/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:15:13 by ecarbona          #+#    #+#             */
/*   Updated: 2025/02/10 17:40:18 by ecarbona         ###   ########.fr       */
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

int calculate_moves(t_stack **a, t_stack **b, t_stack *elem_b)
{
	t_stack *temp_a;
	int pos;
	int i;
	int moves;

	i = 0;
	pos = 1;
	moves = 0;
	temp_a = *a;

	// Trova la posizione dell'elemento minimo in `a`
	while (temp_a->content != take_min(*a))
	{
		pos++;
		temp_a = temp_a->next;
	}

	// Scorri `a` fino a trovare la posizione corretta per `elem_b` (rispetto all'ordinamento desiderato)
	while (temp_a->content < elem_b->content)
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

	// Calcola le mosse per `a`
	if (pos <= ft_stacksize(*a) / 2)
	{
		moves += pos;  // Mossa in avanti (ra)
	}
	else
	{
		moves += ft_stacksize(*a) - pos + 1;  // Mossa indietro (rra)
	}

	// Calcola le mosse per `b` (come se spostassi l'elemento da `b` su `a`)
	// Se l'elemento in `b` è in cima o in fondo, calcola di conseguenza.
	int pos_b = 0;
	t_stack *temp_b = *b;
	while (temp_b)
	{
		pos_b++;
		if (temp_b == elem_b)
			break;
		temp_b = temp_b->next;
	}

	if (pos_b <= ft_stacksize(*b) / 2)
	{
		moves += pos_b;  // Mossa in avanti (rb)
	}
	else
	{
		moves += ft_stacksize(*b) - pos_b + 1;  // Mossa indietro (rrb)
	}

	return moves;
}


t_stack	*find_best(t_stack **a, t_stack **b)
{
	t_stack *temp_b;
	t_stack *best;
	int		moves;
	int		best_moves;

	best_moves = 2147483647;
	temp_b = *b;
	best = NULL;
	while (temp_b)
	{
		moves = calculate_moves(a, b, temp_b);
		if (moves < best_moves)
		{
			best_moves = moves;
			best = temp_b;
		}
		temp_b = temp_b->next;
	}
	return (best);
}
