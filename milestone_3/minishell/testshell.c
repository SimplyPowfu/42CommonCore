/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testshell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:41:12 by ecarbona          #+#    #+#             */
/*   Updated: 2025/04/03 17:34:29 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	signal_manager(int signal)
{
	struct sigaction	sa;

	if (signal == SIGINT) //segnale CTRL+C quando non fa niente
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

int	main(int argc, char **argv, char **envp)
{
	char	*command;
	int		g_signal_error = 0;
	t_shell	shell;

	if (argc != 1)
		return (write (1,"Error\n", 6), 1);
	signal(SIGINT, signal_manager);
	signal(SIGQUIT, SIG_IGN);
	command = readline("minishell$ ");
	init(command, envp, &shell);
	while (command)
	{
		if (!ft_strcmp(command, "exit"))
		{
			command = NULL;
			break ;
		}
		add_history(command);
		free(command);
		command = readline("minishell$ ");
	}
	if (!command)
		return (write(1, "exit\n", 5), free(command),
			rl_clear_history(), free_all(&shell), 0);
}
