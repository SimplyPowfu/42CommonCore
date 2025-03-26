/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testshell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:41:12 by ecarbona          #+#    #+#             */
/*   Updated: 2025/03/26 19:23:30 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void signal_manager(int signal)
{
	if(signal == SIGINT) //segnale CTRL+C
	{
		printf("CTRL+C");
	}
	else if(signal == SIGQUIT) //segnale CTRL+D
	{
		printf("CTRL+\\");
	}
}

int main()
{
	char *command;

	signal(SIGINT, signal_manager);
	signal(SIGQUIT, signal_manager);
	command = readline("minishell$ ");
	while(command)
	{
		add_history(command);
		if (!command)
		{
			write(1, "exit", 4);
			break;
		}
		free(command);
		command = readline("minishell$ ");
	}
	rl_clear_history();
	free(command);
}