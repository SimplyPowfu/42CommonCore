/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 01:33:50 by ecarbona          #+#    #+#             */
/*   Updated: 2025/01/08 14:53:29 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_textures(t_root *root)
{
	mlx_destroy_image(root->mlx, root->player);
	mlx_destroy_image(root->mlx, root->player_m);
	mlx_destroy_image(root->mlx, root->enemy);
	mlx_destroy_image(root->mlx, root->exit);
	mlx_destroy_image(root->mlx, root->coll);
	mlx_destroy_image(root->mlx, root->wall);
	mlx_destroy_image(root->mlx, root->ground);
}

void	free_all_bonus(t_root *root, t_game *game)
{
	ft_free_maps_bonus(game->map);
	free_textures(root);
	if (root->mlx_win)
		mlx_destroy_window(root->mlx, root->mlx_win);
	if (root->mlx)
	{
		mlx_destroy_display(root->mlx);
		free(root->mlx);
	}
}
