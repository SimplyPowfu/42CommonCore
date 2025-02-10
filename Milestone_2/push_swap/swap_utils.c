/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:15:13 by ecarbona          #+#    #+#             */
/*   Updated: 2025/02/10 13:16:02 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	take_min(t_stack *a)
{
	t_stack	*temp;
	int		min;
	int		i;

	i = 0;
	temp = a;
	min = temp->content;
	while (temp)
	{
		if (min > temp->content)
			min = temp->content;
		temp = temp->next;
	}
	return (min);
}

void	min_pos(t_stack **a)
{
	t_stack	*temp;
	int		min;
	int		pos;
	int		i;

	i = 0;
	pos = 1;
	min = take_min(*a);
	temp = *a;
	while (temp->content != min)
	{
		temp = temp->next;
		pos++;
	}
	if (pos <= ft_stacksize(*a) / 2)
		while (++i < pos)
			ra(a);
	else
		while (pos++ < ft_stacksize(*a) + 1)
			rra(a);
}
