/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hadler_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glancell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 16:05:00 by glancell          #+#    #+#             */
/*   Updated: 2025/05/20 14:55:50 by glancell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	try_direct_execution(t_command *cmd, char **envp)
{
	if (access(cmd->command, X_OK) == 0)
	{
		execve(cmd->command, cmd->args, envp);
		perror(cmd->command);
		exit(126);
	}
	return (0);
}

static int	try_path_execution(char **paths, t_command *cmd, char **envp)
{
	char	*dir;
	char	*full_path;
	int		i;

	i = -1;
	while (paths[++i])
	{
		dir = ft_strjoin(paths[i], "/");
		full_path = ft_strjoin(dir, cmd->command);
		free(dir);
		if (access(full_path, X_OK) == 0)
		{
			execve(full_path, cmd->args, envp);
			free(full_path);
			break ;
		}
		free(full_path);
	}
	return (127);
}

static void	execute_child_process(t_shell *shell, t_command *cmd, char **paths)
{
	try_direct_execution(cmd, shell->envp);
	if (paths == NULL)
	{
		ft_putstr_fd("minishell: PATH not set\n", 2);
		free_all(shell, 0);
		if (paths != NULL)
			ft_free_split(paths);
		exit(127);
	}
	try_path_execution(paths, cmd, shell->envp);
	close(3);
	close(4);
	free_all(shell, 0);
	if (paths != NULL)
		ft_free_split(paths);
	exit(127);
}

static int	handle_child_process(t_shell *shell, t_command *cmd, char **paths)
{
	set_signals_noninteractive();
	if (g_signal == SIGINT || g_signal == SIGPIPE)
	{
		if (paths)
			ft_free_split(paths);
		free_all(shell, 0);
		exit(130);
	}
	execute_child_process(shell, cmd, paths);
	return (1);
}

int	handle_fork_and_execution(t_shell *shell, t_command *cmd, char **paths)
{
	pid_t	pid;
	int		ret;

	ret = 127;
	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		if (paths)
			ft_free_split(paths);
		return (1);
	}
	if (pid == 0)
	{
		ret = handle_child_process(shell, cmd, paths);
		free_all(shell, 0);
		exit_error(shell, ret);
	}
	ret = handle_parent_process(pid, paths);
	close(3);
	close(4);
	exit_error(shell, ret);
	return (ret);
}
