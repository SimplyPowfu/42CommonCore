/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 12:48:30 by ecarbona          #+#    #+#             */
/*   Updated: 2025/05/20 15:33:02 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	signal_print_newline(int signal)
{
	if (signal == SIGINT)
	{
		write(2, "\n", 1);
		g_signal = SIGINT;
	}
	if (signal == SIGQUIT)
	{
		write(2, "Quit (core dumped)\n", 20);
		g_signal = SIGQUIT;
	}
}

void	signal_print_newline_child(int signal)
{
	if (signal == SIGINT)
		g_signal = SIGINT;
	if (signal == SIGQUIT)
		g_signal = SIGQUIT;
}

void	set_signals_noninteractive(void)
{
	struct sigaction	act;

	ft_memset(&act, 0, sizeof(act));
	act.sa_handler = &signal_print_newline;
	sigaction(SIGINT, &act, NULL);
	sigaction(SIGQUIT, &act, NULL);
}

void	set_signals_noninteractive_child(void)
{
	struct sigaction	act;

	ft_memset(&act, 0, sizeof(act));
	act.sa_handler = &signal_print_newline_child;
	sigaction(SIGINT, &act, NULL);
	sigaction(SIGQUIT, &act, NULL);
}
