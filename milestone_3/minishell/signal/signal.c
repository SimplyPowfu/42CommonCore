/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 11:06:39 by ecarbona          #+#    #+#             */
/*   Updated: 2025/04/03 17:27:43 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_ignore_signal(struct sigaction sa, int sig) //quando CTRL+\ non fa niente
{
	sa.sa_handler = SIG_IGN;
	sigaction(sig, &sa, NULL);
}
