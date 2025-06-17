/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 23:25:56 by ecarbona          #+#    #+#             */
/*   Updated: 2025/06/17 17:59:10 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	count_comma(char *path)
{
	int	comma;
	int	i;

	i = -1;
	comma = 0;
	while (path[++i])
		if (path[i] == ',')
			comma++;
	if (comma != 2)
		return (0);
	return (1);
}

int	is_valid_texture(t_root *root, char *path, int *i)
{
	if (ft_strncmp("WE", path, 2) == 0)
	{
		if (!take_texture_path(root, path, *i, 'W'))
			return (0);
	}
	else if (ft_strncmp("EA", path, 2) == 0)
	{
		if (!take_texture_path(root, path, *i, 'E'))
			return (0);
	}
	else if (ft_strncmp("F", path, 1) == 0 || ft_strncmp("C", path, 1) == 0)
	{
		if (!take_env(root, path))
			return (0);
		*i -= 1;
	}
	else
		return (ft_putstr_fd("Error\nInvalid parameter\n", 2), 0);
	return (1);
}

void	read_map(t_root *root, char *argv)
{
	int		i;
	int		fd;
	char	*line;

	root->map->map = ft_calloc(100, sizeof(char *));
	fd = open(argv, O_RDONLY);
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		root->map->map[i] = ft_strdup(line);
		if (root->map->map[i][ft_strlen(line) - 1] == '\n')
			root->map->map[i][ft_strlen(line) - 1] = '\0';
		i++;
		root->map->height++;
		if ((int)ft_strlen(line) > root->map->width)
			root->map->width = (int)ft_strlen(line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

int	is_wall(t_root *root, int i, int j)
{
	if (j == is_first_char(root->map->map, i, 1)
		&& (i == 0 || i == root->map->height - 1))
		if (root->map->map[i][j] != '1')
			return (ft_putstr_fd("Error\nInvalid wall\n", 2), 0);
	if (j == is_first_char(root->map->map, i, 1) || j == (
			(int)ft_strlen(root->map->map[i]) - 1))
		if (root->map->map[i][j] != '1')
			return (ft_putstr_fd("Error\nInvalid wall\n", 2), 0);
	return (1);
}

int	slash_n_map(t_root *root)
{
	int	i;

	i = -1;
	while (root->map->map[++i])
	{
		if (!root->map->map[i][0])
			return (ft_putstr_fd("Error\nInvalid Map\n", 2), 0);
	}
	return (1);
}
