/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:00:30 by ecarbona          #+#    #+#             */
/*   Updated: 2025/01/07 13:56:37 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

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
	t_img	*mlx_img;
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
	int		score;
	int		tot_score;
	int		move;
	t_root	*root;
}	t_game;

void	texture_init(t_root *root);
void	*put_map(char **map, char *filename);
void	take_p(t_game *game);
int		is_valid(char *filename);
int		check_wall(char **map, int l);
void	ft_clean(char **map, char *line, int fd, int i);
void	ft_free_maps(char **maps);
void	put_map_with_textures(t_root *root, t_game *game);

#endif