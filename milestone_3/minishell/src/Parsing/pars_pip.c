/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_pip.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glancell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 19:47:18 by glancell          #+#    #+#             */
/*   Updated: 2025/05/18 23:24:33 by glancell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	pipes_init_command(t_shell *shell)
{
	int	i;
	int	arg;

	shell->command = ft_calloc(shell->pipes_count + 1,
			sizeof(t_command *));
	i = -1;
	arg = 0;
	while (++i <= shell->pipes_count)
	{
		shell->command[i] = malloc(sizeof(t_command));
		if (!split_struct(shell, shell->command[i], &arg))
			return (0);
	}
	return (1);
}
