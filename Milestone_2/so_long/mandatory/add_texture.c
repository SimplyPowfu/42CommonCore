/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:12:51 by ecarbona          #+#    #+#             */
/*   Updated: 2025/01/07 13:58:27 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	texture_load(t_root *root, t_img **img, char *path)
{
	int	width;
	int	height;

	*img = mlx_xpm_file_to_image(root->mlx, path, &width, &height);
	(*img)->width = width;
	(*img)->height = height;
}

void	texture_init(t_root *root)
{
	texture_load(root, &root->player, "./textures/player.xpm");
	texture_load(root, &root->player_m, "./textures/playerMove.xpm");
	texture_load(root, &root->enemy, "./textures/enemy.xpm");
	texture_load(root, &root->exit, "./textures/key.xpm");
	texture_load(root, &root->coll, "./textures/coin.xpm");
	texture_load(root, &root->wall, "./textures/wall.xpm");
	texture_load(root, &root->ground, "./textures/sand.xpm");
}

void	put_map_with_textures(t_root *root, t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while ((y * 40) < game->height)
	{
		x = 0;
		while ((x * 40) < game->width)
		{
			if (game->map[y][x] == '1')
				PUT_IM(root->mlx, root->mlx_win, root->wall, x * 40, y * 40);
			else if (game->map[y][x] == 'C')
				PUT_IM(root->mlx, root->mlx_win, root->coll, x * 40, y * 40);
			else if (game->map[y][x] == 'P')
				PUT_IM(root->mlx, root->mlx_win, root->player, x * 40, y * 40);
			else if (game->map[y][x] == 'E')
				PUT_IM(root->mlx, root->mlx_win, root->exit, x * 40, y * 40);
			else
				PUT_IM(root->mlx, root->mlx_win, root->ground, x * 40, y * 40);
			x++;
		}
		y++;
	}
}
