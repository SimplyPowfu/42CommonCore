/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:36:45 by ecarbona          #+#    #+#             */
/*   Updated: 2025/02/17 14:26:26 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h" //ultimo in prima

int	reverse(t_stack **stack)
{
	t_stack	*head;
	t_stack	*temp;
	t_stack	*last;

	if (ft_stacksize(*stack) == 0)
		return (0);
	temp = *stack;
	head = *stack;
	last = ft_laststack(head);
	while (head->next->next)
		head = head->next;
	head->next = NULL;
	*stack = last;
	(*stack)->next = temp;
	return (1);
}

int	rra(t_stack **a, int i)
{
	if (ft_stacksize(*a) == 1)
		return (1);
	else if (!reverse(a))
		return (ft_printf("Error\n"), 0);
	if (i == 1)
		write(1, "rra\n", 4);
	return (1);
}

int	rrb(t_stack **b, int i)
{
	if (ft_stacksize(*b) == 1)
		return (1);
	if (!reverse(b))
		return (ft_printf("Error\n"), 0);
	if (i == 1)
		write(1, "rrb\n", 4);
	return (1);
}

int	rrr(t_stack **a, t_stack **b, int i)
{
	// if (ft_stacksize((*a)) < 2 || ft_stacksize((*b)) < 2)
	// 	return (ft_printf("Error\n"), 0);
	reverse(a);
	reverse(b);
	if (i == 1)
		write(1, "rrr\n", 4);
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
//  	print_stack(stack);
// 	print_stack(stack_b);
//     if (!rrr(&stack, &stack_b))
// 		return (1);
//     print_stack(stack);
// 	print_stack(stack_b);
// 	free_stack(stack);
// 	free_stack(stack_b);
//     return (0);
// }
