/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:58:08 by ecarbona          #+#    #+#             */
/*   Updated: 2025/04/05 18:38:18 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"//cartella parsing

static void	malloc_args(t_shell *shell, int *i, int *j)
{
	while(shell->cmd && shell->cmd[(*i)])
	{
		while(shell->cmd[(*i)] == ' ')
			(*i)++;
		while(shell->cmd[(*i)] != ' ' && shell->cmd[(*i)] != '\0')
			(*i)++;
		shell->argc++;
	}
	shell->argv = malloc(sizeof(char *) * (shell->argc + 1));
	(*i) = 0;
	shell->argc = 0;
	while(shell->cmd && shell->cmd[(*i)])
	{
		while(shell->cmd[(*i)] == ' ')
			(*i)++;
		while(shell->cmd[(*i)] != ' ' && shell->cmd[(*i)] != '\0')
		{
			(*i)++;
			(*j)++;
		}
		shell->argv[shell->argc] = malloc((*j) + 1);
		shell->argv[shell->argc][(*j)] = '\0';
		shell->argc++;
		(*j) = 0;
	}
}

static void	init_args(t_shell *shell)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	malloc_args(shell, &i, &j);
	shell->argv[shell->argc] = NULL;
	i = 0;
	shell->argc = 0;
	while(shell->cmd && shell->cmd[i])
	{
		while(shell->cmd[i] == ' ')
			i++;
		while(shell->cmd[i] != ' ' && shell->cmd[i] != '\0')
		{
			shell->argv[shell->argc][j] = shell->cmd[i];
			i++;
			j++;
		}
		shell->argc++;
		j = 0;
	}
}

static void	take_env(char **envp, t_shell *shell)
{
	int	i;

	i = -1;
	while (envp[++i])
		i++;
	shell->envp = malloc(sizeof(char *) * (i + 1));
	i = -1;
	while (envp[++i])
		shell->envp[i] = ft_strdup(envp[i]);
	shell->envp[i] = NULL;
}

void	init(char *cmd, char **envp, t_shell *shell)
{
	shell->cmd = cmd;//stringa di output di readline contenente i comandi da parsare
	shell->argc = 0;
	shell->argv = NULL;
	shell->in_file = NULL;//redirection file input
	shell->out_file = NULL;//redirection file output
	shell->append = 0;//gestione pipe
	shell->heredoc = NULL;//gestione pipe
	shell->path = malloc(PATH_MAX);
	getcwd(shell->path, sizeof(shell->path));//path iniziale da modificare su cd per avere il path nuovo
	take_env(envp, shell);//copia dell'env
	init_args(shell);//predo la stringa command e creo un argc/argv per ogni comando; argv[0] comando, argv[1]flag o contenuto
}

void	free_all(t_shell *shell)
{
	int	i;

	i = -1;
	if (shell->envp)
	{
		while (shell->envp[++i])
			free(shell->envp[i]);
		free(shell->envp);
	}
	if (shell->path)
		free(shell->path);
	if (shell->argv)
	{
		i = -1;
		while (shell->argv[++i])
			free(shell->argv[i]);
		free(shell->argv);
	}
}
