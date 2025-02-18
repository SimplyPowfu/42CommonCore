/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:43:30 by ecarbona          #+#    #+#             */
/*   Updated: 2025/02/18 18:34:42 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc > 1)
	{
		if (!check_char(argv))
			return (ft_printf("Error\n"), 1);
		a = NULL;
		b = NULL;
		if (!put_argv(argc, argv, &a))
			return (ft_printf("Numero doppio\n"), free_stack(a), 1);
		if (argc == 4)
			direct_sort(&a);
		while (a && !is_sort(&a))
			put_in_b(&a, &b);
		while (b)
			put_in_a(&a, &b);
		min_pos(&a);
		return (free_stack(a), free_stack(b), 0);
	}
}
