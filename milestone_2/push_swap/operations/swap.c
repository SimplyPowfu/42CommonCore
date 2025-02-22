/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:39:11 by ecarbona          #+#    #+#             */
/*   Updated: 2025/02/17 14:28:11 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	swap(t_stack **stack)
{
	t_stack	*head;
	int		tmp;

	if (ft_stacksize(*stack) < 2)
		return (0);
	head = (*stack);
	tmp = head->content;
	head->content = head->next->content;
	head->next->content = tmp;
	return (1);
}

int	sa(t_stack **a, int i) //swap first 2 element a
{
	if (!swap(a))
		return (ft_printf("Error\n"), 0);
	if (i == 1)
		write(1, "sa\n", 3);
	return (1);
}

int	sb(t_stack **b, int i) //swap first 2 element b
{
	if (!swap(b))
		return (ft_printf("Error\n"), 0);
	if (i == 1)
		write(1, "sb\n", 3);
	return (1);
}

int	ss(t_stack **a, t_stack **b, int i) //sa & sb
{
	if (ft_stacksize((*a)) < 2 || ft_stacksize((*b)) < 2)
		return (ft_printf("Error\n"), 0);
	swap (a);
	swap (b);
	if (i == 1)
		write(1, "ss\n", 3);
	return (1);
}
