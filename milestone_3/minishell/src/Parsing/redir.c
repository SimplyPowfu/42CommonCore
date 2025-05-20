/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:14:02 by ecarbona          #+#    #+#             */
/*   Updated: 2025/05/17 14:34:14 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	check_syntax_error_pipes(t_shell *shell, t_command *command)
{
	int	i;

	i = -1;
	while (command->args[++i])
	{
		if (command->args[i][0] == '>' || command->args[i][0] == '<')
			if (command->args[i][1] && (command->args[i][1] == '>'
				|| command->args[i][1] == '<'))
				if (command->args[i][2] && (command->args[i][2] == '>'
					|| command->args[i][2] == '<'))
					return (exit_error(shell, 2), printf("%s `%s'\n",
							SYNTAX, &command->args[i][2]), 0);
	}
	return (1);
}

int	check_syntax_error(t_shell *shell)
{
	int	i;

	i = -1;
	while (shell->argv[++i])
	{
		if (shell->argv[i][0] == '>' || shell->argv[i][0] == '<')
			if (shell->argv[i][1] && (shell->argv[i][1] == '>'
				|| shell->argv[i][1] == '<'))
				if (shell->argv[i][2] && (shell->argv[i][2] == '>'
					|| shell->argv[i][2] == '<'))
					return (exit_error(shell, 2), printf("%s `%s'\n",
							SYNTAX, &shell->argv[i][2]), 0);
	}
	return (1);
}

int	parse_redir(t_shell *shell)
{
	int	i;
	int	k;
	int	egg;

	k = 0;
	i = -1;
	egg = 777;
	while (shell->argv[++i])
	{
		if (ft_strlen(shell->argv[i]) == 1 || ft_strlen(shell->argv[i]) == 2)
			if (!take_redirection(shell, &i, &k, &egg))
				return (0);
		if (!check_syntax_error(shell))
			return (0);
	}
	return (1);
}

static void	add_space_result(char *command, char *result, int *i, int *j)
{
	if (command[*i])
	{
		if (command[*i] && ft_isalpha(command[*i]) == 1 && command[(*i) + 1]
			&& (command[(*i) + 1] == '<' || command[(*i) + 1] == '>'
				|| command[(*i) + 1] == '|'))
		{
			result[(*j)++] = command[(*i)++];
			result[(*j)++] = ' ';
		}
		if (command[*i] && (command[*i] == '<' || command[*i] == '>'
				|| command[*i] == '|'))
		{
			result[(*j)++] = command[*i];
			if (command[(*i) + 1] != '<' && command[(*i) + 1] != '>'
				&& command[(*i) + 1] != ' ')
				result[(*j)++] = ' ';
		}
		else
			result[(*j)++] = command[*i];
		(*i)++;
	}
}

char	*space_redir(char *command)
{
	int		i;
	int		j;
	char	*result;

	result = malloc(ft_strlen(command) + add_space_malloc(command) + 1);
	i = 0;
	j = 0;
	while (command[i])
	{
		if (command[i] && command[i] == 34)
		{
			result[j++] = command[i++];
			while (command[i] && command[i] != 34)
				result[j++] = command[i++];
		}
		else if (command[i] && command[i] == 39)
		{
			result[j++] = command[i++];
			while (command[i] && command[i] != 39)
				result[j++] = command[i++];
		}
		add_space_result(command, result, &i, &j);
	}
	result[j] = '\0';
	return (result);
}
