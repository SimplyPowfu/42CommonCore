/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_map_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 15:11:28 by ecarbona          #+#    #+#             */
/*   Updated: 2025/01/08 16:57:18 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_empty_line_bonus(const char *line)
{
	int	i;
	int	f;

	i = 0;
	f = 0;
	if (line[i] == '\n')
		return (1);
	while (line[i])
	{
		if (line[i] == ' ' || line[i] == '\t')
			f = 1;
		i++;
	}
	if (f == 0)
		return (0);
	else
		return (1);
}

void	*put_map_bonus(char **map, char *filename)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(filename, O_RDONLY);
	if (fd < 1)
		return (NULL);
	i = -1;
	line = get_next_line(fd);
	if (line == NULL)
		return (NULL);
	while (line != NULL)
	{
		if (check_empty_line_bonus(line) == 1)
		{
			ft_clean_bonus(map, line, fd, ++i);
			return (NULL);
		}
		map[++i] = line;
		line = get_next_line(fd);
	}
	map[++i] = NULL;
	free(line);
	close(fd);
	return (map);
}

int	count_char_bonus(char *str, int *p, int *c, int *e)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'P')
			(*p)++;
		else if (str[i] == 'C')
			(*c)++;
		else if (str[i] == 'E')
			(*e)++;
		if (str[i] != 'C' && str[i] != 'P' && str[i] != 'E'
			&& str[i] != '1' && str[i] != '0' && str[i] != '\n'
			&& str[i] != 'N')
			return (0);
		i++;
	}
	return (1);
}

int	check_map_bonus(int p, int c, int e)
{
	if (p != 1 || e != 1 || c < 1)
		return (0);
	return (1);
}

int	is_valid_bonus(char *filename)
{
	char	**maps;
	int		p;
	int		c;
	int		e;
	int		i;

	p = 0;
	c = 0;
	e = 0;
	maps = (char **)malloc(100 * sizeof(char *));
	if (!maps)
		return (ft_free_maps_bonus(maps), 0);
	if (put_map_bonus(maps, filename) == NULL)
		return (ft_free_maps_bonus(maps), 0);
	i = -1;
	while (maps[++i])
	{
		if (count_char_bonus(maps[i], &p, &c, &e) != 1)
			return (ft_free_maps_bonus(maps), 0);
	}
	if (check_wall_bonus(maps, i) != 1 || check_map_bonus(p, c, e) != 1)
		return (ft_free_maps_bonus(maps), 0);
	ft_free_maps_bonus(maps);
	return (1);
}

// int main()
// {
//     printf("%d", is_valid_bonus("maps/valid/bons/small.ber"));
//     return (0);
// }