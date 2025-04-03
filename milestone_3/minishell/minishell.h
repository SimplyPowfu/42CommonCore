/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:38:30 by ecarbona          #+#    #+#             */
/*   Updated: 2025/04/03 17:30:06 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdint.h>
# include "libft/libft.h"
# include <limits.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <bits/types/siginfo_t.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/wait.h>

extern int	g_signal_error;//globale per gestire i segnali

//struct
typedef struct s_shell
{
	char	*cmd;//stringa di comando messa in output da readline |
	char	**argc;//quanti comandi abbiamo X
	char	**argv;//quali comandi abbiamo X
	char	**envp;//copia dell env |
	char	*path;//path(pwd) dove ti trovi |
	char	*in_file;//redirect |
	char	*out_file;//redirect |
	char	*heredoc;// |
	int		append;//bool 1/0 - true/false |
}	t_shell;

//inizialization
void	init(char *cmd, char **envp, t_shell *shell);

//builtins
int		echo(int argc, char **argv);

//signal
void	ft_ignore_signal(struct sigaction sa, int sig);

//free
void	free_all(t_shell *shell);

#endif