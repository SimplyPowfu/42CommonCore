/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glancell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 11:06:39 by ecarbona          #+#    #+#             */
/*   Updated: 2025/05/18 21:09:27 by glancell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"//cartella signal
#include <signal.h>

void	signal_manager(int signal)
{
	if (signal == SIGINT)
	{
		write(2, "\n", 1);
		g_signal = SIGINT;
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	sig_here(int signal)
{
	if (signal == SIGINT)
	{
		close(0);
		write(2, "\n", 1);
		g_signal = SIGINT;
	}
}

void	handle_sigpipe(int sig)
{
	(void)sig;
	g_signal = SIGPIPE;
}

void	set_pipeline_signals(void)
{
	struct sigaction	act;

	ft_memset(&act, 0, sizeof(act));
	act.sa_handler = handle_sigpipe;
	sigaction(SIGPIPE, &act, NULL);
	set_signals_noninteractive();
}
