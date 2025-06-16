/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 09:51:06 by glancell          #+#    #+#             */
/*   Updated: 2025/06/14 00:37:39 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_render0(t_root *root)
{
	root->img = mlx_new_image(root->mlx, WIDTH, HEIGHT);
	root->data = (int *)mlx_get_data_addr(root->img, &root->bpp,
			&root->size_line, &root->endian);
	root->map->player->pos_x += 0.5;
	root->map->player->pos_y += 0.5;
	root->map->player->move_speed = 0.05;
	root->map->player->rot_speed = 0.05;
	if (root->map->view == 'N')
	{
		root->map->player->dir_x = -1.1;
		root->map->player->dir_y = 0;
		root->map->player->plane_x = 0;
		root->map->player->plane_y = 0.66;
	}
	else if (root->map->view == 'S')
	{
		root->map->player->dir_x = 1.1;
		root->map->player->dir_y = 0;
		root->map->player->plane_x = 0;
		root->map->player->plane_y = -0.66;
	}
}

void	init_render(t_root *root)
{
	init_render0(root);
	if (root->map->view == 'E')
	{
		root->map->player->dir_x = 0;
		root->map->player->dir_y = 1.1;
		root->map->player->plane_x = 0.66;
		root->map->player->plane_y = 0;
	}
	else if (root->map->view == 'W')
	{
		root->map->player->dir_x = 0;
		root->map->player->dir_y = -1.1;
		root->map->player->plane_x = -0.66;
		root->map->player->plane_y = 0;
	}
}

static void	perform_dda(t_root *root, t_ray *ray)
{
	ray->hit = 0;
	while (ray->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (root->map->map[ray->map_x][ray->map_y] == '1')
			ray->hit = 1;
		else if (root->map->map[ray->map_x][ray->map_y] == 'P')
		{
			if (root->map->door_state[ray->map_x][ray->map_y] == 0)
				ray->hit = 1;
			else
				ray->hit = 0;
		}
	}
}

static void	calculate_texture_coords(t_root *root, t_ray *ray)
{
	if (ray->side == 0)
		ray->wall_x = root->map->player->pos_y
			+ ray->perp_wall_dist * ray->ray_dir_y;
	else
		ray->wall_x = root->map->player->pos_x
			+ ray->perp_wall_dist * ray->ray_dir_x;
	ray->wall_x -= floor(ray->wall_x);
	ray->tex_x = (int)(ray->wall_x * (double)TEX_WIDTH);
	if (ray->side == 0 && ray->ray_dir_x > 0)
		ray->tex_x = TEX_WIDTH - ray->tex_x - 1;
	if (ray->side == 1 && ray->ray_dir_y < 0)
		ray->tex_x = TEX_WIDTH - ray->tex_x - 1;
	ray->step = 1.0 * TEX_HEIGHT / ray->line_height;
	ray->tex_pos = (ray->draw_start - HEIGHT / 2 + ray->line_height / 2)
		* ray->step;
}

void	cast_rays(t_root *root)
{
	int		x;
	t_ray	ray;

	x = 0;
	while (x < WIDTH)
	{
		init_ray(root, &ray, x);
		calculate_delta_dist(&ray);
		calculate_step_and_side_dist_x(root, &ray);
		calculate_step_and_side_dist_y(root, &ray);
		perform_dda(root, &ray);
		calculate_wall_distance(root, &ray);
		calculate_line_height(&ray);
		determine_texture(root, &ray);
		calculate_texture_coords(root, &ray);
		draw_vertical_line(root, x, &ray);
		x++;
	}
}
