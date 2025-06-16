/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validating_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 11:42:23 by ecarbona          #+#    #+#             */
/*   Updated: 2025/06/13 23:46:04 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	add_other_textures(t_root *root, char *path, int height, int width)
{
	int	i;

	i = 0;
	while (root->texture[i])
		i++;
	root->texture[i] = ft_calloc(1, sizeof(t_texture));
	root->texture[i]->path = ft_strdup(path);
	root->texture[i]->direction = 0;
	root->texture[i]->img = mlx_xpm_file_to_image(root->mlx, root->texture[i]
			->path, &root->texture[i]->width, &root->texture[i]->height);
	root->texture[i]->data = (int *)mlx_get_data_addr(root->texture[i]->img,
			&root->texture[i]->width, &root->texture[i]->height,
			&root->texture[i]->width);
	root->texture[i]->height = height;
	root->texture[i]->width = width;
}

int	validate_texture(t_root *root)
{
	char	dir[5];
	int		i;
	int		j;

	i = -1;
	j = -1;
	while (root->texture[++i])
	{
		if (root->texture[i]->direction == 'N')
			dir[++j] = 'N';
		else if (root->texture[i]->direction == 'S')
			dir[++j] = 'S';
		else if (root->texture[i]->direction == 'E')
			dir[++j] = 'E';
		else if (root->texture[i]->direction == 'W')
			dir[++j] = 'W';
	}
	dir[++j] = '\0';
	if (!validate_text(dir))
		return (ft_putstr_fd("Error\nDouble initialization texture\n", 2), 0);
	return (1);
}

static int	no_hole_r(t_root *root, char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = is_first_char(map, i, 0);
		if (i > 0 && i < root->map->height - 1)
		{
			while (map[i][j] == '1' || map[i][j] == ' ')
				j--;
			if (map[i][j])
			{
				if (map[i - 1][j] == ' ' || map[i - 1][j] == '\0')
					return (0);
				if (map[i + 1][j] == ' ' || map[i - 1][j] == '\0')
					return (0);
			}
		}
	}
	return (1);
}

static int	no_hole_l(t_root *root, char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = is_first_char(map, i, 1);
		if (i > 0 && i < root->map->height - 1)
		{
			while (map[i][j] == '1' || map[i][j] == ' ')
				j++;
			if (map[i][j])
			{
				if (map[i - 1][j] == ' ')
					return (0);
				if (map[i + 1][j] == ' ')
					return (0);
			}
		}
	}
	return (1);
}

int	validate_map(t_root *root)
{
	int	i;
	int	j;

	i = -1;
	if (!validate_char(root, root->map->map))
		return (0);
	while (root->map->map[++i])
	{
		j = -1;
		while (root->map->map[i][++j])
			if (!is_wall(root, i, j))
				return (0);
	}
	if (!no_hole_l(root, root->map->map))
		return (ft_putstr_fd("Error\nInvalid wall\n", 2), 0);
	if (!no_hole_r(root, root->map->map))
		return (ft_putstr_fd("Error\nInvalid wall\n", 2), 0);
	return (1);
}
