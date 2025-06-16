/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 15:52:26 by ecarbona          #+#    #+#             */
/*   Updated: 2025/06/13 23:20:45 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#include <sys/time.h>

void	ft_usleep(long milliseconds)
{
	struct timeval	start;
	struct timeval	current;
	long			elapsed;

	gettimeofday(&start, NULL);
	gettimeofday(&current, NULL);
	elapsed = (current.tv_sec - start.tv_sec) * 1000L
		+ (current.tv_usec - start.tv_usec) / 1000L;
	while (elapsed < milliseconds)
	{
		gettimeofday(&current, NULL);
		elapsed = (current.tv_sec - start.tv_sec) * 1000L
			+ (current.tv_usec - start.tv_usec) / 1000L;
	}
}

void	shift_arg(t_root *root, int i)
{
	int	j;
	int	finish;

	if (!root->map->map[i + 1])
	{
		free(root->map->map[i]);
		root->map->map[i] = NULL;
		return ;
	}
	finish = 0;
	while (root->map->map[finish])
		finish++;
	free(root->map->map[i]);
	j = i;
	while (j < finish)
	{
		root->map->map[j] = root->map->map[j + 1];
		j++;
	}
	root->map->map[j] = NULL;
	root->map->height--;
}

void	init_player(t_root *root, int x, int y)
{
	root->map->player = ft_calloc(1, sizeof(t_player));
	if (!root->map->player)
		return ;
	root->map->view = root->map->map[x][y];
	root->map->map[x][y] = '0';
	root->map->player->pos_x = x;
	root->map->player->pos_y = y;
	root->map->player->move_speed = 0.05;
	root->map->player->rot_speed = 0.05;
}

void	take_player(t_root *root, int x, int y)
{
	init_player(root, x, y);
	if (root->map->view == 'N')
	{
		root->map->player->dir_x = -1;
		root->map->player->plane_y = 0.66;
	}
	else if (root->map->view == 'S')
	{
		root->map->player->dir_x = 1;
		root->map->player->plane_y = -0.66;
	}
	else if (root->map->view == 'E')
	{
		root->map->player->dir_y = 1;
		root->map->player->plane_x = 0.66;
	}
	else if (root->map->view == 'W')
	{
		root->map->player->dir_y = -1;
		root->map->player->plane_x = -0.66;
	}
}

int	is_first_char(char **map, int row, int direction)
{
	int	i;

	i = 0;
	if (direction == 1)
	{
		while (map[row][i] == ' ')
			i++;
	}
	else
	{
		while (map[row][i])
			i++;
		i--;
		while (map[row][i] == ' ')
			i--;
	}
	return (i);
}
