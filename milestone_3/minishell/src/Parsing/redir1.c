/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 14:14:04 by ecarbona          #+#    #+#             */
/*   Updated: 2025/05/17 20:10:50 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	take_redirection(t_shell *shell, int *i, int *k, int *egg)
{
	if ((shell->argv[*i][0] == '>' && !shell->argv[*i][1]) || (shell
		->argv[*i][0] == '>' && shell->argv[*i][1] && shell->argv[*i][1]
		== '>' && !shell->argv[*i][2]))
	{
		if (!check_output_file(shell, i, egg))
			return (0);
	}
	else if (shell->argv[*i][0] == '<' && !shell->argv[*i][1])
	{
		if (!check_input_file(shell, i, egg))
			return (0);
	}
	else if (shell->argv[*i][0] == '<' && shell->argv[*i][1]
		&& !shell->argv[*i][2])
	{
		if (!check_heredoc(shell, i, k, egg))
			return (0);
	}
	return (1);
}

int	check_output_file(t_shell *shell, int *i, int *egg)
{
	if (shell->argv[(*i) + 1])
	{
		if (shell->argv[*i][0] == '>' && shell->argv[*i][1]
			&& shell->argv[*i][1] == '>')
			shell->append = 1;
		free(shell->output_file);
		shell->output_file = ft_strdup(shell->argv[(*i) + 1]);
		shift_arg(shell, (*i) + 1, egg);
		shift_arg(shell, (*i), egg);
		(*i) = -1;
	}
	else
		return (exit_error(shell, 2), printf("%s `newline'\n",
				SYNTAX), 0);
	return (1);
}

int	check_input_file(t_shell *shell, int *i, int *egg)
{
	if (shell->argv[(*i) + 1])
	{
		free(shell->input_file);
		shell->input_file = ft_strdup(shell->argv[(*i) + 1]);
		shift_arg(shell, (*i) + 1, egg);
		shift_arg(shell, (*i), egg);
		(*i) = -1;
	}
	else
		return (exit_error(shell, 2), printf("%s `newline'\n",
				SYNTAX), 0);
	return (1);
}

int	check_heredoc(t_shell *shell, int *i, int *k, int *egg)
{
	if (shell->argv[*i][1] == '<' && shell->argv[(*i) + 1])
	{
		shell->heredoc[(*k)++] = ft_strdup(shell->argv[(*i) + 1]);
		shift_arg(shell, (*i) + 1, egg);
		shift_arg(shell, (*i), egg);
		(*i) = -1;
	}
	else if (shell->argv[*i][1] == '>' && shell->argv[(*i) + 1])
	{
		free(shell->input_file);
		free(shell->output_file);
		shell->input_file = ft_strdup(shell->argv[(*i) + 1]);
		shell->output_file = ft_strdup(shell->argv[(*i) + 1]);
		shift_arg(shell, (*i) + 1, egg);
		shift_arg(shell, (*i), egg);
		(*i) = -1;
	}
	else
		return (exit_error(shell, 2), printf("%s `newline'\n",
				SYNTAX), 0);
	return (1);
}
