/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline_exe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 20:08:22 by glancell          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/05/20 15:27:35 by glancell         ###   ########.fr       */
=======
/*   Updated: 2025/05/20 15:43:58 by ecarbona         ###   ########.fr       */
>>>>>>> refs/remotes/origin/master
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	execute_child_process(t_shell *shell, int *pipes, int i)
{
	int	status;

	status = 0;
	if (i > 0)
		dup2(pipes[(i - 1) * 2], STDIN_FILENO);
	if (i < shell->pipes_count)
		dup2(pipes[i * 2 + 1], STDOUT_FILENO);
	close_pipes(pipes, shell->pipes_count);
	free(pipes);
	handle_redirections(shell, shell->command[i]);
	if (g_signal == SIGINT || g_signal == SIGQUIT)
	{
		free_all(shell, 0);
		exit(130);
	}
	if (command_bultins(shell->command[i]->command))
	{
		status = is_builtins(shell, shell->command[i]);
		free_all(shell, 0);
		exit(status);
	}
	execute_path_command(shell, shell->command[i]);
	free_all(shell, 0);
	exit(127);
}

static void	handle_child(t_shell *shell, int *pipes, int i, pid_t *pids)
{
	free(pids);
	set_signals_noninteractive_child();
	if (g_signal == SIGINT || g_signal == SIGQUIT)
	{
		free_all(shell, 0);
		free(pipes);
		exit(130);
	}
	execute_child_process(shell, pipes, i);
	free(pipes);
}

static void	execute_commands(t_shell *shell, int *pipes, pid_t *pids)
{
	int	i;

	i = -1;
	while (++i <= shell->pipes_count && shell->command[i])
	{
		pids[i] = fork();
		if (pids[i] == 0)
			handle_child(shell, pipes, i, pids);
		else if (pids[i] < 0)
		{
			perror("minishell: fork");
			close_pipes(pipes, shell->pipes_count);
			free(pipes);
			free(pids);
			free_all(shell, 0);
			exit_error(shell, 1);
		}
	}
}

static void	wait_for_processes(t_shell *shell, pid_t *pids, int num_commands)
{
	int	i;
	int	status;

	i = 0;
	status = 0;
	while (i <= num_commands)
	{
		waitpid(pids[i], &status, 0);
		if (WIFEXITED(status))
			exit_error(shell, WEXITSTATUS(status));
		else if (WIFSIGNALED(status))
		{
			if (WTERMSIG(status) == SIGPIPE)
				g_signal = SIGPIPE;
			exit_error(shell, 128 + WTERMSIG(status));
		}
		i++;
	}
}

void	execute_pipeline(t_shell *shell)
{
	int		*pipes;
	pid_t	*pids;
	int		i;

	pipes = malloc(sizeof(int) * shell->pipes_count * 2);
	pids = malloc(sizeof(pid_t) * (shell->pipes_count + 1));
	if (!pipes || !pids)
	{
		free(pipes);
		free(pids);
		free_all(shell, 0);
		exit_error(shell, 1);
	}
	ft_memset(pids, 0, sizeof(pid_t) * (shell->pipes_count + 1));
	i = -1;
	while (++i < shell->doc_count && shell->command[i])
		handle_command_heredoc(pipes, pids, shell, i);
	handle_pipe_creation(shell, pipes);
	set_pipeline_signals();
	execute_commands(shell, pipes, pids);
	close_pipes(pipes, shell->pipes_count);
	wait_for_processes(shell, pids, shell->pipes_count);
	free(pipes);
	free(pids);
	cleanup_pipeline(shell);
}
