/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glancell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:56:03 by tolanini          #+#    #+#             */
/*   Updated: 2025/05/10 21:51:05 by glancell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

//se non funziona shift_arg togli i commenti e prova con quel codice
static void	remove_env_var(t_shell *shell, const char *key)
{
	int		i;
	int		j;
	size_t	key_len;

	i = 0;
	key_len = ft_strlen(key);
	while (shell->envp[i])
	{
		if (ft_strncmp(shell->envp[i], key, key_len) == 0
			&& shell->envp[i][key_len] == '=')
		{
			free(shell->envp[i]);
			j = i;
			while (shell->envp[j])
			{
				shell->envp[j] = shell->envp[j + 1];
				j++;
			}
			return ;
		}
		i++;
	}
}

int	unset(t_shell *shell)
{
	int	i;	

	i = 1;
	if (shell->argc < 2)
		return (0);
	while (i < shell->argc)
	{
		remove_env_var(shell, shell->argv[i]);
		i++;
	}
	return (0);
}
