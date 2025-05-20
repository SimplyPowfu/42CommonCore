/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glancell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:36:04 by ecarbona          #+#    #+#             */
/*   Updated: 2025/05/20 12:30:58 by glancell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"//cartella builtins

int	env(char **envp)
{
	int		i;

	i = -1;
	while (envp[++i])
		if (strrchr(envp[i], '='))
			ft_putendl_fd(envp[i], 1);
	return (1);
}
