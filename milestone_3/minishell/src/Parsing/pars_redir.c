/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 19:24:29 by ecarbona          #+#    #+#             */
/*   Updated: 2025/05/17 20:15:19 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	check_outfile_pipe(t_shell *shell, t_command *command, int *i)
{
	if (command->args[(*i) + 1])
	{
		if (command->args[*i][0] == '>' && command->args[*i][1]
			&& command->args[*i][1] == '>')
			command->append = 1;
		free(command->output_file);
		command->output_file = ft_strdup(command->args[(*i) + 1]);
		shift_arg_pipes(command, (*i) + 1);
		shift_arg_pipes(command, (*i));
		(*i) = -1;
	}
	else
		return (exit_error(shell, 2), printf("%s `newline'\n",
				SYNTAX), 0);
	return (1);
}

int	check_input_pipe(t_shell *shell, t_command *command, int *i)
{
	if (command->args[(*i) + 1])
	{
		free(command->input_file);
		command->input_file = ft_strdup(command->args[(*i) + 1]);
		shift_arg_pipes(command, (*i) + 1);
		shift_arg_pipes(command, (*i));
		(*i) = -1;
	}
	else
		return (exit_error(shell, 2), printf("%s `newline'\n",
				SYNTAX), 0);
	return (1);
}

int	check_heredoc_pipe(t_shell *shell, t_command *command, int *i, int *k)
{
	if (command->args[*i][1] == '<' && command->args[(*i) + 1])
	{
		command->heredoc[(*k)++] = ft_strdup(command->args[(*i) + 1]);
		shift_arg_pipes(command, (*i) + 1);
		shift_arg_pipes(command, (*i));
		(*i) = -1;
	}
	else if (command->args[*i][1] == '>' && command->args[(*i) + 1])
	{
		free(command->input_file);
		free(command->output_file);
		command->input_file = ft_strdup(command->args[(*i) + 1]);
		command->output_file = ft_strdup(command->args[(*i) + 1]);
		shift_arg_pipes(command, (*i) + 1);
		shift_arg_pipes(command, (*i));
		(*i) = -1;
	}
	else
		return (exit_error(shell, 2), printf("%s `newline'\n",
				SYNTAX), 0);
	return (1);
}

int	take_argv_pipe(t_shell *shell, t_command *command, int *i, int *k)
{
	if ((command->args[*i][0] == '>' && !command->args[*i][1])
		|| (command->args[*i][0] == '>' && command->args[*i][1]
		&& command->args[*i][1] == '>' && !command->args[*i][2]))
	{
		if (!check_outfile_pipe(shell, command, i))
			return (0);
	}
	else if (command->args[*i][0] == '<' && !command->args[*i][1])
	{
		if (check_input_pipe(shell, command, i))
			return (0);
	}
	else if (command->args[*i][0] == '<' && command->args[*i][1]
			&& command->args[*i][1] == '<')
	{
		if (!check_heredoc_pipe(shell, command, i, k))
			return (0);
	}
	return (1);
}

int	parse_redir_pipe(t_shell *shell, t_command *command)
{
	int	i;
	int	k;

	i = -1;
	k = 0;
	while (command->args[++i])
	{
		if (ft_strlen(command->args[i]) == 1
			|| ft_strlen(command->args[i]) == 2)
			if (!take_argv_pipe(shell, command, &i, &k))
				return (0);
		if (!check_syntax_error_pipes(shell, command))
			return (0);
	}
	return (1);
}
