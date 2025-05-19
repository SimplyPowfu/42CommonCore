/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:36:04 by ecarbona          #+#    #+#             */
/*   Updated: 2025/04/07 16:26:03 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"//cartella builtins

int	env(char **envp)
{
	int		i;

	i = -1;
	while (envp[++i])
		ft_putendl_fd(envp[i], 1);
	return (1);
}
