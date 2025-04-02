/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:58:08 by ecarbona          #+#    #+#             */
/*   Updated: 2025/04/02 19:53:52 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minishell.h"

void	take_env(char **envp, t_shell *shell)
{
	int i;

	i = -1;
	while (envp[++i])
		i++;
	shell->envp = malloc(sizeof(char *) * i);
	i = -1;
	while(envp[++i])
		shell->envp[i] = ft_strdup(envp[i]);
}

void	init(char *cmd, char **envp, t_shell *shell)
{
	shell->cmd = cmd;//stringa di output di readline contenente i comandi da parsare
	shell->in_file = NULL;//redirection file input
	shell->out_file = NULL;//redirection file output
	shell->append = 0;//gestione pipe
	shell->heredoc = NULL;//gestione pipe
	shell->path = malloc(PATH_MAX);
	getcwd(shell->path, sizeof(shell->path));//path iniziale da modificare su cd per avere il path nuovo
	take_env(envp, shell);
}
