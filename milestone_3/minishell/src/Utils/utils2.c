/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 11:58:59 by ecarbona          #+#    #+#             */
/*   Updated: 2025/05/17 13:23:41 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	add_space_malloc(char *command)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (command[++i])
		if (command[i] == '>' || command[i] == '<' || command[i] == '|')
			j += 2;
	return (j);
}

static char	*ft_space(char *command)
{
	int		i;
	char	*temp;

	i = 0;
	temp = malloc(ft_strlen(command) + 1);
	while (command[i] && command[i] != ' ')
	{
		temp[i] = command[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

int	is_valid(t_shell *shell, char *command)
{
	int		i;
	char	*check;
	char	*trim;

	i = 0;
	if (!close_quote(command))
		return (add_history(command), exit_error(shell, 2),
			printf("syntax error\n"), 0);
	while (command[i] && command[i] == ' ')
		i++;
	if (command[i] != '\0')
	{
		trim = ft_space(&command[i]);
		if (ft_strchr(trim, '$'))
		{
			check = in_env(shell, trim, shell->envp);
			if (check == NULL)
				return (free(trim), free(command), 0);
			free(check);
		}
		return (free(trim), 1);
	}
	return (free(command), 0);
}

int	count_char(t_shell *shell, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (shell-> cmd && shell->cmd[i])
	{
		if (shell->cmd[i] == 34 || shell->cmd[i] == 39)
		{
			i++;
			while (shell->cmd[i] && shell->cmd[i] != 34 && shell->cmd[i] != 39)
				i++;
		}
		if (shell->cmd[i] == c)
			j++;
		if (shell->cmd[i])
			i++;
	}
	return (j);
}

void	redir_is_char(char **argv)
{
	char	*temp;

	if ((*argv)[0] == '>' || (*argv)[0] == '<' )
	{
		temp = ft_strdup((*argv));
		free((*argv));
		(*argv) = ft_strjoin(" ", temp);
		free(temp);
	}
}
