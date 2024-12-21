#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include "mlx/mlx_int.h"
# include "libft/libft.h"
# include <stdlib.h>
# include <X11/keysymdef.h>
# include <X11/keysym.h> //macro tasti tastiera (LINUX)

typedef struct s_coord
{
	int				x;
	int				y;
}	t_coord;

typedef struct s_game //gestione del gioco e posizioni degli sprites
{
	int				**map;
	int				height;
	int				width;
	t_coord			player;
	int				player_up;
	int				player_down;
	int				player_left;
	int				player_right;
	int				player_move;
	int				player_coll;
	t_coord			exit;
	t_coord			*coll;
	int				count_coll;
	int				count_exit;
	int				count_player;
}	t_game;

typedef struct s_root //inizializzazioni texture
{
	void			*mlx;
	void			*mlx_win;
	t_img			*mlx_img;
	t_img			*player; //contadino
	t_img			*exit; //scala
	t_img			*coll; //carota
	t_img			*wall; //albero
	t_img			*ground; //erba
}	t_root;

void	texture_init(t_root *root);
void *put_map(char **map, char *filename);

#endif