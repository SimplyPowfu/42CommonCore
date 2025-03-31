/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testshell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:41:12 by ecarbona          #+#    #+#             */
/*   Updated: 2025/03/31 19:14:34 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_sstrcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void signal_manager(int signal)
{
	struct sigaction	sa;

	if(signal == SIGINT) //segnale CTRL+C quando non fa niente
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

int main(int argc, char **argv, char **envp)
{
	char *command;

	if (argc != 1)
		return (write(1,"Error: no arguments\n", 20), 1);
	signal(SIGINT, signal_manager);
	signal(SIGQUIT, SIG_IGN);	
	command = readline("minishell$ ");
	while(command)
	{
		if (!ft_sstrcmp(command, "exit"))
		{
			command = NULL;
			break ;
		}
		add_history(command);
		free(command);
		command = readline("minishell$ ");
	}
	if (!command)
		return (write(1, "exit\n", 5), rl_clear_history(), free(command), 0);
}
