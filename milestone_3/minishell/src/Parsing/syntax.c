/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 12:52:30 by ecarbona          #+#    #+#             */
/*   Updated: 2025/05/17 13:55:15 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"//cartella parsing

static int	check_syntax_heredoc(t_shell *shell)
{
	int	i;

	i = -1;
	while (shell->heredoc[++i])
	{
		if (shell->heredoc[i][0] == '>' || shell->heredoc[i][0] == '<'
				|| shell->heredoc[i][0] == '|')
			return (exit_error(shell, 2), printf("%s `%s'\n",
					SYNTAX, shell->heredoc[i]), 0);
	}
	return (1);
}

static int	check_syntax_heredoc_pipe(t_shell *shell, t_command *command)
{
	int	i;

	i = -1;
	while (command->heredoc[++i])
	{
		if (command->heredoc[i][0] == '>' || command->heredoc[i][0]
				== '<' || command->heredoc[i][0] == '|')
			return (exit_error(shell, 2), printf("%s `%s'\n",
					SYNTAX, command->heredoc[i]), 0);
	}
	return (1);
}

int	syntax_pipes(t_shell *shell, t_command *command)
{
	if (shell->pipes_count < 1 && command->args[0]
		&& command->args[0][0] == '|')
		return (exit_error(shell, 2), printf("%s `%s'\n",
				SYNTAX, command->args[0]), 0);
	if (command->input_file || command->output_file || command->heredoc)
	{
		if (!command->input_file && !command->output_file && !command->heredoc)
			return (exit_error(shell, 2), printf("%s `newline'\n", SYNTAX), 0);
		if (command->input_file && (command->input_file[0] == '>' || command
				->input_file[0] == '<' || command->input_file[0] == '|'))
			return (exit_error(shell, 2), printf("%s `%s'\n",
					SYNTAX, command->input_file), 0);
		if (command->output_file && (command->output_file[0] == '>' || command
				->output_file[0] == '<' || command->output_file[0] == '|'))
			return (exit_error(shell, 2), printf("%s `%s'\n",
					SYNTAX, command->output_file), 0);
		if (command->heredoc)
			if (!check_syntax_heredoc_pipe(shell, command))
				return (0);
	}
	return (1);
}

int	syntax(t_shell *shell)
{
	if (shell->argv[0] && shell->argv[0][0] == '|')
		return (exit_error(shell, 2), printf("%s `%s'\n",
				SYNTAX, shell->argv[0]), 1);
	if (shell->input_file || shell->output_file || shell->heredoc)
	{
		if (!shell->input_file && !shell->output_file && !shell->heredoc)
			return (exit_error(shell, 2), printf("%s `newline'\n", SYNTAX), 0);
		if (shell->input_file && (shell->input_file[0] == '>' || shell
				->input_file[0] == '<' || shell->input_file[0] == '|'))
			return (exit_error(shell, 2), printf("%s `%s'\n",
					SYNTAX, shell->input_file), 0);
		if (shell->output_file && (shell->output_file[0] == '>' || shell
				->output_file[0] == '<' || shell->output_file[0] == '|'))
			return (exit_error(shell, 2), printf("%s `%s'\n",
					SYNTAX, shell->output_file), 0);
		if (shell->heredoc)
			if (!check_syntax_heredoc(shell))
				return (0);
	}
	return (1);
}

int	check_pipes(t_shell *shell)
{
	int	i;

	i = -1;
	while (shell->argv[++i])
	{
		if (shell->argv[i][0] == '|' && !shell->argv[i + 1])
			return (exit_error(shell, 2), printf("%s `|'\n", SYNTAX), 0);
		if (shell->argv[i + 1] && (shell->argv[i][0] == '|' || shell
			->argv[i][0] == '>' || shell->argv[i][0] == '<'))
		{
			if (shell->argv[i + 1][0] == '|' && !shell->argv[i + 1][1])
				return (exit_error(shell, 2), printf("%s `|'\n", SYNTAX), 0);
		}
	}
	return (1);
}
