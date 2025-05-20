/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:25:24 by ecarbona          #+#    #+#             */
/*   Updated: 2025/05/20 14:55:53 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	echo(int argc, char **argv)
{
	int	i;
	int	j;
	int	is_n;

	is_n = 0;
	i = 1;
	if (argc == 1)
		return (write(1, "\n", 1), 1);
	while (echo_is_n(argv, &i))
		is_n = 1;
	while (i < argc)
	{
		j = -1;
		while (argv[i][++j])
			ft_putchar_fd(argv[i][j], 1);
		if (i < argc - 1)
			ft_putchar_fd(' ', 1);
		i++;
	}
	if (!is_n)
		ft_putchar_fd('\n', 1);
	return (1);
}
