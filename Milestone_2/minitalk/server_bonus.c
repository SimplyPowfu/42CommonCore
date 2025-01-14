/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:34:17 by ecarbona          #+#    #+#             */
/*   Updated: 2025/01/14 16:44:05 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	take_signal(int sig, siginfo_t *info, void *content)
{
	static int	c;
	static int	i;

	(void)content;
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
		if (kill(info->si_pid, SIGUSR1) == -1)
			ft_putstr_fd("Unable to send SIGUSR1\n", 2);
		return ;
	}
	if (kill(info->si_pid, SIGUSR2) == -1)
		ft_putstr_fd("Unable to send SIGUSR2\n", 2);
}

int	main(void)
{
	struct sigaction	sa_sig;

	ft_printf("PID process: %d\n", getpid());
	sa_sig = (struct sigaction){0};
	while (1)
	{
		sa_sig.sa_sigaction = &take_signal;
		sa_sig.sa_flags = SA_SIGINFO;
		if (sigaction(SIGUSR1, &sa_sig, NULL) == -1)
			ft_printf("Unable to send SIGUSR1\n", 2);
		if (sigaction(SIGUSR2, &sa_sig, NULL) == -1)
			ft_printf("Unable to send SIGUSR2\n", 2);
	}
	return (0);
}
