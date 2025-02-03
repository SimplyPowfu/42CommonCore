/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:32:33 by ecarbona          #+#    #+#             */
/*   Updated: 2025/02/03 13:33:01 by ecarbona         ###   ########.fr       */
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

#endif