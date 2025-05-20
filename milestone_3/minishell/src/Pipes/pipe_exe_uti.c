/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_exe_uti.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 11:45:11 by glancell          #+#    #+#             */
/*   Updated: 2025/05/20 15:38:08 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	cleanup_pipeline(t_shell *shell)
{
	int	i;

	i = 0;
	while (i <= shell->pipes_count)
	{
		if (shell->command[i] && shell->command[i]->input_file)
		{
			unlink(shell->command[i]->input_file);
			free(shell->command[i]->input_file);
			shell->command[i]->input_file = NULL;
		}
		i++;
	}
}

void	close_pipes(int *pipes, int pipes_count)
{
	int	i;

	i = 0;
	while (i < pipes_count * 2)
	{
		close(pipes[i]);
		i++;
	}
}

void	handle_pipe_creation(t_shell *shell, int *pipes)
{
	int	i;

	i = 0;
	while (i < shell->pipes_count)
	{
		if (pipe(pipes + i * 2) == -1)
		{
			perror("minishell: pipe creation");
			close(3);
			close(4);
			cleanup_pipeline(shell);
			free_all(shell, 0);
			exit_error(shell, 1);
		}
		i++;
	}
}

char	*create_tempfile(int cmd_index)
{
	char	*tempfile;
	char	*index_str;
	int		fd;

	index_str = ft_itoa(cmd_index);
	if (!index_str)
		return (NULL);
	tempfile = ft_strjoin("/tmp/minishell_heredoc_temp_", index_str);
	free(index_str);
	if (!tempfile)
		return (NULL);
	fd = open(tempfile, O_RDWR | O_CREAT | O_TRUNC, 0600);
	if (fd == -1)
	{
		free(tempfile);
		perror("minishell: create_tempfile");
		return (NULL);
	}
	close(fd);
	return (tempfile);
}

void	handle_heredoc_parent(pid_t pid, t_heredoc_ctx *ctx)
{
	int	status;

	status = 0;
	waitpid(pid, &status, 0);
	if (WIFEXITED(status) && WEXITSTATUS(status) == EXIT_SUCCESS)
		ctx->cmd->input_file = ctx->tempfile;
	else
	{
		free(ctx->tempfile);
		free(ctx->pipes);
		exit_error(ctx->shell, 1);
	}
}
