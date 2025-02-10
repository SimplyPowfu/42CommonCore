/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_in_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:33:12 by ecarbona          #+#    #+#             */
/*   Updated: 2025/02/10 21:02:58 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_in_b(t_stack **a, t_stack **b)
{
	t_stack	*temp;
	t_stack	*last;

	temp = *a;
	last = ft_laststack(temp);
	if (temp->content < last->content)
		pb(a, b);
	else
		ra(a);
}

void	put_sort_in_a(t_stack **a, t_stack **b)
{
	t_stack	*temp_a;
	t_stack	*temp_b;
	int		pos;
	int		i;

	i = 0;
	pos = 1;
	temp_a = *a;
	temp_b = *b;
	while (temp_a->content != take_min(*a))
	{
		pos++;
		temp_a = temp_a->next;
	}
	while (temp_a->content < temp_b->content)
	{
		pos++;
		if (temp_a->next)
			temp_a = temp_a->next;
		else
		{
			temp_a = (*a);
			pos = 1;
		}
	}
	if (pos <= ft_stacksize(*a) / 2)
		while (++i < pos)
			ra(a);
	else
		while (pos++ < ft_stacksize(*a) + 1)
			rra(a);
	pa(a, b);
}

int	is_sort(t_stack **a)
{
	t_stack	*temp;

	temp = *a;
	while (temp && temp->next && temp->content < temp->next->content)
		temp = temp->next;
	if (temp == NULL || temp->next == NULL)
		return (1);
	return (0);
}
