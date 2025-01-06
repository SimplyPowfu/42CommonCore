#include "so_long.h"

static void	texture_load(t_root *root, t_img **img, char *path)
{
	int	width;
	int	height;

	*img = mlx_xpm_file_to_image(root->mlx, path, &width, &height);
	(*img)->width = width;
	(*img)->height = height;
}

void	texture_init(t_root *root)
{
	texture_load(root, &root->player, "./textures/player.xpm");
	texture_load(root, &root->playerM, "./textures/playerMove.xpm");
    texture_load(root, &root->enemy, "./textures/enemy.xpm");
	texture_load(root, &root->exit, "./textures/key.xpm");
	texture_load(root, &root->coll, "./textures/coin.xpm");
	texture_load(root, &root->wall, "./textures/wall.xpm");
	texture_load(root, &root->ground, "./textures/sand.xpm");
}

void	put_map_with_textures(t_root *root, t_game *game)
{
    int y;
	int x;

	y = 0;
    while ((y * 40) < game->height)
    {
		x = 0;
        while ((x * 40) < game->width)
        {
            if (game->map[y][x] == '1')
                mlx_put_image_to_window(root->mlx, root->mlx_win, root->wall, x * 40, y * 40);
            else if (game->map[y][x] == 'C')
                mlx_put_image_to_window(root->mlx, root->mlx_win, root->coll, x * 40, y * 40);
            else if (game->map[y][x] == 'P')
                mlx_put_image_to_window(root->mlx, root->mlx_win, root->player, x * 40, y * 40);
            else if (game->map[y][x] == 'E')
                mlx_put_image_to_window(root->mlx, root->mlx_win, root->exit, x * 40, y * 40);
            else if (game->map[y][x] == 'N')
                mlx_put_image_to_window(root->mlx, root->mlx_win, root->enemy, x * 40, y * 40);
			else
                mlx_put_image_to_window(root->mlx, root->mlx_win, root->ground, x * 40, y * 40);
			x++;
        }
		y++;
    }
}
