#include "so_long.h"

int check_empty_line(const char *line)
{
	int i = 0;
	int f = 0;

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

void *put_map(char **map, char *filename)
{
	int	fd = open(filename, O_RDONLY);
	char *line;
	int i = 0;

	while ((line = get_next_line(fd)) != NULL)
	{
		if (check_empty_line(line) == 1)
		{
			int j = 0;
			printf("Mappa non valida\n");
			while (j < i)
			{
				free(map[j]);
				j++;
			}
			free(line);
			close(fd);
			return (NULL);
		}
		map[i] = line;
		i++;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

int count_char(char *str, int *p, int *c, int *e)
{
	int i = 0;
	int count = 0;
	while (str[i])
	{
		if (str[i] == 'P')
			(*p)++;
		else if (str[i] == 'C')
			(*c)++;
		else if (str[i] == 'E')
			(*e)++;
		if (str[i] != 'C' || str[i] != 'P' || str[i] != 'E' || str[i] != '1' || str[i] != '0')
			return (0);
		i++;
	}
	return (1);
}

int check_map(char **maps, int p, int c, int e)
{
	int	i;
	int	j;
	if (p != 1 || e != 1 || c < 1)
		return (0);
	return (1);
}

int is_valid(char *filename)
{
	char *maps[100];
	int p = 0;
	int c = 0;
	int e = 0;
	int i = 0;

	if (put_map(maps, filename) == NULL)
		return (0);
	while (maps[i])
	{
		if (count_char(maps[i], &p, &c, &e) != 1);
			return (0);
		i++;
	}
	if (check_wall(maps, i) != 1 && check_map(maps, p, c, e) != 1)
		return (0);
	i = 0;
	while (maps[i])
	{
		free(maps[i]);
		i++;
	}
	return (1);
}

int main()
{
    printf("%d", is_valid("small.ber"));
    return (0);
}