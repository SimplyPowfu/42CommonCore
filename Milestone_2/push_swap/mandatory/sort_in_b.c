/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_in_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:33:12 by ecarbona          #+#    #+#             */
/*   Updated: 2025/02/18 18:08:08 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	put_in_b(t_stack **a, t_stack **b)
{
	t_stack	*temp;
	t_stack	*last;

	temp = *a;
	last = ft_laststack(temp);
	
	if (temp->content < last->content)
		pb(a, b, 1);
	else
		ra(a, 1);
}

int	take_pos_a(t_stack **a, t_stack *temp_a, t_stack *temp_b, int pos)
{
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
	return (pos);
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
	while (temp_a && temp_a->content != take_min(*a))
	{
		pos++;
		temp_a = temp_a->next;
	}
	pos = take_pos_a(a, temp_a, temp_b, pos);
	if (pos <= ft_stacksize(*a) / 2)
		while (++i < pos)
			ra(a, 1);
	else
		while (pos++ < ft_stacksize(*a) + 1)
			rra(a, 1);
	pa(a, b, 1);
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

void	put_in_a(t_stack **a, t_stack **b)
{
	t_stack	*temp;
	t_stack	*best;
	int		i;
	int		pos;

	best = find_best(a, b);
	i = 0;
	pos = 1;
	check_doubles(a, b, best);
	temp = *b;
	while (temp->content != best->content)
	{
		pos++;
		temp = temp->next;
	}
	if (pos <= ft_stacksize(*b) / 2 && ft_stacksize(*b) > 1)
		while (++i < pos)
			rb(b, 1);
	else
		while (pos++ < ft_stacksize(*b) + 1 && ft_stacksize(*b) > 1)
			rrb(b, 1);
	put_sort_in_a(a, b);
}
