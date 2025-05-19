/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 11:06:39 by ecarbona          #+#    #+#             */
/*   Updated: 2025/04/03 18:23:57 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"//cartella signal

void	signal_manager(int signal)
{
	if (signal == SIGINT) //segnale CTRL+C quando non fa niente
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	ft_ignore_signal(struct sigaction sa, int sig) //quando CTRL+\ non fa niente
{
	sa.sa_handler = SIG_IGN;
	sigaction(sig, &sa, NULL);
}
