/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 18:05:20 by glancell          #+#    #+#             */
/*   Updated: 2025/06/14 13:18:32 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	mv_forward(t_root *root)
{
	int	new_x;
	int	new_y;

	new_x = (int)(root->map->player->pos_x
			+ root->map->player->dir_x * root->map->player->move_speed);
	new_y = (int)(root->map->player->pos_y
			+ root->map->player->dir_y * root->map->player->move_speed);
	if (root->map->map[new_x][(int)(root->map->player->pos_y)] == '0'
		|| (root->map->map[new_x][(int)(root->map->player->pos_y)] == 'P'
		&& root->map->door_state[new_x][(int)(root->map->player->pos_y)] == 1))
		root->map->player->pos_x += root->map->player->dir_x
			* root->map->player->move_speed;
	if (root->map->map[(int)(root->map->player->pos_x)][new_y] == '0'
		|| (root->map->map[(int)(root->map->player->pos_x)][new_y] == 'P'
		&& root->map->door_state[(int)(root->map->player->pos_x)][new_y] == 1))
		root->map->player->pos_y += root->map->player->dir_y
			* root->map->player->move_speed;
	render_frame(root);
	return (0);
}

int	mv_backward(t_root *root)
{
	int	new_x;
	int	new_y;

	new_x = (int)(root->map->player->pos_x
			- root->map->player->dir_x * root->map->player->move_speed);
	new_y = (int)(root->map->player->pos_y
			- root->map->player->dir_y * root->map->player->move_speed);
	if (root->map->map[new_x][(int)(root->map->player->pos_y)] == '0'
		|| (root->map->map[new_x][(int)(root->map->player->pos_y)] == 'P'
		&& root->map->door_state[new_x][(int)(root->map->player->pos_y)] == 1))
		root->map->player->pos_x -= root->map->player->dir_x
			* root->map->player->move_speed;
	if (root->map->map[(int)(root->map->player->pos_x)][new_y] == '0'
		|| (root->map->map[(int)(root->map->player->pos_x)][new_y] == 'P'
		&& root->map->door_state[(int)(root->map->player->pos_x)][new_y] == 1))
		root->map->player->pos_y -= root->map->player->dir_y
			* root->map->player->move_speed;
	render_frame(root);
	return (0);
}

int	mv_left(t_root *root)
{
	int	new_x;
	int	new_y;

	new_x = (int)(root->map->player->pos_x
			- root->map->player->dir_y * root->map->player->move_speed);
	new_y = (int)(root->map->player->pos_y
			+ root->map->player->dir_x * root->map->player->move_speed);
	if (root->map->map[new_x][(int)(root->map->player->pos_y)] == '0'
		|| (root->map->map[new_x][(int)(root->map->player->pos_y)] == 'P'
		&& root->map->door_state[new_x][(int)(root->map->player->pos_y)] == 1))
		root->map->player->pos_x -= root->map->player->dir_y
			* root->map->player->move_speed;
	if (root->map->map[(int)(root->map->player->pos_x)][new_y] == '0'
		|| (root->map->map[(int)(root->map->player->pos_x)][new_y] == 'P'
		&& root->map->door_state[(int)(root->map->player->pos_x)][new_y] == 1))
		root->map->player->pos_y += root->map->player->dir_x
			* root->map->player->move_speed;
	render_frame(root);
	return (0);
}

int	mv_right(t_root *root)
{
	int	new_x;
	int	new_y;

	new_x = (int)(root->map->player->pos_x
			+ root->map->player->dir_y * root->map->player->move_speed);
	new_y = (int)(root->map->player->pos_y
			- root->map->player->dir_x * root->map->player->move_speed);
	if (root->map->map[new_x][(int)(root->map->player->pos_y)] == '0'
		|| (root->map->map[new_x][(int)(root->map->player->pos_y)] == 'P'
		&& root->map->door_state[new_x][(int)(root->map->player->pos_y)] == 1))
		root->map->player->pos_x += root->map->player->dir_y
			* root->map->player->move_speed;
	if (root->map->map[(int)(root->map->player->pos_x)][new_y] == '0'
		|| (root->map->map[(int)(root->map->player->pos_x)][new_y] == 'P'
		&& root->map->door_state[(int)(root->map->player->pos_x)][new_y] == 1))
		root->map->player->pos_y -= root->map->player->dir_x
			* root->map->player->move_speed;
	render_frame(root);
	return (0);
}
