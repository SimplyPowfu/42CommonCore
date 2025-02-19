/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:54:49 by ecarbona          #+#    #+#             */
/*   Updated: 2025/02/19 16:05:11 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*first_pos(t_stack **a, t_stack *temp_a, int *pos)
{
	while (temp_a && temp_a->content != take_min(*a))
	{
		(*pos)++;
		temp_a = temp_a->next;
	}
	return (temp_a);
}

void	take_pos_b(t_stack **b, t_stack *best, int *r_b, int *rr_b)
{
	t_stack	*temp;
	int		pos;
	int		i;

	i = 0;
	pos = 1;
	temp = *b;
	while (temp->content != best->content)
	{
		pos++;
		temp = temp->next;
	}
	if (pos <= ft_stacksize(*b) / 2 && ft_stacksize(*b) > 1)
		while (++i < pos)
			(*r_b)++;
	else
		while (pos++ < ft_stacksize(*b) + 1 && ft_stacksize(*b) > 1)
			(*rr_b)++;
}

void	take_doub_a(t_stack **a, t_stack *best, int *r_a, int *rr_a)
{
	t_stack	*temp_a;
	int		pos;
	int		i;

	temp_a = *a;
	pos = 1;
	i = 0;
	temp_a = first_pos(a, temp_a, &pos);
	while (temp_a->content < best->content)
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
			(*r_a)++;
	else
		while (pos++ < ft_stacksize(*a) + 1)
			(*rr_a)++;
}

void	check_doubles(t_stack **a, t_stack **b, t_stack *best)
{
	int		r_a;
	int		r_b;
	int		rr_a;
	int		rr_b;

	r_a = 0;
	r_b = 0;
	rr_a = 0;
	rr_b = 0;
	take_pos_b(b, best, &r_b, &rr_b);
	take_doub_a(a, best, &r_a, &rr_a);
	while (r_a > 0 && r_b > 0)
	{
		rr(a, b, 1);
		r_a--;
		r_b--;
	}
	while (rr_a > 0 && rr_b > 0)
	{
		rrr(a, b, 1);
		rr_a--;
		rr_b--;
	}
}
