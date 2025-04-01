/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:43:05 by ecarbona          #+#    #+#             */
/*   Updated: 2025/04/02 00:24:25 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minitalk.h"

void	put_signal(int pid, char *str)
{
	int	i;
	int	c;

	i = 0;
	while (*str)
	{
		c = *(str);
		while (i < 8)
		{
			if (c << i & 0b10000000)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			i++;
			usleep(200);
		}
		str++;
		i = 0;
	}
}

int	main(int argc, char **argv)
{
	if (ft_atoi(argv[1]) <= 0)
	{
		ft_printf("Invalid PID.\n");
		exit(1);
	}
	if (argc == 3)
		put_signal(ft_atoi(argv[1]), argv[2]);
	else
	{
		ft_printf("Invalid arguments, Put PID and messange.\n");
		exit(1);
	}
	return (0);
}
