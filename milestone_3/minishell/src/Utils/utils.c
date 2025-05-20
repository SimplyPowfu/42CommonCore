/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 16:19:57 by ecarbona          #+#    #+#             */
/*   Updated: 2025/05/20 11:16:25 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	check_argv_quote(t_shell *shell, int *i, int *j, int *k)
{
	while (shell->cmd[++(*i)] != 39 && shell->cmd[*i])
	{
		shell->argv[*k][*j] = shell->cmd[*i];
		(*j)++;
	}
	if (shell->cmd[++(*i)] == ' ' || shell->cmd[*i] == '\0')
	{
		pipe_is_char(&shell->argv[*k]);
		redir_is_char(&shell->argv[*k]);
		(*k)++;
		(*j) = 0;
	}
}

static void	count_quotes(char *command, int *i, int *quotes, int *double_quotes)
{
	if (command[*i] == 34)
	{
		(*i)++;
		(*quotes)++;
		while (command[*i] && command[*i] != 34)
			(*i)++;
		if (command[*i])
			(*quotes)++;
	}
	else if (command[*i] == 39)
	{
		(*i)++;
		(*double_quotes)++;
		while (command[*i] && command[*i] != 39)
			(*i)++;
		if (command[*i])
			(*double_quotes)++;
	}
	if ((*i) >= (int)ft_strlen(command))
		(*i) = (ft_strlen(command) - 1);
}

int	close_quote(char *command)
{
	int	i;
	int	quotes;
	int	double_quotes;

	i = -1;
	quotes = 0;
	double_quotes = 0;
	while (command[++i])
		count_quotes(command, &i, &quotes, &double_quotes);
	if (quotes % 2 != 0 || double_quotes % 2 != 0)
		return (0);
	return (1);
}

void	del_extra_space(t_shell *shell)
{
	int		i;
	char	*temp;

	i = -1;
	while (shell->argv[++i])
	{
		if (shell->argv[i][0] == ' '
			&& (shell->argv[i][1] == '>' || shell->argv[i][1] == '<'))
		{
			temp = ft_strdup(shell->argv[i]);
			free(shell->argv[i]);
			shell->argv[i] = ft_strdup(&temp[1]);
			free(temp);
		}
	}
}

void	del_extra_space_pipe(t_command *command)
{
	int		i;
	char	*temp;

	i = -1;
	while (command->args[++i])
	{
		if (command->args[i][0] == ' '
			&& (command->args[i][1] == '>' || command->args[i][1] == '<'))
		{
			temp = ft_strdup(command->args[i]);
			free(command->args[i]);
			command->args[i] = ft_strdup(&temp[1]);
			free(temp);
		}
	}
}
