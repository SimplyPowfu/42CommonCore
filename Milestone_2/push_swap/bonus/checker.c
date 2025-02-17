/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 20:36:47 by ecarbona          #+#    #+#             */
/*   Updated: 2025/02/17 14:57:18 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	ft_moves(char *str, t_stack **a, t_stack **b)
{
	if (ft_strcmp(str, "sa\n") == 0)
		sa(a, 0);
	else if (ft_strcmp(str, "sb\n") == 0)
		sb(b, 0);
	else if (ft_strcmp(str, "ss\n") == 0)
		ss(a, b, 0);
	else if (ft_strcmp(str, "ra\n") == 0)
		ra(a, 0);
	else if (ft_strcmp(str, "rb\n") == 0)
		rb(b, 0);
	else if (ft_strcmp(str, "rr\n") == 0)
		rr(a, b, 0);
	else if (ft_strcmp(str, "rra\n") == 0)
		rra(a, 0);
	else if (ft_strcmp(str, "rrb\n") == 0)
		rrb(b, 0);
	else if (ft_strcmp(str, "rrr\n") == 0)
		rrr(a, b, 0);
	else if (ft_strcmp(str, "pa\n") == 0)
		pa(a, b, 0);
	else if (ft_strcmp(str, "pb\n") == 0)
		pb(a, b, 0);
	else
		return (write(1, "Error\n", 6), free_stack(*a), free_stack(*b), 0);
	return (1);
}

int	main(int argc, char **argv)
{
	char	*str;
	t_stack	*a;
	t_stack	*b;

	if (argc < 2 || !check_char(argv))
		return (ft_printf("Error\n"), 1);
	a = NULL;
	b = NULL;
	if (!put_argv(argc, argv, &a))
		return (ft_printf("Numero doppio\n"), free_stack(a), 1);
	str = get_next_line(0);
	while (str)
	{
		if (!ft_moves(str, &a, &b))
			return (free(str), free_stack(a), free_stack(b), 0);
		free(str);
		str = get_next_line(0);
	}
	free(str);
	if (is_sort(&a))
		return (write(1, "OK\n", 3), free_stack(a), free_stack(b), 0);
	else
		return (write(1, "KO\n", 3), free_stack(a), free_stack(b), 1);
}
