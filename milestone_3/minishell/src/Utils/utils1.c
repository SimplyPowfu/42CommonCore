/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 11:50:52 by ecarbona          #+#    #+#             */
/*   Updated: 2025/05/17 11:55:33 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	exit_error(t_shell *shell, int number)
{
	int		error;
	char	*exit_error;
	char	*itoa;

	if (number < 0 || number > 255)
	{
		exit_error = in_env(shell, "$EXIT_ERROR", shell->envp);
		error = ft_atoi(exit_error);
	}
	else
	{
		itoa = ft_itoa(number);
		exit_error = ft_strjoin("EXIT_ERROR=", itoa);
		add_or_update_var(shell, exit_error);
		error = number;
		free(itoa);
	}
	free(exit_error);
	return (error);
}

char	*var_not_expandible(char *str, int finish)
{
	int		i;
	char	*result;

	i = 0;
	result = malloc(sizeof(char *) * ft_strlen(str));
	while (str[i] && i < finish)
	{
		result[i] = str[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

int	echo_is_n(char **argv, int *i)
{
	int	j;

	j = 2;
	if (argv[*i] && argv[*i][0] == '-' && argv[*i][1] == 'n')
	{
		while (argv[*i][j] && argv[*i][j] == 'n')
			j++;
		if (!argv[*i][j])
		{
			(*i)++;
			return (1);
		}
	}
	return (0);
}

void	pipe_is_char(char **argv)
{
	if ((*argv)[0] && (*argv)[0] == '|' && !(*argv)[1])
	{
		free(*argv);
		(*argv) = ft_strdup(" |");
	}
}

void	take_env(char **envp, t_shell *shell)
{
	int	i;

	i = -1;
	while (envp[++i])
		i++;
	shell->envp = malloc(sizeof(char *) * (i + 1));
	i = -1;
	while (envp[++i])
		shell->envp[i] = ft_strdup(envp[i]);
	shell->envp[i] = NULL;
	add_or_update_var(shell, "EXIT_ERROR=0");
}
