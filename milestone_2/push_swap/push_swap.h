/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:32:33 by ecarbona          #+#    #+#             */
/*   Updated: 2025/02/19 17:33:19 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
	struct s_stack	*before;
}	t_stack;

void	ft_free(char **tab);
void	free_stack(t_stack *a);
void	print_stack(t_stack *stack);
int		ft_stacksize(t_stack *lst);
t_stack	*ft_laststack(t_stack *stack);
int		is_sort(t_stack **a);
int		check_char(char **av);
int		put_argv(int argc, char **argv, t_stack **a);
int		take_min(t_stack *a);
void	put_in_b(t_stack **a, t_stack **b);
void	put_in_a(t_stack **a, t_stack **b);
void	put_sort_in_a(t_stack **a, t_stack **b);
void	min_pos(t_stack **a);
int		take_pos_a(t_stack **a, t_stack *temp_a, t_stack *temp_b, int pos);
t_stack	*find_best(t_stack **a, t_stack **b);
void	check_doubles(t_stack **a, t_stack **b, t_stack *best);
void	direct_sort(t_stack **a);
int		sa(t_stack **a, int i);
int		sb(t_stack **b, int i);
int		ss(t_stack **a, t_stack **b, int i);
int		ra(t_stack **a, int i);
int		rb(t_stack **b, int i);
int		rr(t_stack **a, t_stack **b, int i);
int		rra(t_stack **a, int i);
int		rrb(t_stack **b, int i);
int		rrr(t_stack **a, t_stack **b, int i);
int		pa(t_stack **a, t_stack **b, int i);
int		pb(t_stack **a, t_stack **b, int i);

#endif