/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:22:09 by ecarbona          #+#    #+#             */
/*   Updated: 2025/02/01 18:03:17 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_double(t_stack **a)
{
    t_stack *stack; //a
    t_stack *checker;

    stack = *a;
    while (stack)
    {
        checker = stack->next;
        while (checker)
        {
            if (stack->content == checker->content)
				return (0);
            checker = checker->next;
        }
        stack = stack->next;
    }
    return (1);
}

int	check_char(char **av)
{
	int	i;
	int	j;
	int n;

	i = 0;
	n = 0;
	while (av[++i] != NULL)
	{
		j = -1;
		while (av[i][++j])
		{
			if ((av[i][j] < '0' || av[i][j] > '9') && av[i][j] != ' ' &&
				av[i][j] != '-' && av[i][j] != '+')
				return (ft_printf("Only numbers, "), 0);
			if (av[i][j] >= '0' && av[i][j] <= '9')
				n++;
		}
	}
	return (n);
}

void take_numb(t_stack **a, t_stack *new, t_stack *temp, char **mat, int *i)
{
	new = ft_calloc(sizeof(t_stack));
	new->content = ft_atoi(mat[*i]);
	if (*a == NULL)
		*a = new;
	else
	{
		temp = *a;
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
}

int put_argv(int argc, char **argv, t_stack **a)
{
    char **mat;
    int i;
	int x;
    t_stack *new;
    t_stack *temp;

	i = -1;
	x = 1;
    if (argc == 2)
    {
        mat = ft_split(argv[1], ' ');
        while (mat[++i])
            take_numb(a, new, temp, mat, &i);
		ft_free(mat, i);
    }
	else
	{
		i = 0;
		while (argv[++i])
			take_numb(a, new, temp, argv, &i);
	}
	if (!check_double(a))
		return (0);
	return (1);
}


int main(int argc, char **argv)
{
	t_stack	*a;
	//t_stack	*b;

	if (argc < 2 || !check_char(argv))
		return (ft_printf("Error\n"), 1);
	a = NULL;
	if (!put_argv(argc, argv, &a))
		return (ft_printf("Numero doppio\n"), free_stack(a), 1);
	t_stack *temp = a;
    while (temp)
    {
        printf("%d\n", temp->content);
        temp = temp->next;
    }
	free_stack(a);
	return (0);
}
