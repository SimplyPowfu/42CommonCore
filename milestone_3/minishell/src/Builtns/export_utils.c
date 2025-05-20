/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glancell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:52:39 by tolanini          #+#    #+#             */
/*   Updated: 2025/05/15 13:50:04 by glancell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	compare_envp(const char *a, const char *b)
{
	return (ft_strcmp(a, b));
}

static void	swap(char **a, char **b)
{
	char	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	bubble_sort(char **envp)
{
	int	i;
	int	swapped;
	int	j;

	i = 0;
	while (envp[i])
	{
		swapped = 0;
		j = 0;
		while (envp[j + 1])
		{
			if (compare_envp(envp[j], envp[j + 1]) > 0)
			{
				swap(&envp[j], &envp[j + 1]);
				swapped = 1;
			}
			j++;
		}
		if (swapped == 0)
			break ;
		i++;
	}
}

void	print_export_error(char *arg)
{
	write(STDERR_FILENO, "minishell: export: `", 20);
	write(STDERR_FILENO, arg, ft_strlen(arg));
	write(STDERR_FILENO, "': not a valid identifier\n", 26);
}

int	is_valid_varname(const char *str)
{
	const char	*p;

	p = str;
	if (p == NULL || *p == '\0' || *p == '=' || ft_isdigit(*p))
		return (0);
	while (*p && *p != '=')
	{
		if (ft_isalnum(*p) == 0 && *p != '_')
			return (0);
		p++;
	}
	return (1);
}
