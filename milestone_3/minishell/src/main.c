/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glancell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:41:12 by ecarbona          #+#    #+#             */
/*   Updated: 2025/05/20 11:07:13 by glancell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include <readline/history.h>

int		g_signal = 0;

void	first_init(t_shell *shell, int argc, char **argv, char **envp)
{
	(void)argv;
	if (argc != 1)
	{
		write(1, "too many arguments\n", 20);
		exit(1);
	}
	shell->envp = NULL;
	signal(SIGINT, signal_manager);
	signal(SIGQUIT, SIG_IGN);
	take_env(envp, shell);
}

int	main(int argc, char **argv, char **envp)
{
	char	*command;
	t_shell	shell;

	first_init(&shell, argc, argv, envp);
	command = readline("minishell$ ");
	while (command && !is_valid(&shell, command))
		command = readline("minishell$ ");
	init(command, &shell);
	while (command)
	{
		g_signal = 0;
		add_history(command);
		pars(&shell);
		free(command);
		free_all(&shell, 1);
		command = readline("minishell$ ");
		while (command && !is_valid(&shell, command))
			command = readline("minishell$ ");
		init(command, &shell);
		close(3);
		close(4);
	}
	if (!shell.cmd)
		ft_exit(&shell);
}
