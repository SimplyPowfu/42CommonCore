/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glancell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 16:13:11 by glancell          #+#    #+#             */
/*   Updated: 2025/05/20 12:36:53 by glancell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	is_valid_number(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static long	ft_atol(const char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		result = result * 10 + (*str++ - '0');
	return (result * sign);
}

static void	exit_status_updater(t_shell *shell, int *exit_status)
{
	if (shell->argc == 1 || !shell->cmd)
		*exit_status = exit_error(shell, -1);
	else if (shell->argc > 2)
	{
		write(2, "minishell: exit: too many arguments\n", 36);
		*exit_status = 1;
		exit_error(shell, *exit_status);
		close(3);
		close(4);
	}
	else if (!is_valid_number(shell->argv[1]))
	{
		write(2, "minishell: exit: ", 17);
		write(2, shell->argv[1], ft_strlen(shell->argv[1]));
		write(2, ": numeric argument required\n", 28);
		*exit_status = 2;
	}
	else
		*exit_status = ft_atol(shell->argv[1]) % 256;
}

void	ft_exit(t_shell *shell)
{
	int	exit_status;

	exit_status = 0;
	write(1, "exit\n", 5);
	exit_status_updater(shell, &exit_status);
	close(3);
	close(4);
	if (shell->argc <= 2)
	{
		free_all(shell, 0);
		exit(exit_status);
	}
}
