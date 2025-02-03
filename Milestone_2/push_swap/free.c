/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 13:44:21 by ecarbona          #+#    #+#             */
/*   Updated: 2025/02/03 13:21:55 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stacksize(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

void print_stack(t_stack *stack)
{
    while (stack)
    {
        printf("%d -> ", stack->content);
        stack = stack->next;
    }
    printf("NULL\n");
}

void	ft_free(char **tab, int wrld)
{
	while (wrld >= 0)
		free(tab[wrld--]);
	free(tab);
}

void free_stack(t_stack *a)
{
    t_stack *temp;
    while (a)
    {
        temp = a;
        a = a->next;
        free(temp);
    }
}