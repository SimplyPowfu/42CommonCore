/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:22:09 by ecarbona          #+#    #+#             */
/*   Updated: 2025/02/01 11:56:52 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_free(void **tab, int wrld)
{
	while (wrld >= 0)
		free(tab[wrld--]);
	free(tab);
}

int check_args(char *matr)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (matr[i])
	{
		if (matr[i] >= '0' && matr[i] <= '9')
		{
			n++;
			i++;
		}
		else if (matr[i] == ' ' || matr[i] == '-' || matr[i] == '+')
			i++;
		else
			return (ft_printf("Only numbers, "), 0);
	}
	return (n);
}

int	put_args(int argc, char **argv, t_list *a, t_list *b)
{
	int		i = 1;
	int		size = 0;
	char	**mat;

	while (i < argc)
	{
		if (!check_args(argv[i]))
			return (0);
		size += check_args(argv[i]);
		i++;
	}
	a[size + 1].content = NULL;
	if (argc == 2)
	{
		mat = ft_split(argv[1],' ');
		i = 0;
		while (mat[i])
		{
			a[i].content = (void *)(intptr_t)ft_atoi(mat[i]);
			ft_printf("%d\n", a[i].content);
			i++;
		}
		ft_free((void **)mat, size);
	}
	else
		ft_printf("more arguments\n");
	return (1);
}

int main(int argc, char **argv)
{
	t_list	stack_a;
	t_list	stack_b;

	if (argc < 2 || !put_args(argc, argv, &stack_a, &stack_b))
		return (ft_printf("Error\n"),1);
	return (0);
}
