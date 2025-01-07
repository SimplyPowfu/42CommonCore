/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:16:28 by ecarbona          #+#    #+#             */
/*   Updated: 2025/01/07 14:24:30 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	close_window(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

int	move_player(t_game *game, int new_y, int new_x)
{
	if (game->map[new_y][new_x] == '1')
		return (0);
	if (game->map[new_y][new_x] == 'N')
		exit(0);
	if (game->map[new_y][new_x] == 'C')
		game->score++;
	if (game->map[new_y][new_x] == 'E')
	{
		if (game->score == game->tot_score)
		{
			ft_printf("Hai Vinto!\n");
			exit(0);
		}
		return (0);
	}
	game->move++;
	game->map[game->player_y][game->player_x] = '0';
	game->player_y = new_y;
	game->player_x = new_x;
	game->map[new_y][new_x] = 'P';
	game->idle = 1;
	game->step_timer = 115;
	return (1);
}

void	take_map(t_game *game, char *filename)
{
	char	*maps[100];
	int		y;
	int		x;

	put_map_bonus(maps, filename);
	y = 0;
	x = 0;
	while (maps[y])
		y++;
	while (maps[0][x])
		x++;
	game->map = ft_calloc(y * sizeof(char *));
	y = 0;
	while (maps[y])
	{
		game->map[y] = ft_calloc(x);
		ft_strlcpy(game->map[y], maps[y], x);
		y++;
	}
	game->map[y] = NULL;
	take_p_bonus(game);
	game->width = (x - 1) * 40;
	game->height = y * 40;
}

int	key_press(int keycode, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keycode == XK_Escape)
		exit(0);
	if (keycode == XK_w)
		move_player(game, game->player_y - 1, game->player_x);
	if (keycode == XK_s)
		move_player(game, game->player_y + 1, game->player_x);
	if (keycode == XK_a)
		move_player(game, game->player_y, game->player_x - 1);
	if (keycode == XK_d)
		move_player(game, game->player_y, game->player_x + 1);
	put_in_loop(game->root, game);
	return (0);
}

int	main(int argc, char **argv)
{
	t_root	root;
	t_game	game;

	if (argc != 2)
		return (write(1, "Invalid Argument\n", 17), 1);
	if (!is_valid_bonus(argv[1]))
		return (write(1, "Invalid Maps\n", 13), 1);
	take_map(&game, argv[1]);
	root = (t_root){0};
	game.score = 0;
	game.move = 0;
	game.idle = 0;
	game.step_timer = 0;
	root.mlx = mlx_init();
	root.mlx_win = mlx_new_window(root.mlx, game.width,
			game.height, "Bonus");
	game.root = &root;
	texture_init(&root);
	put_in_loop(&root, &game);
	mlx_hook(root.mlx_win, 17, 0, close_window, NULL);
	mlx_key_hook(root.mlx_win, key_press, &game);
	mlx_loop_hook(root.mlx, update, &game);
	mlx_loop(root.mlx);
	ft_free_maps_bonus(game.map);
}
