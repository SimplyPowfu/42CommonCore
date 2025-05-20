/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glancell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 12:18:47 by glancell          #+#    #+#             */
/*   Updated: 2025/05/20 15:00:03 by glancell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	open_output_file(t_command *cmd)
{
	int	flags;

	flags = O_WRONLY | O_CREAT;
	if (cmd->append)
		flags = flags | O_APPEND;
	else
		flags = flags | O_TRUNC;
	return (open(cmd->output_file, flags, 0644));
}

static int	handle_input_redirection(t_command *cmd)
{
	int	fd;

	fd = open(cmd->input_file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("minishell: ", STDERR_FILENO);
		ft_putstr_fd(cmd->input_file, STDERR_FILENO);
		ft_putstr_fd(": No such file or directory\n", STDERR_FILENO);
		close(3);
		close(4);
		return (0);
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
	return (1);
}

static int	handle_output_redirection(t_command *cmd)
{
	int	fd;

	fd = open_output_file(cmd);
	if (fd == -1)
	{
		perror("minishell");
		return (0);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
	return (1);
}

void	handle_redirections(t_shell *shell, t_command *cmd)
{
	int	success;

	success = 1;
	if (cmd->input_file)
		success = handle_input_redirection(cmd);
	if (cmd->output_file && success)
		success = handle_output_redirection(cmd);
	if (!success)
	{
		free_all(shell, 0);
		exit(1);
	}
}
