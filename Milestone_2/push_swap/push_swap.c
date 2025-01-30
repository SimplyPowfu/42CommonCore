/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:22:09 by ecarbona          #+#    #+#             */
/*   Updated: 2025/01/28 17:23:18 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_numb(char *matr)
{
	int	i;

	i = 0;
	while (matr[i])
	{
		if (matr[i] >= '0' && matr[i] <= '9' && matr[i] != '\0')
			i++;
		else
			return (ft_printf("non 'e un numero"), 0);
	}
	return (1);
}

int main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;
	char	**mat;
	int i = 1;

	if (argc < 2)
		return (1);
	while (i < argc)
	{
		if (!is_numb(argv[i]))
			return (1);
		i++;
	}
	if (argc == 2)
		mat = ft_split(argv[1],' ');
	else
		ft_printf("more arguments");
	// while (mat[i])
	// {
	// 	ft_printf("%s\n", mat[i]);
	// 	i++;
	// }
	return (0);
}
