/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 18:54:54 by ecarbona          #+#    #+#             */
/*   Updated: 2025/06/13 23:17:57 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	validate_char(t_root *root, char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != ' '
				&& map[i][j] != 'N' && map[i][j] != 'S'
				&& map[i][j] != 'E' && map[i][j] != 'W' && map[i][j] != 'P')
				return (ft_putstr_fd("Error\nInvalid character\n", 2), 0);
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E'
				|| map[i][j] == 'W')
			{
				if (!root->map->view)
					take_player(root, i, j);
				else
					return (ft_putstr_fd
						("Error\nDouble initialization player\n", 2), 0);
			}
		}
	}
	return (1);
}

int	validate_header(t_root *root)
{
	int	i;

	i = -1;
	while (root->map->map[0] && ++i < 6)
	{
		while (root->map->map[0][0] == '\0')
			shift_arg(root, 0);
		if (root->map->map[0] && !take_texture(root, root->map->map[0]))
			return (0);
		shift_arg(root, 0);
		while (root->map->map[0][0] == '\0')
			shift_arg(root, 0);
	}
	return (1);
}

int	validate_text(char *dir)
{
	int	i;
	int	j;

	i = -1;
	while (dir[++i])
	{
		j = -1;
		while (dir[++j])
		{
			if (j == i)
				j++;
			if (dir[i] == dir[j])
				return (0);
		}
	}
	return (1);
}

int	validate_number(t_env *env, char *result, int *color)
{
	int	i;

	i = -1;
	if (result[0])
		(*color)++;
	while (result[++i])
		if (!ft_isdigit(result[i]))
			return (0);
	if (ft_atoi(result) < 0 || ft_atoi(result) > 255)
		return (0);
	if (*color == 1)
		env->r = ft_atoi(result);
	else if (*color == 2)
		env->g = ft_atoi(result);
	else if (*color == 3)
		env->b = ft_atoi(result);
	return (1);
}

int	validate_color(t_env *env, char *path)
{
	int		i;
	int		j;
	int		color;
	char	*result;

	color = 0;
	i = 1;
	while (path[i])
	{
		j = 0;
		result = ft_calloc(ft_strlen(path), sizeof(char));
		while (path[i] && (path[i] == ' ' || path[i] == ','))
			i++;
		while (path[i] && path[i] != ',')
			result[j++] = path[i++];
		path = &path[i];
		if (!validate_number(env, result, &color))
			return (free(result), 0);
		free(result);
		i = 0;
	}
	if (color != 3)
		return (0);
	return (1);
}
