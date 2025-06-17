/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validating.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:46:10 by ecarbona          #+#    #+#             */
/*   Updated: 2025/06/17 17:58:27 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	take_texture_path(t_root *root, char *path, int i, char dir)
{
	int	j;

	j = 0;
	while (path[j] && path[j] == ' ')
		j++;
	while (path[j] && path[j] != ' ')
		j++;
	while (path[j] && path[j] == ' ')
		j++;
	if (!strrchr(&path[j], '.'))
		return (ft_putstr_fd("Error\nInvalid texture path\n", 2), 0);
	if (strcmp(strrchr(&path[j], '.'), ".xpm"))
		return (ft_putstr_fd("Error\nInvalid texture path\n", 2), 0);
	root->texture[i]->path = ft_strdup(&path[j]);
	root->texture[i]->direction = dir;
	root->texture[i]->height = 64;
	root->texture[i]->width = 64;
	root->texture[i]->img = mlx_xpm_file_to_image(root->mlx, root->texture[i]
			->path, &root->texture[i]->width, &root->texture[i]->height);
	if (!root->texture[i]->img)
		return (ft_putstr_fd("Error\nInvalid texture path\n", 2), 0);
	root->texture[i]->data = (int *)mlx_get_data_addr(root->texture[i]->img,
			&root->texture[i]->width, &root->texture[i]->height,
			&root->texture[i]->width);
	return (1);
}

int	take_env(t_root *root, char *path)
{
	if (ft_strncmp("F", path, 1) == 0)
	{
		if (!root->map->floor)
			root->map->floor = ft_calloc(1, sizeof(t_env));
		else
			return (ft_putstr_fd("Error\nDouble initialization floor\n", 2), 0);
		if (!count_comma(path) || !validate_color(root->map->floor, path))
			return (ft_putstr_fd("Error\nFloor: invalid parameter\n", 2), 0);
	}
	else if (ft_strncmp("C", path, 1) == 0)
	{
		if (!root->map->sky)
			root->map->sky = ft_calloc(1, sizeof(t_env));
		else
			return (ft_putstr_fd("Error\nDouble initialization sky\n", 2), 0);
		if (!count_comma(path) || !validate_color(root->map->sky, path))
			return (ft_putstr_fd("Error\nSky: invalid parameter\n", 2), 0);
	}
	return (1);
}

int	take_texture(t_root *root, char *path)
{
	static int	i;

	if (ft_strncmp("NO", path, 2) == 0 || ft_strncmp("SO", path, 2) == 0
		|| ft_strncmp("WE", path, 2) == 0 || ft_strncmp("EA", path, 2) == 0)
		root->texture[i] = ft_calloc(1, sizeof(t_texture));
	if (ft_strncmp("NO", path, 2) == 0)
	{
		if (!take_texture_path(root, path, i, 'N'))
			return (0);
	}
	else if (ft_strncmp("SO", path, 2) == 0)
	{
		if (!take_texture_path(root, path, i, 'S'))
			return (0);
	}
	if (ft_strncmp("NO", path, 2) != 0 && ft_strncmp("SO", path, 2) != 0)
	{
		if (!is_valid_texture(root, path, &i))
			return (0);
	}
	i += 1;
	return (1);
}

static int	take_map(t_root *root, char *argv)
{
	int		y;
	int		x;

	read_map(root, argv);
	root->map->door_state = ft_calloc(root->map->height + 1, sizeof(int *));
	y = -1;
	while (++y < root->map->height)
	{
		root->map->door_state[y] = ft_calloc(root->map->width, sizeof(int));
		x = -1;
		while (++x < root->map->width)
		{
			if (root->map->map[y] && x < (int)ft_strlen(root->map->map[y])
				&& root->map->map[y][x] == 'P')
			{
				root->map->door_state[y][x] = 0;
			}
		}
	}
	if (!validate_header(root))
		return (0);
	if (!slash_n_map(root) || !validate_texture(root))
		return (0);
	return (padding_map(root), 1);
}

int	is_valid(t_root *root, int argc, char *argv)
{
	char	*type;

	if (argc != 2)
		return (ft_putstr_fd("Error\nInvalid Arguments\n", 2), 0);
	type = ft_strrchr(argv, '.');
	if (!type || ft_strcmp(type, ".cub") != 0)
		return (ft_putstr_fd("Error\nInvalid type\n", 2), 0);
	if (!take_map(root, argv))
		return (0);
	if (!validate_map(root))
		return (0);
	if (!root->map->view)
		return (ft_putstr_fd("Error\nMissed player\n", 2), 0);
	return (1);
}
