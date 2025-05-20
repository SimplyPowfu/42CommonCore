/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glancell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 09:41:31 by ecarbona          #+#    #+#             */
/*   Updated: 2025/05/17 19:12:50 by glancell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	pre_dollar(char *str)
{
	int	j;

	j = 0;
	while (str[j] != '$' && str[j])
		j++;
	return (j);
}

int	is_expandible(char *str, char **envp, int *str_pos)
{
	int	i;
	int	j;
	int	k;

	(void)str_pos;
	j = 0;
	k = 0;
	i = -1;
	while (str[j] && str[j] != '$')
		j++;
	while (envp[++i])
	{
		while (str[j + 1] && str[j + 1] == envp[i][k])
		{
			j++;
			k++;
		}
		if (envp[i][k] == '=' && (str[j + 1] == '\0' || str[j + 1] == '$'
				|| str[j + 1] == ' '))
			return (1);
		j = pre_dollar(str);
		k = 0;
	}
	return (0);
}

void	search_in_env(char *str, char **envp, int i, int *k)
{
	int	j;

	j = pre_dollar(str);
	while (str[j + 1] && str[j + 1] == envp[i][*k])
	{
		j++;
		(*k)++;
	}
}

char	*malloc_result(char *str, char *expand)
{
	char	*result;
	int		i;
	int		k;

	i = -1;
	k = 0;
	while (str[++i])
	{
		if (str[i] == '$')
			k++;
	}
	result = ft_calloc(((ft_strlen(str) - ft_strlen(ft_strrchr(str, '$')))
				+ (ft_strlen(expand)
					+ ft_strlen(ft_strrchr(str, '$')))) + 1, k);
	return (result);
}

void	reset_expand_var(t_shell *shell, char **str, int *i)
{
	(*i) += len_pre_dollar(*str, shell->envp);
	while ((*i) >= (int)ft_strlen(*str))
		(*i)--;
	*str = &(*str)[*i];
	(*i) = 0;
}
