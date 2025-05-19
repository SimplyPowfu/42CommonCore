/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:36:21 by glancell          #+#    #+#             */
/*   Updated: 2025/04/05 18:44:52 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"//cartella parsing

int	is_builtins(t_shell *shell)
{
	
	if (!ft_strcmp(shell->argv[0], "exit"))
		shell->cmd = NULL;
	else if (!ft_strcmp(shell->argv[0], "echo"))
		echo(shell->argc, shell->argv);
	else
	 	return (0);
	return (1);
}

int	pars(t_shell *shell)
{
	if (is_builtins(shell))
		return (1);
	// if (is_builtins(shell))
	// 	return (2);
	return (0);
}
