/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:22:09 by ecarbona          #+#    #+#             */
/*   Updated: 2025/02/19 17:33:28 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_double(t_stack **a)
{
	t_stack	*stack;
	t_stack	*checker;

	stack = *a;
	while (stack)
	{
		checker = stack->next;
		while (checker)
		{
			if (stack->content == checker->content)
				return (0);
			checker = checker->next;
		}
		stack = stack->next;
	}
	return (1);
}

int	check_char(char **av)
{
	int	i;
	int	j;
	int	n;

	i = 0;
	n = 0;
	while (av[++i] != NULL)
	{
		j = -1;
		while (av[i][++j])
		{
			if ((av[i][j] < '0' || av[i][j] > '9') && av[i][j] != ' ' &&
				av[i][j] != '-' && av[i][j] != '+')
				return (ft_printf("Only numbers, "), 0);
			if (av[i][j] >= '0' && av[i][j] <= '9')
				n++;
		}
	}
	return (n);
}

int	take_numb(t_stack **a, char **mat, int *i)
{
	t_stack	*new;
	t_stack	*temp;

	new = ft_calloc(sizeof(t_stack));
	new->content = ft_atoi(mat[*i]);
	if (new->content == 0 && mat[*i][0] != '0')
		return (free(new), 0);
	new->next = NULL;
	new->before = NULL;
	if (*a == NULL)
		*a = new;
	else
	{
		temp = *a;
		while (temp->next)
			temp = temp->next;
		temp->next = new;
		new->before = temp;
	}
	if (new->next == NULL)
		(*a)->before = new;
	return (1);
}

int	put_argv(int argc, char **argv, t_stack **a)
{
	char	**mat;
	int		i;

	i = -1;
	if (argc == 2)
	{
		mat = ft_split(argv[1], ' ');
		while (mat[++i])
			if (!take_numb(a, mat, &i))
				return (ft_free(mat), 0);
		ft_free(mat);
	}
	else
	{
		i = 0;
		while (argv[++i])
			if (!take_numb(a, argv, &i))
				return (0);
	}
	if (!check_double(a))
		return (0);
	return (1);
}

void	direct_sort(t_stack **a)
{
	t_stack	*temp;

	temp = *a;
	if (temp->content > temp->next->content
		&& temp->next->content > temp->next->next->content)
	{
		sa(a, 1);
		rra(a, 1);
	}
}
