/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glancell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 17:47:42 by glancell          #+#    #+#             */
/*   Updated: 2025/06/10 13:33:56 by glancell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_line(t_root *root, int px, int py, t_line *line)
{
	line->end_x = px + (int)(root->map->player->dir_y
			* MINIMAP_TILE_SIZE * 1.5);
	line->end_y = py + (int)(root->map->player->dir_x
			* MINIMAP_TILE_SIZE * 1.5);
	line->dx = abs(line->end_x - px);
	line->dy = -abs(line->end_y - py);
	line->err = line->dx + line->dy;
	if (px < line->end_x)
		line->sx = 1;
	else
		line->sx = -1;
	if (py < line->end_y)
		line->sy = 1;
	else
		line->sy = -1;
}

static void	update_line_position(t_line *line)
{
	line->e2 = 2 * line->err;
	if (line->e2 >= line->dy)
	{
		line->err += line->dy;
		line->px += line->sx;
	}
	if (line->e2 <= line->dx)
	{
		line->err += line->dx;
		line->py += line->sy;
	}
}

static void	draw_direction(t_root *root, int px, int py)
{
	t_line	line;

	line.px = px;
	line.py = py;
	init_line(root, px, py, &line);
	while (1)
	{
		if (line.px >= MINIMAP_MARGIN && line.px < WIDTH - MINIMAP_MARGIN
			&& line.py >= MINIMAP_MARGIN && line.py < HEIGHT - MINIMAP_MARGIN)
			root->data[line.py * WIDTH + line.px] = MINIMAP_DIR_COLOR;
		if (line.px == line.end_x && line.py == line.end_y)
			break ;
		update_line_position(&line);
	}
}

void	draw_minimap_tile(t_root *root, int x, int y, t_point *player_pos)
{
	if (root->map->map[y][x] == '1')
		draw_tile(root, x, y, MINIMAP_WALL_COLOR);
	else if (root->map->map[y][x] == '0')
		draw_tile(root, x, y, MINIMAP_FLOOR_COLOR);
	else if (root->map->map[y][x] == 'P')
	{
		if (root->map->door_state[y][x] == 0)
			draw_tile(root, x, y, MINIMAP_DOOR_CLOSED_COLOR);
		else
			draw_tile(root, x, y, MINIMAP_DOOR_OPEN_COLOR);
	}
	if (y == (int)root->map->player->pos_x
		&& x == (int)root->map->player->pos_y)
	{
		draw_tile(root, x, y, MINIMAP_PLAYER_COLOR);
		player_pos->x = MINIMAP_MARGIN + x
			* MINIMAP_TILE_SIZE + MINIMAP_TILE_SIZE / 2;
		player_pos->y = MINIMAP_MARGIN + y
			* MINIMAP_TILE_SIZE + MINIMAP_TILE_SIZE / 2;
	}
}

void	draw_minimap(t_root *root)
{
	int		y;
	int		x;
	t_point	player_pos;

	y = 0;
	player_pos.x = 0;
	player_pos.y = 0;
	if (!root->hud->show_minimap || !root->hud->show_hud)
		return ;
	while (y < root->map->height)
	{
		x = 0;
		while (x <= (int)ft_strlen(root->map->map[y]))
		{
			draw_minimap_tile(root, x, y, &player_pos);
			x++;
		}
		y++;
	}
	if (player_pos.x != 0 || player_pos.y != 0)
		draw_direction(root, player_pos.x, player_pos.y);
}
