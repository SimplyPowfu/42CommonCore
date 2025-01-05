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
	int		x;
	int		y;
}	t_coord;

typedef struct s_game //gestione del gioco e posizioni degli sprites
{
	char	**map;
	int		height;
	int		width;
	int		player_x;
	int		player_y;
	int		score;
}	t_game;

typedef struct s_root //inizializzazioni texture
{
	void	*mlx;
	void	*mlx_win;
	t_img	*mlx_img;
	t_img	*player; //contadina
	t_img	*playerM; //contadina passo
	t_img	*exit; //scala
	t_img	*coll; //carota
	t_img	*wall; //albero
	t_img	*ground; //erba
}	t_root;

void	texture_init(t_root *root);
void	*put_map(char **map, char *filename);
int		is_valid(char *filename);
int		check_wall(char **map, int l);
void	ft_clean(char **map, char *line, int fd, int i);
void	ft_free_maps(char **maps);
void	put_ground(t_root *root, t_game *game);
void	put_map_with_textures(t_root *root, t_game *game, char *filename);

#endif