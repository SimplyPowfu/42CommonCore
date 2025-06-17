/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:22:41 by glancell          #+#    #+#             */
/*   Updated: 2025/06/14 13:33:00 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	hotbar1(t_root *root)
{
	int		x;
	int		y;

	if (root->hud->text)
		render_frame(root);
	root->hud->text = "KICK";
	x = ((WIDTH - (10 * ft_strlen(root->hud->text))) / 2);
	y = ((HEIGHT - 20) / 2);
	root->hud->hotbar = 6;
	mlx_string_put(root->mlx, root->mlx_win, x, y, 0xFFFFFF, root->hud->text);
	return (0);
}

int	hotbar2(t_root *root)
{
	int		x;
	int		y;

	if (root->hud->text)
		render_frame(root);
	root->hud->text = "PUNCH";
	x = ((WIDTH - (10 * ft_strlen(root->hud->text))) / 2);
	y = ((HEIGHT - 20) / 2);
	root->hud->hotbar = 11;
	mlx_string_put(root->mlx, root->mlx_win, x, y, 0xFFFFFF, root->hud->text);
	return (0);
}

int	kick_player(t_root *root)
{
	int	door_x;
	int	door_y;

	door_x = (int)(root->map->player->pos_x + root->map->player->dir_x);
	door_y = (int)(root->map->player->pos_y + root->map->player->dir_y);
	if (door_x >= 0 && door_x < root->map->height
		&& door_y >= 0 && door_y < (int)ft_strlen(root->map->map[door_x])
		&& root->map->map[door_x][door_y] == 'P')
	{
		if (!root->map->door_state[door_x][door_y])
			draw_anim(root);
		root->map->door_state[door_x][door_y] = !root->map->door_state[door_x]
		[door_y];
	}
	else
		draw_anim(root);
	render_frame(root);
	return (0);
}

static int	find_and_execute_action(t_root *root, int keycode,
	const t_keymap *mappings)
{
	while (mappings->func != NULL)
	{
		if (mappings->key_code == keycode)
		{
			mappings->func(root);
			return (1);
		}
		mappings++;
	}
	return (0);
}

int	key_press(int keycode, void *param)
{
	t_root			*root;
	const t_keymap	key_actions[] = {{XK_Escape, close_window},
	{XK_w, mv_forward},
	{XK_s, mv_backward},
	{XK_a, mv_left},
	{XK_d, mv_right},
	{XK_Left, rotate_left},
	{XK_Right, rotate_right},
	{XK_F1, toggle_hud}, {XK_m, toggle_minimap}, {XK_h, toggle_helmet},
	{XK_e, kick_player}, {XK_1, hotbar1}, {XK_2, hotbar2},
	{XK_F2, toggle_raytracing},
	{0, NULL}
	};

	root = (t_root *)param;
	find_and_execute_action(root, keycode, key_actions);
	return (0);
}
