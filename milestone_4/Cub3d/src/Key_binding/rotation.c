/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glancell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 23:40:13 by glancell          #+#    #+#             */
/*   Updated: 2025/06/10 11:54:51 by glancell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	rotate_left(t_root *root)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = root->map->player->dir_x;
	root->map->player->dir_x = root->map->player->dir_x
		* cos(root->map->player->rot_speed) - root->map->player->dir_y
		* sin(root->map->player->rot_speed);
	root->map->player->dir_y = old_dir_x * sin(root->map->player->rot_speed)
		+ root->map->player->dir_y * cos(root->map->player->rot_speed);
	old_plane_x = root->map->player->plane_x;
	root->map->player->plane_x = root->map->player->plane_x
		* cos(root->map->player->rot_speed) - root->map->player->plane_y
		* sin(root->map->player->rot_speed);
	root->map->player->plane_y = old_plane_x
		* sin(root->map->player->rot_speed)
		+ root->map->player->plane_y * cos(root->map->player->rot_speed);
	render_frame(root);
	return (0);
}

int	rotate_right(t_root *root)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = root->map->player->dir_x;
	root->map->player->dir_x = root->map->player->dir_x
		* cos(-root->map->player->rot_speed) - root->map->player->dir_y
		* sin(-root->map->player->rot_speed);
	root->map->player->dir_y = old_dir_x * sin(-root->map->player->rot_speed)
		+ root->map->player->dir_y * cos(-root->map->player->rot_speed);
	old_plane_x = root->map->player->plane_x;
	root->map->player->plane_x = root->map->player->plane_x
		* cos(-root->map->player->rot_speed) - root->map->player->plane_y
		* sin(-root->map->player->rot_speed);
	root->map->player->plane_y = old_plane_x
		* sin(-root->map->player->rot_speed)
		+ root->map->player->plane_y * cos(-root->map->player->rot_speed);
	render_frame(root);
	return (0);
}

static void	apply_player_rotation(t_root *root, double rot_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = root->map->player->dir_x;
	root->map->player->dir_x = root->map->player->dir_x * cos(rot_speed)
		- root->map->player->dir_y * sin(rot_speed);
	root->map->player->dir_y = old_dir_x * sin(rot_speed)
		+ root->map->player->dir_y * cos(rot_speed);
	old_plane_x = root->map->player->plane_x;
	root->map->player->plane_x = root->map->player->plane_x * cos(rot_speed)
		- root->map->player->plane_y * sin(rot_speed);
	root->map->player->plane_y = old_plane_x * sin(rot_speed)
		+ root->map->player->plane_y * cos(rot_speed);
}

int	mouse_move(int x, int y, t_root *root)
{
	static int		last_x = -1;
	static double	smoothed_delta = 0;
	double			delta_x;
	double			rot_speed;

	(void)y;
	if (last_x == -1)
	{
		last_x = x;
		return (0);
	}
	delta_x = x - last_x;
	last_x = x;
	if (fabs(delta_x) < MOUSE_DEADZONE)
		return (0);
	smoothed_delta = smoothed_delta * (1.0 - MOUSE_SMOOTHING)
		+ delta_x * MOUSE_SMOOTHING;
	rot_speed = smoothed_delta * MOUSE_SENSITIVITY;
	rot_speed = fmax(-MAX_ROTATION, fmin(MAX_ROTATION, rot_speed));
	apply_player_rotation(root, rot_speed);
	render_frame(root);
	return (0);
}
