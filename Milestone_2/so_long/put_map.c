#include "so_long.h"

int check_empty_line(const char *line)
{
    int i = 0;

    while (line[i])
    {
        if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
            return (0);
        i++;
    }
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

int main()
{
    char *maps[100];
    int i = 0;

	if (put_map(maps, "small.ber") == NULL)
        return (0);
    while (maps[i] != NULL)
    {
        printf("%s", maps[i]);
        i++;
    }
    i = 0;
    while (maps[i] != NULL)
    {
        free(maps[i]);
        i++;
    }
    return (0);
}