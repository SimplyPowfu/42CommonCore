/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testshell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:41:12 by ecarbona          #+#    #+#             */
/*   Updated: 2025/04/07 16:18:10 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

//quando faccio CTRL+D leakka, provo a freeare una struttura vuota

int	main(int argc, char **argv, char **envp)
{
	char	*command;
	t_shell	shell;
	g_signal_error = 0;

	(void)argv;
	if (argc != 1)
		return (write (1,"Error\n", 6), 1);
	signal(SIGINT, signal_manager);
	signal(SIGQUIT, SIG_IGN);
	command = readline("minishell$ ");
	init(command, envp, &shell);
	while (command)
	{
		add_history(command);
		if (!pars(&shell))//gestisto l'out di readline e inizializzo nella struttura i comandi parsati
			{
				printf("%s: command not found\n", command);
				g_signal_error = 127;
			}
		if (!shell.cmd)
			return (write(1, "exit\n", 5), free(command),
				rl_clear_history(), free_all(&shell), 0);
		free(command);
		free_all(&shell);
		command = readline("minishell$ ");
		init(command, envp, &shell);
	}
	if (!command)
		return (write(1, "exit\n", 5), free(command),
			rl_clear_history(), free_all(&shell), 0);
}
