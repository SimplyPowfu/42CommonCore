/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glancell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:32:55 by tolanini          #+#    #+#             */
/*   Updated: 2025/05/15 13:54:39 by glancell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	add_or_update_var(t_shell *shell, const char *arg)
{
	char	*eq;
	char	*key;
	char	*value;
	int		result;

	eq = ft_strchr(arg, '=');
	if (eq)
	{
		key = ft_substr(arg, 0, eq - arg);
		value = ft_strdup(eq + 1);
	}
	else
	{
		key = ft_strdup(arg);
		value = ft_strdup("");
	}
	if (key == NULL || value == NULL)
	{
		free(key);
		free(value);
		perror("malloc");
		return (-1);
	}
	result = update_env(shell, key, value);
	return (free(key), free(value), result);
}

static char	**copy_envp(char **envp)
{
	char	**dupe;
	int		count;
	int		j;

	count = 0;
	while (envp[count])
		count++;
	dupe = malloc(sizeof(char *) * (count + 1));
	if (dupe == NULL)
		return (NULL);
	j = -1;
	while (++j < count)
	{
		dupe[j] = ft_strdup(envp[j]);
		if (dupe[j] == NULL)
		{
			while (--j >= 0)
				free(dupe[j]);
			free(dupe);
			return (NULL);
		}
	}
	dupe[j] = NULL;
	bubble_sort(dupe);
	return (dupe);
}

static void	print_env_var(char *var)
{
	char	*eq;

	eq = ft_strchr(var, '=');
	write(1, "declare -x ", 11);
	if (eq)
	{
		write(1, var, eq - var);
		write(1, "=\"", 2);
		write(1, eq + 1, ft_strlen(eq + 1));
		write(1, "\"\n", 2);
	}
	else
	{
		write(1, var, ft_strlen(var));
		write(1, "\n", 1);
	}
}

static void	print_env(char **envp)
{
	char	**dupe_envp;
	int		i;

	dupe_envp = copy_envp(envp);
	if (dupe_envp == NULL)
		return ;
	i = -1;
	while (dupe_envp[++i])
	{
		print_env_var(dupe_envp[i]);
		free(dupe_envp[i]);
	}
	free(dupe_envp);
}

int	ft_export(t_shell *shell)
{
	int		has_error;
	int		i;
	char	**args;

	if (shell->command && *shell->command && (*shell->command)->args)
		args = (*shell->command)->args;
	else
		args = shell->argv;
	if ((shell->command && *shell->command && !args[1])
		|| (!shell->command && shell->argc == 1))
		return (print_env(shell->envp), exit_error(shell, 0), 0);
	has_error = 0;
	i = 0;
	while (args[++i])
	{
		if (!is_valid_varname(args[i]))
		{
			print_export_error(args[i]);
			has_error = 1;
		}
		else if (add_or_update_var(shell, args[i]) == -1)
			has_error = 1;
	}
	exit_error(shell, has_error);
	return (has_error);
}
