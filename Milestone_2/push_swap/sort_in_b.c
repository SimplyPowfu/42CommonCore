#include "push_swap.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// Function to check if a value already exists in the stack
int value_exists(t_stack *stack, int value)
{
	t_stack *current = stack;
	while (current != NULL)
	{
		if (current->content == value)
			return 1; // Value already exists
		current = current->next;
	}
	return 0; // Value does not exist
}

t_stack *init_stack_with_random_values(t_stack *a)
{
	t_stack *current;
	t_stack *new_node;
	int i;
	int rand_value;
	srand(time(NULL));
	a = (t_stack *)malloc(sizeof(t_stack));
	rand_value = rand() % 100 + 1;
	while (value_exists(a, rand_value))
		rand_value = rand() % 100 + 1;
	a->content = rand_value;
	a->next = NULL;
	a->before = NULL;  // Il primo nodo non ha un nodo precedente
	current = a;
	for (i = 1; i < 10; i++) // Abbiamo già il primo nodo
	{
		new_node = (t_stack *)malloc(sizeof(t_stack));
		rand_value = rand() % 900 + 1;
		while (value_exists(a, rand_value))
			rand_value = rand() % 100 + 1;
		new_node->content = rand_value;
		new_node->next = NULL;
		new_node->before = current;  // Collega il nodo precedente al nuovo nodo
		current->next = new_node;  // Collega il nodo precedente al nuovo nodo
		current = new_node;  // Muove il puntatore corrente al nuovo nodo
	}
	a->before = current;
	return a;
}


int	take_min(t_stack *a)
{
	t_stack *temp;
	int	min;
	int	i;

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

void put_in_b(t_stack **a, t_stack **b)
{
	t_stack *temp;
	t_stack *last;

	temp = *a;
	last = ft_laststack(temp);
	if (temp->content < last->content)
		pb(a, b);
	else
		ra(a);
}

void	put_in_a(t_stack **a, t_stack **b)
{
	t_stack *temp_a;
	t_stack *temp_b;
	int pos;
	int i;

	i = 0;
	pos = 1;
	temp_a = *a;
	temp_b = *b;

	while(temp_a->content < temp_b->content)
	{
		pos++;
		temp_a = temp_a->next;
	}
	if (pos <= ft_stacksize(*a) / 2)
		while (++i < pos)
			ra(a);
	else
	while (pos++ < ft_stacksize(*a) + 1)
		rra(a);
	pa(a, b);
}

void	put_sort_in_a(t_stack **a, t_stack **b, t_stack **temp)
{
	t_stack *temp_a;
	t_stack *temp_b;
	int pos;
	int i;

	i = 0;
	pos = 1;
	temp_a = *a;
	temp_b = *b;

	while (temp_a->content != (*temp)->content)
	{
		pos++;
		temp_a = temp_a->next;
	}
	while(temp_a->content < temp_b->content)
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
			ra(a);
	else
	while (pos++ < ft_stacksize(*a) + 1)
		rra(a);
	pa(a, b);
}

int is_sort(t_stack **a)
{
	t_stack *temp;

	temp = *a;
	while (temp && temp->next && temp->content < temp->next->content)
		temp = temp->next;
	if (temp == NULL || temp->next == NULL)
		return (1);
	return (0);
}

void min_pos(t_stack **a)
{
	t_stack *temp;
	int	min;
	int pos;
	int i;

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

// int main()
// {
// 	t_stack *a = NULL;
// 	t_stack *b = NULL;

// 	a = init_stack_with_random_values(a);
// 	print_stack(a); // Assuming print_stack is implemented
// 	print_stack(b); // Assuming print_stack is implemented

// 	while (a && !is_sort(&a))
// 		put_in_b(&a, &b);
// 	print_stack(a); // Assuming print_stack is implemented
// 	print_stack(b); // Assuming print_stack is implemented
// 	while (b)
// 		put_in_a(&a, &b);
// 	print_stack(a);
// 	print_stack(b);

// 	free_stack(a); // Assuming free_stack is implemented
// 	free_stack(b); // Assuming free_stack is implemented
// 	return 0;
// }
