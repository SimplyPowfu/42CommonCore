/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 15:11:28 by ecarbona          #+#    #+#             */
/*   Updated: 2025/01/07 12:54:17 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_empty_line(const char *line)
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

void	*put_map(char **map, char *filename)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(filename, O_RDONLY);
	if (fd < 1)
		return (NULL);
	i = 0;
	line = get_next_line(fd);
	if (line == NULL)
		return (NULL);
	while (line != NULL)
	{
		if (check_empty_line(line) == 1)
		{
			ft_clean(map, line, fd, i);
			return (NULL);
		}
		map[i] = line;
		i++;
		line = get_next_line(fd);
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

int	count_char(char *str, int *p, int *c, int *e)
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
			&& str[i] != '1' && str[i] != '0' && str[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int	check_map(int p, int c, int e)
{
	if (p != 1 || e != 1 || c < 1)
		return (0);
	return (1);
}

int	is_valid(char *filename)
{
	char	*maps[100];
	int		p;
	int		c;
	int		e;
	int		i;

	p = 0;
	c = 0;
	e = 0;
	if (put_map(maps, filename) == NULL)
		return (0);
	i = 0;
	while (maps[i])
	{
		if (count_char(maps[i], &p, &c, &e) != 1)
			return (0);
		i++;
	}
	if (check_wall(maps, i) != 1 || check_map(p, c, e) != 1)
		return (0);
	ft_free_maps(maps);
	return (1);
}
