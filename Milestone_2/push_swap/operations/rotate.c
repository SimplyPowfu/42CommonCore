/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:38:14 by ecarbona          #+#    #+#             */
/*   Updated: 2025/02/17 14:58:09 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h" //primo in ultimo

int	rotate(t_stack **stack)
{
	t_stack	*head;
	t_stack	*temp;
	t_stack	*last;

	if (ft_stacksize(*stack) == 0)
		return (0);
	head = *stack;
	temp = *stack;
	last = ft_laststack(head);
	*stack = (*stack)->next;
	last->next = temp;
	temp->next = NULL;
	return (1);
}

int	ra(t_stack **a, int i)
{
	if (ft_stacksize(*a) == 1)
		return (1);
	if (!rotate(a))
		return (ft_printf("Error\n"), 0);
	if (i == 1)
		write(1, "ra\n", 3);
	return (1);
}

int	rb(t_stack **b, int i)
{
	if (ft_stacksize(*b) == 1)
		return (1);
	if (!rotate(b))
		return (ft_printf("Error\n"), 0);
	if (i == 1)
		write(1, "rb\n", 3);
	return (1);
}

int	rr(t_stack **a, t_stack **b, int i)
{
	rotate (a);
	rotate (b);
	if (i == 1)
		write(1, "rr\n", 3);
	return (1);
}
