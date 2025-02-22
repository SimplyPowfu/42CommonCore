/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:43:14 by ecarbona          #+#    #+#             */
/*   Updated: 2025/01/14 16:43:33 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	take_signal(int sig)
{
	static int	c;
	static int	i;

	if (sig == SIGUSR2)
		c = c << 1;
	else if (sig == SIGUSR1)
		c = c << 1 | 0b00000001;
	i++;
	if (i == 8)
	{
		ft_printf("%c", c);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	ft_printf("PID process: %d\n", getpid());
	while (1)
	{
		signal(SIGUSR1, take_signal);
		signal(SIGUSR2, take_signal);
	}
	return (0);
}
