/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testshell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:41:12 by ecarbona          #+#    #+#             */
/*   Updated: 2025/03/24 17:42:31 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void signal_manager(void *signal)
{
	
}

int main()
{
	char *command;

	command = readline("minishell$ ");
	while(command)
	{
		add_history(command);
		if (command[0] == 'e')
			break;
		else if (command[0] == 'c')
			rl_clear_history();
		else
			ft_printf("input\n");
		free(command);
		command = readline("minishell$ ");
	}
	rl_clear_history();
	free(command);
}