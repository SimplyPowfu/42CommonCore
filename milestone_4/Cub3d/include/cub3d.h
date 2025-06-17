/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:36:21 by glancell          #+#    #+#             */
/*   Updated: 2025/06/17 17:47:42 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "utils.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include <X11/keysymdef.h>
# include <X11/keysym.h>
# include <math.h>
# include <sys/time.h>

typedef struct s_texture
{
	t_img	*img;
	int		width;
	int		height;
	char	*path;
	char	direction;
	int		*data;
}	t_texture;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	move_speed;
	double	rot_speed;
}	t_player;

// raycasting struct i use this to draw the rays for the engine
typedef struct s_ray
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		tex_num;
	double	wall_x;
	int		tex_x;
	double	step;
	double	tex_pos;
}	t_ray;

// handle camera and view because to ortate in the space i kneed them
typedef struct s_map
{
	char		**map;
	int			width;
	int			height;
	char		view;
	int			**door_state;
	t_env		*floor;
	t_env		*sky;
	t_player	*player;
}	t_map;

typedef struct s_hud
{
	char	*text;
	int		show_hud;
	int		show_minimap;
	int		show_helmet;
	int		x;
	int		y;
	int		color;
	char	*overlay_data;
	char	*main_data;
	int		bpp;
	int		sl;
	int		endian;
	int		hotbar;
}	t_hud;

// updated root to discuss with Enrico
typedef struct s_root
{
	void		*mlx;
	void		*mlx_win;
	t_map		*map;
	t_texture	**texture;
	t_img		*img;
	t_hud		*hud;
	int			*data;
	int			bpp;
	int			size_line;
	int			endian;
	int			mouse_prev_x;
	int			is_raytracing;
}	t_root;

typedef struct s_keymap
{
	int		key_code;
	int		(*func)(t_root *);
}	t_keymap;

// Parsing
int		is_valid(t_root *root, int argc, char *argv);
int		take_texture(t_root *root, char *path);
int		take_env(t_root *root, char *path);
int		take_texture_path(t_root *root, char *path, int i, char dir);
int		validate_texture(t_root *root);
int		validate_map(t_root *root);
void	take_player(t_root *root, int x, int y);

// Raycasting
void	init_render(t_root *root);
void	init_ray(t_root *root, t_ray *ray, int x);
void	cast_rays(t_root *root);
void	render_frame(t_root *root);
void	draw_vertical_line(t_root *root, int x, t_ray *ray);

//minimap utils
void	draw_tile(t_root *root, int map_x, int map_y, int color);

// Key Binding
int		key_press(int keycode, void *param);
int		mv_forward(t_root *root);
int		mv_backward(t_root *root);
int		mv_left(t_root *root);
int		mv_right(t_root *root);
int		rotate_left(t_root *root);
int		rotate_right(t_root *root);
int		mouse_move(int x, int y, t_root *root);
int		toggle_hud(t_root *root);
int		toggle_minimap(t_root *root);
int		toggle_helmet(t_root *root);
int		toggle_raytracing(t_root *root);
void	draw_minimap(t_root *root);
int		hotbar1(t_root *root);
int		hotbar2(t_root *root);

// Calc-utils
void	calculate_delta_dist(t_ray *ray);
void	calculate_step_and_side_dist_x(t_root *root, t_ray *ray);
void	calculate_step_and_side_dist_y(t_root *root, t_ray *ray);
void	calculate_wall_distance(t_root *root, t_ray *ray);
void	calculate_line_height(t_ray *ray);
void	determine_texture(t_root *root, t_ray *ray);

// Utils
void	ft_usleep(long milliseconds);
int		validate_color(t_env *env, char *path);
int		validate_number(t_env *env, char *result, int *color);
int		validate_text(char *dir);
int		is_valid_texture(t_root *root, char *path, int *i);
int		validate_header(t_root *root);
int		validate_char(t_root *root, char **map);
void	read_map(t_root *root, char *argv);
int		is_wall(t_root *root, int i, int j);
void	shift_arg(t_root *root, int i);
int		is_first_char(char **map, int row, int direction);
void	padding_map(t_root *root);
void	sort_texture(t_root *root);
void	draw_kick(t_root *root, int i);
void	draw_kick_punch(t_root *root, int i);
void	draw_in_offset(t_root *root, t_draw_anim *anim, int i);
void	draw_hud_win(t_root *root);
int		slash_n_map(t_root *root);
int		count_comma(char *path);

//HUD
void	add_texture(t_root *root);
void	add_other_textures(t_root *root, char *path, int height, int width);
void	draw_helmet(t_root *root, void *overlay_img);
void	draw_anim(t_root *root);

// Free
void	free_all(t_root *root);
int		close_window(t_root *root);

#endif
