/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:47:36 by ecarbona          #+#    #+#             */
/*   Updated: 2025/05/17 17:01:05 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include <stdlib.h>
#include <unistd.h>

void	shift_arg(t_shell *shell, int i, int *k)
{
	int	j;

	if (i == shell->argc - 1)
	{
		free(shell->argv[i]);
		shell->argv[i] = NULL;
		shell->argc--;
		return ;
	}
	free(shell->argv[i]);
	j = i;
	while (j < shell->argc - 1)
	{
		shell->argv[j] = shell->argv[j + 1];
		j++;
	}
	shell->argv[j] = NULL;
	shell->argc--;
	(*k)--;
}

int	len_pre_dollar(char *str, char **envp)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	while (envp[++i])
	{
		k = 0;
		j = pre_dollar(str);
		if (str[j] && (str[j + 1] == '?' || str[j + 1] == '$'))
			return (1);
		while (str[j + 1] && str[j + 1] == envp[i][k++])
			j++;
		if (envp[i][--k] == '=' && (str[j + 1] == '\0' || str[j + 1] == '$'
			|| str[j + 1] == ' '))
			return (k);
		else if (envp[i][k] == '=' && str[j + 1])
		{
			while (str[j])
				j++;
			return (j);
		}
	}
	return (ft_strlen(ft_strrchr(str, '$')));
}

static char	*expandstr(t_shell *shell, char *str, char *expand, int envp)
{
	char	*result;
	int		i;
	int		j;
	int		k;

	i = -1;
	k = 0;
	j = 0;
	result = malloc_result(str, expand);
	while (str[++i])
	{
		if (str[i] == '$' && j == 0)
		{
			if (is_expandible(str, shell->envp, &i) == 1 || envp == -1)
				while (expand[j])
					result[k++] = expand[j++];
			reset_expand_var(shell, &str, &i);
		}
		else
			result[k++] = str[i];
	}
	free(expand);
	if (result[0] == '\0')
		return (free(result), NULL);
	return (result);
}

char	*in_env(t_shell *shell, char *str, char **envp)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	j = pre_dollar(str);
	if (str[j] && !str[j + 1])
		return (ft_strdup(str));
	if (str[j] && str[j + 1] == '?')
		return (expandstr(shell, str, ft_itoa(exit_error(shell, -1)), i));
	if (str[j] && str[j + 1] == '$')
		return (expandstr(shell, str, ft_itoa(getpid()), i));
	while (str[j] && envp[++i])
	{
		k = 0;
		search_in_env(str, envp, i, &k);
		if (envp[i][k] == '=')
			return (expandstr(shell, str, ft_strdup(&envp[i][k + 1]), i));
	}
	if (j)
		return (var_not_expandible(str, j));
	return (NULL);
}

void	var_in_env(t_shell *shell, char **argv, int *k)
{
	char	*s;
	int		i;

	while (*argv && ft_strchr(*argv, '$'))
	{
		i = 0;
		while ((*argv)[i] != '$' && (*argv)[i])
			i++;
		if ((*argv)[i] == '\0' || (*argv)[i + 1] == '\0'
			|| (*argv)[i + 1] == ' ')
			return ;
		i = 0;
		while (shell->argv[i] != *argv)
			i++;
		s = ft_strdup(*argv);
		free(*argv);
		*argv = in_env(shell, s, shell->envp);
		free(s);
		if (*argv == NULL)
			shift_arg(shell, i, k);
	}
}
