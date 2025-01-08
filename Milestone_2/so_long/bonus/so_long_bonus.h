/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:00:30 by ecarbona          #+#    #+#             */
/*   Updated: 2025/01/08 01:38:47 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <X11/keysymdef.h>
# include <X11/keysym.h> //macro tasti tastiera (LINUX)
# define PUT_IM mlx_put_image_to_window

typedef struct s_root //inizializzazioni texture
{
	void	*mlx;
	void	*mlx_win;
	t_img	*player; //contadina
	t_img	*player_m; //contadina passo
	t_img	*enemy; //slime ball
	t_img	*exit; //scala
	t_img	*coll; //carota
	t_img	*wall; //albero
	t_img	*ground; //erba
}	t_root;

typedef struct s_game //gestione del gioco e posizioni degli sprites
{
	char	**map;
	int		height;
	int		width;
	int		player_x;
	int		player_y;
	int		idle; //se 1 movimento se 0 idle
	int		step_timer;
	int		score;
	int		tot_score;
	int		move;
	t_root	*root;
}	t_game;

void	texture_init(t_root *root);
void	*put_map_bonus(char **map, char *filename);
void	take_p_bonus(t_game *game);
int		is_valid_bonus(char *filename);
int		check_wall_bonus(char **map, int l);
void	ft_clean_bonus(char **map, char *line, int fd, int i);
void	ft_free_maps_bonus(char **maps);
void	put_in_loop(t_root *root, t_game *game);
int		update(void *param);
void	free_all(t_root *root, t_game *game);

#endif