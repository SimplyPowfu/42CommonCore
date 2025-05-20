/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 19:09:43 by glancell          #+#    #+#             */
/*   Updated: 2025/05/20 15:44:17 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	setup_backups(int *stdin_backup, int *stdout_backup)
{
	*stdin_backup = dup(STDIN_FILENO);
	*stdout_backup = dup(STDOUT_FILENO);
	return (1);
}

static int	handle_builtin(t_shell *shell, t_command *cmd,
	int stdin_backup, int stdout_backup)
{
	handle_heredoc(shell, cmd);
	handle_redirections(shell, cmd);
	is_builtins(shell, cmd);
	dup2(stdin_backup, STDIN_FILENO);
	dup2(stdout_backup, STDOUT_FILENO);
	close(stdin_backup);
	close(stdout_backup);
	return (1);
}

static int	handle_nonbuiltin(t_shell *shell, t_command *cmd)
{
	int	exit_status;

	exit_status = execute_command(shell, cmd);
	if (exit_status == 127 && shell->argv[0])
	{
		printf("%s: command not found\n", shell->argv[0]);
		return (exit_error(shell, 127));
	}
	else if (exit_status != 0)
		return (exit_error(shell, exit_status));
	return (1);
}

static int	handle_single_cmd(t_shell *shell, t_command *cmd)
{
	int	stdin_backup;
	int	stdout_backup;

	if (!parse_redir(shell) || !syntax(shell))
		return (exit_error(shell, 2));
	del_extra_space(shell);
	init_command(shell, cmd);
	setup_backups(&stdin_backup, &stdout_backup);
	if (command_bultins(shell->argv[0]))
		return (handle_builtin(shell, cmd, stdin_backup, stdout_backup));
	else
		return (handle_nonbuiltin(shell, cmd));
}

int	pars(t_shell *shell)
{
	t_command	cmd;

	if (shell->pipes_count < 1)
		return (handle_single_cmd(shell, &cmd));
	else
	{
		if (!check_pipes(shell) || !pipes_init_command(shell))
			return (exit_error(shell, 2));
		execute_pipeline(shell);
		signal(SIGINT, signal_manager);
		signal(SIGQUIT, SIG_IGN);
		return (1);
	}
}
