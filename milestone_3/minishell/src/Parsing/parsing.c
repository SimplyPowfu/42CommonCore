/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:36:21 by glancell          #+#    #+#             */
/*   Updated: 2025/05/20 14:59:53 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include <stdlib.h>

int	command_bultins(char *cmd)
{
	if (!cmd)
		return (0);
	return (!ft_strcmp(cmd, "exit")
		|| !ft_strcmp(cmd, "cd")
		|| !ft_strcmp(cmd, "export")
		|| !ft_strcmp(cmd, "unset")
		|| !ft_strcmp(cmd, "echo")
		|| !ft_strcmp(cmd, "pwd")
		|| !ft_strcmp(cmd, "env"));
}

int	is_builtins(t_shell *shell, t_command *cmd)
{
	if (!cmd->command)
		return (0);
	if (!ft_strcmp(cmd->command, "exit") || !shell->cmd)
		return (ft_exit(shell), 1);
	else if (!ft_strcmp(cmd->command, "echo"))
		echo(shell->argc, cmd->args);
	else if (!ft_strcmp(cmd->command, "pwd"))
		pwd();
	else if (!ft_strcmp(cmd->command, "env"))
		env(shell->envp);
	else if (!ft_strcmp(cmd->command, "cd"))
		cd(shell);
	else if (!ft_strcmp(cmd->command, "export"))
		ft_export(shell);
	else if (!ft_strcmp(cmd->command, "unset"))
		unset(shell);
	else
		return (0);
	return (exit_error(shell, 0), 1);
}

void	shift_arg_pipes(t_command *shell, int i)
{
	if (shell->args[i + 1] == NULL)
	{
		free(shell->args[i]);
		shell->args[i] = NULL;
		return ;
	}
	free(shell->args[i]);
	while (shell->args[i + 1] != NULL)
	{
		shell->args[i] = shell->args[i + 1];
		i++;
	}
	shell->args[i] = NULL;
}

static int	copy_command_args(t_shell *shell, t_command *command, int *arg)
{
	int	i;
	int	arg_count;

	i = 0;
	arg_count = *arg;
	while (shell->argv[arg_count] && !(shell->argv[arg_count][0] == '|'
		&& !shell->argv[arg_count][1]))
		arg_count++;
	command->args = malloc(sizeof(char *) * (arg_count - *arg + 1));
	if (!command->args)
		return (0);
	while (shell->argv[*arg] && !(shell->argv[*arg][0] == '|'
		&& !shell->argv[*arg][1]))
	{
		if (i == 0)
			command->command = ft_strdup(shell->argv[*arg]);
		command->args[i] = ft_strdup(shell->argv[*arg]);
		i++;
		(*arg)++;
	}
	command->args[i] = NULL;
	if (shell->argv[*arg])
		(*arg)++;
	return (1);
}

int	split_struct(t_shell *shell, t_command *command, int *arg)
{
	command->command = NULL;
	command->input_file = NULL;
	command->output_file = NULL;
	command->append = 0;
	command->heredoc = NULL;
	command->doc_count = 0;
	if (!copy_command_args(shell, command, arg))
		return (0);
	count_heredoc_pipe(shell, command);
	if (!parse_redir_pipe(shell, command) || !syntax_pipes(shell, command))
		return (0);
	del_extra_space_pipe(command);
	return (1);
}
