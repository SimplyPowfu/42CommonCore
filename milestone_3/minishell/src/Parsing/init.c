/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:58:08 by ecarbona          #+#    #+#             */
/*   Updated: 2025/05/17 19:20:26 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include <stdio.h>
#include <stdlib.h>

static void	malloc_args(t_shell *shell)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (shell->cmd && shell->cmd[i])
		take_argc(shell, &i);
	shell->argv = malloc(sizeof(char *) * (shell->argc + 1));
	i = 0;
	shell->argc = 0;
	while (shell->cmd && shell->cmd[i])
	{
		while (shell->cmd[i] == ' ')
			i++;
		if (shell->cmd[i] == 39)
			take_argv_quotes(shell, 39, &i, &j);
		else if (shell->cmd[i] == 34)
			take_argv_quotes(shell, 34, &i, &j);
		else if (shell->cmd[i])
			take_argv(shell, &i, &j);
	}
}

static void	init_args(t_shell *shell)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	malloc_args(shell);
	shell->argv[shell->argc] = NULL;
	i = 0;
	j = 0;
	k = 0;
	while (shell->cmd && shell->cmd[i])
	{
		while (shell->cmd[i] == ' ')
			i++;
		if (!shell->cmd[i])
			return ;
		if (shell->cmd[i] == 39)
			check_argv_quote(shell, &i, &j, &k);
		else if (shell->cmd[i] == 34)
			check_argv_quotes(shell, &i, &j, &k);
		else if (shell->cmd[i])
			check_argv(shell, &i, &j, &k);
	}
}

void	init_command(t_shell *shell, t_command *cmd)
{
	cmd->command = shell->argv[0];
	cmd->args = shell->argv;
	cmd->input_file = shell->input_file;
	cmd->output_file = shell->output_file;
	cmd->append = shell->append;
	cmd->heredoc = shell->heredoc;
	cmd->doc_count = shell->doc_count;
}

void	init_shell(t_shell *shell)
{
	shell->cmd = NULL;
	shell->argc = 0;
	shell->argv = NULL;
	shell->path = NULL;
	shell->input_file = NULL;
	shell->output_file = NULL;
	shell->heredoc = NULL;
	shell->doc_count = 0;
	shell->command = NULL;
	shell->append = 0;
}

void	init(char *cmd, t_shell *shell)
{
	char	pwd[PATH_MAX];

	init_shell(shell);
	if (cmd)
		shell->cmd = space_redir(cmd);
	else
		shell->cmd = cmd;
	shell->pipes_count = count_char(shell, '|');
	getcwd(pwd, sizeof(pwd));
	shell->path = ft_strdup(pwd);
	init_args(shell);
	count_heredoc(shell);
}
