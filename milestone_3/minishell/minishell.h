/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:38:30 by ecarbona          #+#    #+#             */
/*   Updated: 2025/04/01 16:22:36 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

extern int	g_signal_error;//globale per gestire i segnali

# include "libft/libft.h"
# include <limits.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <bits/types/siginfo_t.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/wait.h>

//struct
typedef struct s_shell
{
	char	*cmd;
	char	**envp;
}	t_shell;


//builtins
int		echo(int argc, char **argv);

//signal
void	ft_ignore_signal(struct sigaction sa, int sig);

#endif