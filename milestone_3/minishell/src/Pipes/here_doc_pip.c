/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_pip.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glancell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 12:20:24 by glancell          #+#    #+#             */
/*   Updated: 2025/05/19 16:10:33 by glancell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	handle_heredoc_interrupt(t_heredoc_ctx *ctx, char *line)
{
	signal(SIGQUIT, SIG_IGN);
	if (!line || g_signal == SIGINT || g_signal == SIGQUIT)
	{
		print_heredoc_warning(ctx->cmd);
		free(line);
		free(ctx->pids);
		free(ctx->pipes);
		free_all(ctx->shell, 0);
		free(ctx->tempfile);
		exit(0);
	}
	return (0);
}

static int	process_heredoc_input(t_heredoc_ctx *ctx)
{
	char	*line;
	char	*expanded;

	signal(SIGINT, sig_here);
	signal(SIGQUIT, SIG_IGN);
	while (1)
	{
		line = readline("> ");
		if (handle_heredoc_interrupt(ctx, line))
			continue ;
		if (ft_strcmp(line,
				ctx->cmd->heredoc[ctx->cmd->doc_count - 1]) == 0)
			return (free(line), free_all(ctx->shell, 0), 1);
		expanded = in_env(ctx->shell, line, ctx->shell->envp);
		if (expanded)
		{
			write(ctx->fd, expanded, ft_strlen(expanded));
			free(expanded);
		}
		else
			write(ctx->fd, line, ft_strlen(line));
		write(ctx->fd, "\n", 1);
		free(line);
	}
}

static void	write_heredoc_to_tempfile(t_heredoc_ctx *ctx)
{
	int	success;

	success = 0;
	signal(SIGQUIT, SIG_IGN);
	ctx->fd = open(ctx->tempfile, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (ctx->fd == -1)
	{
		perror("minishell: heredoc");
		free(ctx->tempfile);
		exit(EXIT_FAILURE);
	}
	signal(SIGINT, sig_here);
	signal(SIGQUIT, SIG_IGN);
	success = process_heredoc_input(ctx);
	close(ctx->fd);
	if (!success)
	{
		unlink(ctx->tempfile);
		free(ctx->tempfile);
		free_all(ctx->shell, 0);
		exit(EXIT_FAILURE);
	}
}

static void	handle_heredoc_child(t_heredoc_ctx *ctx)
{
	signal(SIGQUIT, SIG_IGN);
	write_heredoc_to_tempfile(ctx);
	free(ctx->tempfile);
	free(ctx->pipes);
	free(ctx->pids);
	exit(EXIT_SUCCESS);
}

void	handle_command_heredoc(pid_t *pids, int *pipes,
	t_shell *shell, int cmd_index)
{
	t_command		*cmd;
	t_heredoc_ctx	ctx;
	pid_t			pid;

	signal(SIGQUIT, SIG_IGN);
	cmd = shell->command[cmd_index];
	if (!cmd->heredoc || cmd->doc_count == 0)
		return ;
	ctx.tempfile = create_tempfile(cmd_index);
	if (!ctx.tempfile)
		return ;
	ctx.pids = pids;
	ctx.pipes = pipes;
	ctx.shell = shell;
	ctx.cmd = cmd;
	pid = fork();
	if (pid == 0)
		handle_heredoc_child(&ctx);
	else
		handle_heredoc_parent(pid, &ctx);
}
