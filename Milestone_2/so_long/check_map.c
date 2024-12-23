#include "so_long.h"

static int is_simm(char **map, int l, int *i, int *j)
{
	int	r;

	r = 0;
	while (map[*i][*j] && map[*i][*j] != '\n')
		(*j)++;
	r = *j;
	while (*i < l) //
	{
		*j = 0;
		while (map[*i][*j] && map[*i][*j] != '\n')
			(*j)++;
		if (r != *j)
			return (0);
		(*i)++;
	}
	return (1);
}

int check_wall(char **map, int l)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (is_simm(map, l, &i, &j) == 0)
		return (0);
	j = 0;
	i--;
	while (map[0][j] && map[0][j] != '\n')
	{
		if (map[0][j] != '1'|| map[i][j] != '1' )
			return (0);
		j++;
	}
	i = 0;
	j--;
	while (i < l) //
	{
		if (map[i][0] != '1' || map[i][j] != '1')
			return (0);
		i++;
	}
	return (1);
}

// int main() {
// 	int l = 3;
//     char *matrice[3] = {
//         "1111111111111",
//         "1EP00000000C1",
//         "1111111111111"
//     };

// 	printf("%d\n", check_wall(matrice, l));
//     return 0;
// }