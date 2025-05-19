/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:25:24 by ecarbona          #+#    #+#             */
/*   Updated: 2025/04/07 16:25:56 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h" //cartella builtins
#include <stdio.h>

int g_signal_error;//gestire variabile globale

int	echo(int argc, char **argv) //da finire echo (echo mamma)
{
	int	i;
	int	j;

	i = 0;
	if (argc == 1)
		return (write(1, "\n", 1), 0);
	if (argv[1][0] == '-' && argv[1][1] == 'n')
		i++;
	while (++i < argc)
	{
		j = -1;
		while (argv[i][++j])
		{
			if (argv[i][j] == '$' && argv[i][j + 1] == '?')
			{
				ft_putnbr_fd(g_signal_error, 1);
				j++;
			}
			else
				ft_putchar_fd(argv[i][j], 1);
		}
		if (i < argc - 1)
			ft_putchar_fd(' ', 1);
	}
	if (argv[1][0] != '-' && argv[1][1] != 'n')
		ft_putchar_fd('\n', 1);
	return (1);
}
