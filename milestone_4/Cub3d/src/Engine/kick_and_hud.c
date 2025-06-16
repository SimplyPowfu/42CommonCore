/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kick_and_hud.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 21:11:01 by ecarbona          #+#    #+#             */
/*   Updated: 2025/06/14 13:12:29 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	add_texture(t_root *root)
{
	add_other_textures(root, "resource/texture/HUD.xpm", HEIGHT, WIDTH);
	add_other_textures(root, "resource/texture/door.xpm", 64, 64);
	add_other_textures(root, "resource/texture/kick1.xpm", 446, 150);
	add_other_textures(root, "resource/texture/kick2.xpm", 446, 150);
	add_other_textures(root, "resource/texture/kick3.xpm", 446, 150);
	add_other_textures(root, "resource/texture/kick4.xpm", 446, 150);
	add_other_textures(root, "resource/texture/kick5.xpm", 446, 150);
	add_other_textures(root, "resource/texture/punch1.xpm", 446, 150);
	add_other_textures(root, "resource/texture/punch2.xpm", 446, 150);
	add_other_textures(root, "resource/texture/punch3.xpm", 446, 150);
	add_other_textures(root, "resource/texture/punch4.xpm", 446, 150);
	add_other_textures(root, "resource/texture/punch5.xpm", 446, 150);
}

void	draw_helmet(t_root *root, void *overlay_img)
{
	root->hud->y = -1;
	if (!root->hud->show_helmet || !root->hud->show_hud)
		return ;
	root->hud->overlay_data = mlx_get_data_addr(overlay_img, &root->hud->bpp,
			&root->hud->sl, &root->hud->endian);
	root->hud->main_data = mlx_get_data_addr(root->img, &root->hud->bpp, &root
			->hud->sl, &root->hud->endian);
	while (++root->hud->y < HEIGHT)
	{
		root->hud->x = -1;
		draw_hud_win(root);
	}
}

void	draw_kick(t_root *root, int i)
{
	t_draw_anim	anim;

	root->hud->y = -1;
	anim.offset_x = 1100;
	anim.offset_y = 460;
	root->hud->main_data = mlx_get_data_addr(root->img, &root->hud->bpp,
			&root->hud->sl, &root->hud->endian);
	root->hud->overlay_data = mlx_get_data_addr(root->texture[i]->img,
			&anim.tex_bpp, &anim.tex_sl, &anim.tex_endian);
	while (++root->hud->y < root->texture[i]->height)
	{
		anim.dst_y = anim.offset_y + root->hud->y;
		if (anim.dst_y >= HEIGHT)
			continue ;
		root->hud->x = -1;
		draw_in_offset(root, &anim, i);
	}
}

void	draw_anim(t_root *root)
{
	int	i;
	int	limiter;

	if (!root->hud->hotbar)
		root->hud->hotbar = 6;
	if (root->hud->hotbar == 6)
		limiter = 10;
	else
		limiter = 15;
	i = root->hud->hotbar - 1;
	while (root->texture[++i] && i <= limiter)
		draw_kick_punch(root, i);
	while (--i >= root->hud->hotbar)
		draw_kick_punch(root, i);
}
