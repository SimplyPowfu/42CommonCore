#include "so_long.h"

int close_window(void *param)
{
    (void)param;
    exit(0);
    return (0);
}

int key_press(int keycode, void *param)
{
    (void)param;
    if (keycode == XK_Escape)
        exit(0);
    return (0);
}

void	take_map(t_game *game, char *filename)
{
	char	*maps[100];
	int	y;
    int x;

	put_map(maps, filename);
	game->map = maps;
    y = 0;
	while (maps[y])
	{
        x = 0;
        while (maps[y][x])
		{
            if (maps[y][x] == 'P')
            {
                game->player_x = x;
                game->player_y = y;
            }
            x++;
        }
        y++;
    }
	game->width = (x - 1) * 40;
	game->height = y * 40;
}

int main(int argc, char **argv)
{
	t_root	root;
	t_game	game;

	if (argc != 2)
		return (write(1, "Invalid Argument\n", 17), 1);
	if (!is_valid(argv[1]))
		return (write(1, "Invalid Maps\n", 13), 1);
	take_map(&game, argv[1]);
	root = (t_root){0};
	root.mlx = mlx_init();
	root.mlx_win = mlx_new_window(root.mlx, game.width, game.height, "Finestra Test");
    mlx_hook(root.mlx_win, 17, 0, close_window, NULL);
    mlx_key_hook(root.mlx_win, key_press, NULL);
	texture_init(&root);
    put_ground(&root, &game);
    put_map_with_textures(&root, &game, argv[1]);//uno su mille non va in core dump

    mlx_loop(root.mlx);
}
