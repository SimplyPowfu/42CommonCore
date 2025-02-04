/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:38:14 by ecarbona          #+#    #+#             */
/*   Updated: 2025/02/04 15:38:54 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

int	ra(t_stack **a)
{
	if (!rotate(a))
		return (ft_printf("Error\n"), 0);
	write(1, "ra\n", 3);
	return (1);
}

int	rb(t_stack **b)
{
	if (!rotate(b))
		return (ft_printf("Error\n"), 0);
	write(1, "rb\n", 3);
	return (1);
}

int	rr(t_stack **a, t_stack **b)
{
	if (ft_stacksize((*a)) < 2 || ft_stacksize((*b)) < 2)
		return (ft_printf("Error\n"), 0);
	rotate (a);
	rotate (b);
	write(1, "rr\n", 3);
	return (1);
}

// int main()
// {
//     t_stack *stack = NULL;
// 	stack = (t_stack *)malloc(sizeof(t_list));
// 	stack->content = 2;
// 	stack->next = NULL;
// 	stack->next = (t_stack *)malloc(sizeof(t_list));
// 	stack->next->content = 4;
// 	stack->next->next = NULL;
// 	t_stack *stack_b = NULL;
// 	stack_b = (t_stack *)malloc(sizeof(t_list));
// 	stack_b->content = 6;
// 	stack_b->next = NULL;
// 	stack_b->next = (t_stack *)malloc(sizeof(t_list));
// 	stack_b->next->content = 8;
// 	stack_b->next->next = NULL;
//  print_stack(stack);
// 	print_stack(stack_b);
//     if (!rr(&stack, &stack_b))
// 		return (1);
//     print_stack(stack);
// 	print_stack(stack_b);
// 	free_stack(stack);
//     return (0);
// }