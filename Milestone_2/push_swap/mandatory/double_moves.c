/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecar_bona <ecar_bona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:58:18 by ecar_bona          #+#    #+#             */
/*   Updated: 2025/02/14 18:01:44 by ecar_bona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	check_doub(t_stack **a, t_stack **b, t_stack *best, int r_b, int rr_b)
{
	t_stack	*temp_a;
	int		pos;
	int		i;
	int		r_a;
	int		rr_a;

	r_a = 0;
	rr_a = 0;
	i = 0;
	pos = 1;
	temp_a = *a;
	while (temp_a && temp_a->content != take_min(*a))
	{
		pos++;
		temp_a = temp_a->next;
	}
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
			r_a++;
	else
		while (pos++ < ft_stacksize(*a) + 1)
			rr_a++;
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

void	check_doubles(t_stack **a, t_stack **b, t_stack *best)
{
	t_stack	*temp;
	int		i;
	int		pos;
	int		r_b;
	int		rr_b;

	r_b = 0;
	rr_b = 0;
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
			r_b++;
	else
		while (pos++ < ft_stacksize(*b) + 1 && ft_stacksize(*b) > 1)
			rr_b++;
	check_doub(a, b, best, r_b, rr_b);
}
