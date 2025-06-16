/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 22:41:13 by glancell          #+#    #+#             */
/*   Updated: 2025/06/14 13:15:01 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# define WIDTH 1600
# define HEIGHT 900
# define TEX_WIDTH 64
# define TEX_HEIGHT 64
# define MINIMAP_TILE_SIZE 10  // Size of each map tile in pixels
# define MINIMAP_MARGIN 20     // Margin from screen edges
# define MINIMAP_PLAYER_COLOR 0xFF0000  // Red
# define MINIMAP_WALL_COLOR 0xFFFFFF    // White
# define MINIMAP_FLOOR_COLOR 0x000000   // Black
# define MINIMAP_DIR_COLOR 0x00FF00 
# define MOUSE_SENSITIVITY 0.0025    // sens
# define MOUSE_DEADZONE 2            // deadzone(ignored pixel)
# define MOUSE_SMOOTHING 1//smoothing of the rotation 1 and 0(no smooth)
# define MAX_ROTATION 0.1
# define MINIMAP_DOOR_CLOSED_COLOR 0x00FFA500
# define MINIMAP_DOOR_OPEN_COLOR   0x0000FF00

typedef struct s_env
{
	int	r;
	int	g;
	int	b;
}	t_env;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

// it's for the lines of view in the minimap
typedef struct s_line
{
	int	px;
	int	py;
	int	end_x;
	int	end_y;
	int	dx;
	int	dy;
	int	err;
	int	e2;
	int	sx;
	int	sy;
}	t_line;

// this is for the drawing of the walls and for their re-shading
typedef struct s_draw_params
{
	int		y;
	int		tex_y;
	int		color;
	double	dist_factor;
	int		r;
	int		g;
	int		b;
}	t_draw_params;

typedef struct s_draw_anim
{
	int	offset_x;
	int	offset_y;
	int	tex_bpp;
	int	tex_sl;
	int	tex_endian;
	int	dst_y;
	int	dst_x;
	int	src_i;
	int	dst_i;
}	t_draw_anim;

#endif
