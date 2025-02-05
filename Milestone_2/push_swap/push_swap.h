/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:32:33 by ecarbona          #+#    #+#             */
/*   Updated: 2025/02/05 23:18:54 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
}	t_stack;

void	ft_free(char **tab, int wrld);
void	free_stack(t_stack *a);
void	print_stack(t_stack *stack);
int		ft_stacksize(t_stack *lst);
t_stack	*ft_laststack(t_stack *stack);

int	sa(t_stack **a);
int	sb(t_stack **b);
int	ss(t_stack **a, t_stack **b);
int	ra(t_stack **a);
int	rb(t_stack **b);
int	rr(t_stack **a, t_stack **b);
int	rra(t_stack **a);
int	rrb(t_stack **b);
int	rrr(t_stack **a, t_stack **b);
int	pa(t_stack **a, t_stack **b);
int	pb(t_stack **a, t_stack **b);

#endif