/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:40:20 by ecarbona          #+#    #+#             */
/*   Updated: 2025/06/13 23:21:17 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_window(t_root *root)
{
	return (free_all(root), exit(0), 0);
}

void	padding_map(t_root *root)
{
	char	**pad_map;
	int		i;
	int		j;

	pad_map = ft_calloc(root->map->height + 1, sizeof(char *));
	i = -1;
	while (root->map->map[++i])
	{
		pad_map[i] = ft_calloc(root->map->width + 1, sizeof(char));
		j = -1;
		while (root->map->map[i][++j])
			pad_map[i][j] = root->map->map[i][j];
	}
	i = -1;
	while (root->map->map[++i])
		free(root->map->map[i]);
	free(root->map->map);
	root->map->map = pad_map;
}

static void	free_mlx(t_root *root)
{
	if (root->img)
		mlx_destroy_image(root->mlx, root->img);
	if (root->mlx_win)
		mlx_destroy_window(root->mlx, root->mlx_win);
	if (root->mlx)
	{
		mlx_destroy_display(root->mlx);
		free(root->mlx);
	}
}

static void	free_map(t_root *root, int i)
{
	if (root->map->door_state)
	{
		i = -1;
		while (root->map->door_state[++i])
			free(root->map->door_state[i]);
		free(root->map->door_state);
	}
	if (root->map)
	{
		if (root->map->floor)
			free(root->map->floor);
		if (root->map->sky)
			free(root->map->sky);
		if (root->map->player)
			free(root->map->player);
		if (root->map->map)
		{
			i = -1;
			while (root->map->map[++i])
				free(root->map->map[i]);
			free(root->map->map);
		}
		free(root->map);
	}
}

// update the free_all with what you see in validating.c
void	free_all(t_root *root)
{
	int	i;

	if (root->hud)
		free(root->hud);
	free_map(root, 0);
	if (root->texture)
	{
		i = -1;
		while (root->texture[++i])
		{
			if (root->texture[i]->path)
				free(root->texture[i]->path);
			if (root->texture[i]->img)
				mlx_destroy_image(root->mlx, root->texture[i]->img);
			free(root->texture[i]);
		}
		free(root->texture);
	}
	free_mlx(root);
}
