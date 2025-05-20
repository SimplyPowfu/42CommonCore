/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glancell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:45:31 by ecarbona          #+#    #+#             */
/*   Updated: 2025/05/18 22:15:33 by glancell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"//cartella parsing

void	free_heredoc(t_shell *shell)
{
	int	i;

	if (shell->heredoc)
	{
		i = -1;
		while (shell->heredoc[++i])
			free(shell->heredoc[i]);
		free(shell->heredoc);
	}
}

void	free_env(t_shell *shell, int finish)
{
	int	i;

	i = -1;
	if (shell->envp && !finish)
	{
		while (shell->envp[++i])
			free(shell->envp[i]);
		free(shell->envp);
	}
}

void	free_command_args(t_shell *shell, int i)
{
	int	j;

	j = -1;
	if (shell->command[i]->command)
		free(shell->command[i]->command);
	if (shell->command[i]->input_file)
		free(shell->command[i]->input_file);
	if (shell->command[i]->output_file)
		free(shell->command[i]->output_file);
	if (shell->command[i]->heredoc)
	{
		while (shell->command[i]->heredoc[++j])
			free(shell->command[i]->heredoc[j]);
		free(shell->command[i]->heredoc);
	}
	free(shell->command[i]);
}

void	free_command(t_shell *shell)
{
	int	i;
	int	j;

	if (shell->command)
	{
		i = -1;
		while (++i <= shell->pipes_count)
		{
			if (shell->command[i])
			{
				j = 0;
				if (shell->command[i]->args)
				{
					while (shell->command[i]->args[j])
					{
						free(shell->command[i]->args[j]);
						j++;
					}
					free(shell->command[i]->args);
				}
				free_command_args(shell, i);
			}
		}
		free(shell->command);
	}
}

void	free_all(t_shell *shell, int finish)
{
	int	i;

	i = -1;
	if (shell->cmd)
		free(shell->cmd);
	if (shell->path)
		free(shell->path);
	free_env(shell, finish);
	if (shell->argv)
	{
		i = -1;
		while (shell->argv[++i])
			free(shell->argv[i]);
		free(shell->argv);
	}
	if (shell->input_file)
		free(shell->input_file);
	if (shell->output_file)
		free(shell->output_file);
	free_heredoc(shell);
	free_command(shell);
}
