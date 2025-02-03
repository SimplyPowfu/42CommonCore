/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:39:11 by ecarbona          #+#    #+#             */
/*   Updated: 2025/02/03 13:40:29 by ecarbona         ###   ########.fr       */
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

int	sa(t_stack **a) //swap first 2 element a
{
	if (!swap(a))
		return (ft_printf("Error\n"), 0);
	write(1, "sa\n", 3);
	return (1);
}

int	sb(t_stack **b) //swap first 2 element b
{
	if (!swap(b))
		return (ft_printf("Error\n"), 0);
	write(1, "sb\n", 3);
	return (1);
}

int	ss(t_stack **a, t_stack **b) //sa & sb
{
	if (ft_stacksize((*a)) < 2 || ft_stacksize((*b)) < 2)
		return (ft_printf("Error\n"), 0);
	swap (a);
	swap (b);
	write(1, "ss\n", 3);
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
//     print_stack(stack);
// 	print_stack(stack_b);
//     if (!ss(&stack, &stack_b))
// 		return (1);
//     print_stack(stack);
// 	print_stack(stack_b);
//     return 0;
// }
