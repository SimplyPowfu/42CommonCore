/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:38:30 by ecarbona          #+#    #+#             */
/*   Updated: 2025/03/27 11:20:48 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# ifndef SIGNAL
#  define SIGNAL//globale per gestire i segnali
# endif

# include "libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <bits/types/siginfo_t.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/wait.h>

void	ft_ignore_signal(struct sigaction sa, int sig);

#endif