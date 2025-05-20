/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 17:41:29 by tolanini          #+#    #+#             */
/*   Updated: 2025/05/20 11:42:02 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char	*make_env_var(const char *key, const char *value)
{
	size_t	key_len;
	size_t	val_len;
	char	*env_var;

	key_len = ft_strlen(key);
	val_len = ft_strlen(value);
	env_var = malloc(key_len + val_len + 2);
	if (!env_var)
		return (NULL);
	ft_memcpy(env_var, key, key_len);
	env_var[key_len] = '=';
	ft_memcpy(env_var + key_len + 1, value, val_len);
	env_var[key_len + val_len + 1] = '\0';
	return (env_var);
}

static int	add_env(t_shell *shell, char *env_var)
{
	int		i;
	char	**new_envp;

	i = 0;
	while (shell->envp[i])
		i++;
	new_envp = (char **)malloc(sizeof(char *) * (i + 2));
	if (!new_envp)
		return (-1);
	i = 0;
	while (shell->envp[i])
	{
		new_envp[i] = shell->envp[i];
		i++;
	}
	new_envp[i] = env_var;
	new_envp[i + 1] = NULL;
	free(shell->envp);
	shell->envp = new_envp;
	return (0);
}

int	update_env(t_shell *shell, const char *key, const char *value)
{
	int		i;
	size_t	key_len;
	char	*new_var;

	i = 0;
	key_len = ft_strlen(key);
	new_var = make_env_var(key, value);
	if (!new_var)
		return (free(new_var), -1);
	while (shell->envp[i])
	{
		if (ft_strncmp(shell->envp[i], key, key_len) == 0
			&& shell->envp[i][key_len] == '=')
		{
			free(shell->envp[i]);
			shell->envp[i] = ft_strdup(new_var);
			free(new_var);
			return (0);
		}
		i++;
	}
	if (add_env(shell, new_var) == 0)
		return (0);
	return (free(new_var), -1);
}

static int	handle_cd_errors(t_shell *shell, char *path, int error)
{
	if (path)
		free(path);
	if (error == 1)
		write(2, "cd: too many arguments\n", 23);
	else if (error == 2)
		perror("getcwd");
	else if (error == 3)
		perror("cd");
	else if (error == 4)
		perror("setenv");
	exit_error(shell, 1);
	return (1);
}

int	cd(t_shell *shell)
{
	char	old_pwd[4096];
	char	new_pwd[4096];
	char	*path;

	if (shell->argc != 2)
		return (handle_cd_errors(shell, NULL, 1));
	path = ft_strdup(shell->argv[1]);
	if (!path)
		return (handle_cd_errors(shell, NULL, 1));
	if (getcwd(old_pwd, sizeof(old_pwd)) == NULL)
		return (handle_cd_errors(shell, path, 2));
	if (chdir(path) != 0)
		return (handle_cd_errors(shell, path, 3));
	if (getcwd(new_pwd, sizeof(new_pwd)) == NULL)
		return (handle_cd_errors(shell, path, 2));
	if (update_env(shell, "OLDPWD", old_pwd) == -1
		|| update_env(shell, "PWD", new_pwd) == -1)
		return (handle_cd_errors(shell, path, 4));
	free(shell->path);
	shell->path = path;
	return (exit_error(shell, 0), 0);
}
