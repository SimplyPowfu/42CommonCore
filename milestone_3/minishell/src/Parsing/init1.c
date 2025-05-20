/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 18:42:45 by ecarbona          #+#    #+#             */
/*   Updated: 2025/05/17 19:14:05 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	take_argc(t_shell *shell, int *i)
{
	while (shell->cmd[*i] == ' ')
		(*i)++;
	if (shell->cmd[*i] == 39)
	{
		while (shell->cmd[++(*i)] != 39 && shell->cmd[*i])
			;
		if (shell->cmd[++(*i)] == ' ' || shell->cmd[*i] == '\0')
			shell->argc++;
	}
	else if (shell->cmd[*i] == 34)
	{
		while (shell->cmd[++(*i)] != 34 && shell->cmd[*i])
			;
		if (shell->cmd[++(*i)] == ' ' || shell->cmd[*i] == '\0')
			shell->argc++;
	}
	else if (shell->cmd[*i])
	{
		while (shell->cmd[++(*i)] != ' ' && shell->cmd[*i] != 39
			&& shell->cmd[*i] != 34 && shell->cmd[*i])
			;
		if (shell->cmd[*i] == ' ' || shell->cmd[*i] == '\0')
			shell->argc++;
	}
}

void	take_argv_quotes(t_shell *shell, int quotes, int *i, int *j)
{
	while (shell->cmd[++(*i)] != quotes && shell->cmd[*i])
		(*j)++;
	if (shell->cmd[++(*i)] == ' ' || shell->cmd[*i] == '\0')
	{
		shell->argv[shell->argc] = malloc((*j) + 1);
		shell->argv[shell->argc][*j] = '\0';
		shell->argc++;
		(*j) = 0;
	}
}

void	take_argv(t_shell *shell, int *i, int *j)
{
	while (shell->cmd[*i] != ' ' && shell->cmd[*i] != 39
		&& shell->cmd[*i] != 34 && shell->cmd[*i])
	{
		(*i)++;
		(*j)++;
	}
	if (shell->cmd[*i] == ' ' || shell->cmd[*i] == '\0')
	{
		shell->argv[shell->argc] = malloc((*j) + 1);
		shell->argv[shell->argc][*j] = '\0';
		shell->argc++;
		(*j) = 0;
	}
}

void	check_argv_quotes(t_shell *shell, int *i, int *j, int *k)
{
	while (shell->cmd[++(*i)] != 34 && shell->cmd[*i])
	{
		shell->argv[*k][*j] = shell->cmd[*i];
		(*j)++;
	}
	if (shell->cmd[++(*i)] == ' ' || shell->cmd[*i] == '\0')
	{
		pipe_is_char(&shell->argv[*k]);
		redir_is_char(&shell->argv[*k]);
		var_in_env(shell, &shell->argv[*k], k);
		(*k)++;
		(*j) = 0;
	}
}

void	check_argv(t_shell *shell, int *i, int *j, int *k)
{
	while (shell->cmd[*i] != ' ' && shell->cmd[*i] != 39 && shell->cmd[*i]
		!= 34 && shell->cmd[*i])
	{
		shell->argv[*k][*j] = shell->cmd[*i];
		(*i)++;
		(*j)++;
	}
	if (shell->cmd[*i] == ' ' || shell->cmd[*i] == '\0')
	{
		var_in_env(shell, &shell->argv[*k], k);
		(*k)++;
		(*j) = 0;
	}
}
