/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:34:23 by glancell          #+#    #+#             */
/*   Updated: 2025/06/14 12:54:14 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_frame(t_root *root)
{
	mlx_clear_window(root->mlx, root->mlx_win);
	cast_rays(root);
	draw_helmet(root, root->texture[4]->img);
	draw_minimap(root);
	mlx_put_image_to_window(root->mlx, root->mlx_win, root->img, 0, 0);
}

void	init_ray(t_root *root, t_ray *ray, int x)
{
	ray->camera_x = 2 * x / (double)WIDTH - 1;
	ray->ray_dir_x = root->map->player->dir_x
		+ root->map->player->plane_x * ray->camera_x;
	ray->ray_dir_y = root->map->player->dir_y
		+ root->map->player->plane_y * ray->camera_x;
	ray->map_x = (int)root->map->player->pos_x;
	ray->map_y = (int)root->map->player->pos_y;
}

static void	hud_init(t_root *root)
{
	root->hud->show_hud = 1;
	root->hud->show_minimap = 1;
	root->hud->show_helmet = 0;
	root->is_raytracing = 0;
}

static int	ft_mlx_window(t_root *root)
{
	root->mlx_win = mlx_new_window(root->mlx, WIDTH, HEIGHT, "cub3D");
	if (!root->mlx_win)
		return (ft_putstr_fd("Error\nWindow creation failed\n", 2),
			free(root->mlx), mlx_destroy_display(root->mlx), 1);
	mlx_clear_window(root->mlx, root->mlx_win);
	mlx_hook(root->mlx_win, 17, 0, close_window, root);
	mlx_hook(root->mlx_win, 2, 1L << 0, key_press, root);
	mlx_mouse_move(root->mlx, root->mlx_win, WIDTH / 2, HEIGHT / 2);
	mlx_hook(root->mlx_win, MotionNotify, PointerMotionMask, mouse_move, root);
	return (0);
}

int	main(int argc, char **argv)
{
	t_root	root;

	root = (t_root){0};
	root.hud = ft_calloc(1, sizeof(t_hud));
	hud_init(&root);
	root.map = ft_calloc(1, sizeof(t_map));
	if (!root.map)
		return (ft_putstr_fd("Error\nMap allocation failed\n", 2), 1);
	root.texture = ft_calloc(10, sizeof(t_texture));
	if (!root.texture)
		return (ft_putstr_fd("Error\nTexture allocation failed\n", 2),
			free(root.map), 1);
	root.mlx = mlx_init();
	root.mlx_win = NULL;
	if (!root.mlx)
		return (ft_putstr_fd("Error\nMLX initialization failed\n", 2), 1);
	if (argc != 2 || !is_valid(&root, argv[1]))
		return (free_all(&root), 1);
	if (ft_mlx_window(&root))
		return (free_all(&root), 1);
	add_texture(&root);
	init_render(&root);
	render_frame(&root);
	mlx_loop(root.mlx);
	return (free_all(&root), 0);
}
