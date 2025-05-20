/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:42:45 by glancell          #+#    #+#             */
/*   Updated: 2025/05/20 15:36:19 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	process_line(t_shell *shell, char *line, int pipe_fd)
{
	char	*expanded;

	expanded = NULL;
	if (ft_strchr(line, '$'))
		expanded = in_env(shell, line, shell->envp);
	if (expanded)
	{
		write(pipe_fd, expanded, ft_strlen(expanded));
		write(pipe_fd, "\n", 1);
		free(expanded);
	}
	else
	{
		write(pipe_fd, line, ft_strlen(line));
		write(pipe_fd, "\n", 1);
	}
}

void	print_heredoc_warning(t_command *cmd)
{
	ft_putstr_fd("minishell: warning: ", STDERR_FILENO);
	ft_putstr_fd("here-document delimited by end-of-file ", STDERR_FILENO);
	ft_putstr_fd("(wanted `", STDERR_FILENO);
	ft_putstr_fd(cmd->heredoc[cmd->doc_count - 1], STDERR_FILENO);
	ft_putstr_fd("')\n", STDERR_FILENO);
	close(3);
	close(4);
}

static int	process_single_heredoc(t_shell *shell,
	t_command *cmd, int pipe_fd, int i)
{
	char	*line;

	line = readline("> ");
	if (!line)
		return (print_heredoc_warning(cmd), 0);
	if (g_signal == SIGINT)
		return (free(line), 0);
	while (line && ft_strcmp(line, cmd->heredoc[i]) && g_signal != SIGINT)
	{
		if (i == cmd->doc_count - 1)
			process_line(shell, line, pipe_fd);
		free(line);
		line = readline("> ");
		if (!line)
			return (print_heredoc_warning(cmd), 0);
		if (g_signal == SIGINT)
			return (free(line), 0);
	}
	free(line);
	if (g_signal == SIGINT)
		return (0);
	return (1);
}

static int	process_heredoc_content(t_shell *shell, t_command *cmd, int pipe_fd)
{
	int	i;

	i = 0;
	signal(SIGINT, sig_here);
	signal(SIGQUIT, SIG_IGN);
	while (i < cmd->doc_count && g_signal != SIGINT)
	{
		if (!process_single_heredoc(shell, cmd, pipe_fd, i))
			return (0);
		i++;
	}
	return (1);
}

void	handle_heredoc(t_shell *shell, t_command *cmd)
{
	int	fd[2];

	if (!cmd->heredoc || cmd->doc_count == 0)
		return ;
	if (pipe(fd) == -1)
	{
		perror("minishell");
		exit(EXIT_FAILURE);
	}
	if (!process_heredoc_content(shell, cmd, fd[1]))
	{
		close(fd[1]);
		close(fd[0]);
		free_all(shell, 0);
		exit(0);
	}
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
}
