/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hadler_process_utility.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glancell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:21:02 by glancell          #+#    #+#             */
/*   Updated: 2025/05/18 23:47:24 by glancell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	handle_parent_process(pid_t pid, char **paths)
{
	int	status;
	int	exit_status;

	status = 0;
	exit_status = 0;
	waitpid(pid, &status, 0);
	if (paths != NULL)
		ft_free_split(paths);
	if (WIFEXITED(status))
		exit_status = WEXITSTATUS(status);
	else
		exit_status = 1;
	return (exit_status);
}
