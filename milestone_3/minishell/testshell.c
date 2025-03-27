/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testshell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:41:12 by ecarbona          #+#    #+#             */
/*   Updated: 2025/03/27 12:00:21 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void signal_manager(int signal)
{
	struct sigaction	sa;

	if(signal == SIGINT) //segnale CTRL+C quando non fa niente
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		return ;
	}
	else if(signal == SIGQUIT)/*&& comando attivo quit del processo in esec*/ 
	{
		ft_ignore_signal(sa, SIGQUIT);//segnale CTRL+\" quando non fa niente
	}
}

int main(int argc, char **argv, char **envp)
{
	char *command;

	if (argc != 1)
		return (write(1,"Error: no arguments\n", 20), 1);
	signal(SIGINT, signal_manager);
	signal(SIGQUIT, signal_manager);	
	command = readline("minishell$ ");
	while(command)
	{
		add_history(command);
		free(command);
		command = readline("minishell$ ");
	}
	if (!command)
		return (write(1, "exit\n", 5), rl_clear_history(), free(command), 0);
}
