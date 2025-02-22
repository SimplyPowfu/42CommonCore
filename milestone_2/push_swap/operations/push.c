/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:35:12 by ecarbona          #+#    #+#             */
/*   Updated: 2025/02/17 14:24:32 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	push(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	temp = *a;
	*a = (*a)->next;
	temp->next = *b;
	*b = temp;
	return (1);
}

int	pa(t_stack **a, t_stack **b, int i)
{
	if (!push(b, a))
		return (ft_printf("Error\n"), 0);
	if (i == 1)
		write (1, "pa\n", 3);
	return (1);
}

int	pb(t_stack **a, t_stack **b, int i)
{
	if (!push(a, b))
		return (ft_printf("Error\n"), 0);
	if (i == 1)
		write (1, "pb\n", 3);
	return (1);
}
