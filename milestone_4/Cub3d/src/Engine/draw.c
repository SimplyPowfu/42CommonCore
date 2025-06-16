/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 13:33:38 by glancell          #+#    #+#             */
/*   Updated: 2025/06/12 20:11:54 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_tile(t_root *root, int map_x, int map_y, int color)
{
	int	pixel_x;
	int	pixel_y;
	int	y;
	int	x;

	pixel_x = MINIMAP_MARGIN + map_x * MINIMAP_TILE_SIZE;
	pixel_y = MINIMAP_MARGIN + map_y * MINIMAP_TILE_SIZE;
	y = 0;
	while (y < MINIMAP_TILE_SIZE)
	{
		x = 0;
		while (x < MINIMAP_TILE_SIZE)
		{
			if (pixel_x + x < WIDTH && pixel_y + y < HEIGHT)
				root->data[(pixel_y + y) * WIDTH + (pixel_x + x)] = color;
			x++;
		}
		y++;
	}
}

void	determine_texture(t_root *root, t_ray *ray)
{
	if (root->map->map[ray->map_x][ray->map_y] == 'P'
			&& root->map->door_state[ray->map_x][ray->map_y] == 0)
		ray->tex_num = 5;
	else
	{
		if (ray->side == 0)
		{
			if (ray->ray_dir_x > 0)
				ray->tex_num = 1;
			else
				ray->tex_num = 3;
		}
		else
		{
			if (ray->ray_dir_y > 0)
				ray->tex_num = 0;
			else
				ray->tex_num = 2;
		}
	}
}

static void	draw_wall_and_shading(t_root *root, int x, t_ray *ray)
{
	t_draw_params	p;

	p.y = ray->draw_start;
	while (p.y < ray->draw_end)
	{
		p.tex_y = (int)ray->tex_pos & (TEX_HEIGHT - 1);
		ray->tex_pos += ray->step;
		p.color = root->texture[ray->tex_num]->data[TEX_HEIGHT
			* p.tex_y + ray->tex_x];
		if (root->is_raytracing && root->hud->show_hud)
		{
			p.dist_factor = 1.0 - (ray->perp_wall_dist / 10.0);
			p.dist_factor = fmax(0.2, fmin(1.0, p.dist_factor));
			p.r = ((p.color >> 16) & 0xFF) * p.dist_factor;
			p.g = ((p.color >> 8) & 0xFF) * p.dist_factor;
			p.b = (p.color & 0xFF) * p.dist_factor;
			p.color = (p.r << 16) | (p.g << 8) | p.b;
		}
		root->data[p.y * WIDTH + x] = p.color;
		p.y++;
	}
}

void	draw_vertical_line(t_root *root, int x, t_ray *ray)
{
	int	y;

	y = 0;
	draw_wall_and_shading(root, x, ray);
	while (y < ray->draw_start)
		root->data[y++ *WIDTH + x] = root->map->sky->r << 16
			| root->map->sky->g << 8
			| root->map->sky->b;
	y = ray->draw_end;
	while (y < HEIGHT)
		root->data[y++ *WIDTH + x] = root->map->floor->r << 16
			| root->map->floor->g << 8
			| root->map->floor->b;
}
