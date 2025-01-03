#include "so_long.h"

// Funzione chiamata per chiudere la finestra
int close_window(void *param)
{
    (void)param;
    exit(0);
    return (0);
}

// Funzione chiamata per gestire i tasti premuti
int key_press(int keycode, void *param)
{
    (void)param;
    if (keycode == XK_Escape)
        exit(0);
    return (0);
}

void put_ground(t_root *root, int width, int height)
{
    int x;
    int y;

    x = 0;
    y = 0;
    while (y < height)
    {
        while (x < width)
        {
            mlx_put_image_to_window(root->mlx, root->mlx_win, root->ground, x, y);
            x += 40;
        }
        y += 40;
        x = 0;
    }
}

void	take_map(t_game *game, char *filename)
{
	char	*maps[100];
	int	i;

	put_map(maps, filename);
	game->map = maps;
    i = 0;
	while (maps[0][i])
		i++;
	game->width = (i - 1) * 40;
	i = 0;
	while (maps[i])
		i++;
	game->height = i * 40;
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
    put_ground(&root, game.width, game.height);
    mlx_put_image_to_window(root.mlx, root.mlx_win, root.player, 40, 40);
    mlx_loop(root.mlx);
}
