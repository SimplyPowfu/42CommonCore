/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 13:02:16 by ecarbona          #+#    #+#             */
/*   Updated: 2025/06/14 13:11:58 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_kick_punch(t_root *root, int i)
{
	if (root->texture[i]->img)
	{
		draw_kick(root, i);
		draw_helmet(root, root->texture[4]->img);
		draw_minimap(root);
		mlx_put_image_to_window(root->mlx, root->mlx_win, root->img, 0, 0);
		mlx_do_sync(root->mlx);
		ft_usleep(20);
		render_frame(root);
	}
}

void	draw_in_offset(t_root *root, t_draw_anim *anim, int i)
{
	while (++root->hud->x < root->texture[i]->width)
	{
		anim->dst_x = anim->offset_x + root->hud->x;
		if (anim->dst_x >= WIDTH)
			continue ;
		anim->src_i = root->hud->y * anim->tex_sl + root->hud->x
			* (anim->tex_bpp / 8);
		anim->dst_i = anim->dst_y * root->hud->sl + anim->dst_x
			* (root->hud->bpp / 8);
		root->hud->color = *(int *)(root->hud->overlay_data + anim->src_i);
		if ((root->hud->color & 0x00FFFFFF) == 0x000000)
			continue ;
		*(int *)(root->hud->main_data + anim->dst_i) = root->hud->color;
	}
}

void	draw_hud_win(t_root *root)
{
	int	i;

	while (++root->hud->x < WIDTH)
	{
		i = root->hud->y * root->hud->sl + root->hud->x
			* (root->hud->bpp / 8);
		root->hud->color = *(int *)(root->hud->overlay_data + i);
		if (root->hud->y > 200)
		{
			if (root->hud->color != 0x00000000 && root->hud->x % 2 == 0)
				continue ;
			else if (root->hud->color != 0x00000000)
				*(int *)(root->hud->main_data + i) = 0x00500000;
			else
				*(int *)(root->hud->main_data + i) = root->hud->color;
		}
		else
			*(int *)(root->hud->main_data + i) = root->hud->color;
	}
}
