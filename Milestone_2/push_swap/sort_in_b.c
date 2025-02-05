#include "push_swap.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

static int m = 0;

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
    current = a;
    for (i = 1; i < 100; i++) // We already have the first node
    {
        new_node = (t_stack *)malloc(sizeof(t_stack));
        rand_value = rand() % 900 + 1;
        while (value_exists(a, rand_value))
            rand_value = rand() % 100 + 1;
        new_node->content = rand_value;
        new_node->next = NULL;
        current->next = new_node; // Link current node to the new node
        current = new_node; // Move current to the new node
    }
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
	int	min;
	int pos;
	int	i;

	i = 0;
	min = take_min(*a);
	temp = *a;
	while (temp && temp->content != min)
		temp = temp->next;
	pos = (ft_stacksize(*a) - ft_stacksize(temp)) + 1;
	if (pos <= ft_stacksize(*a) / 2)
		while (++i < pos)
		{
			ra(a);
			m += 1;
		}
	else
        while (pos++ < ft_stacksize(*a) + 1)
		{
			rra(a);
			m += 1;
		}
	pa(a, b);
	m += 1;
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

int main()
{
    t_stack *a = NULL;
    t_stack *b = NULL;
	int min;

    a = init_stack_with_random_values(a);
	//print_stack(a); // Assuming print_stack is implemented
	while (a && !is_sort(&a))
		put_in_b(&a, &b);
	while (b)
	{
		pb(&a, &b);
		m += 1;
	}
	print_stack(a);
	ft_printf("\n%d\n\n", m);

    free_stack(a); // Assuming free_stack is implemented
    free_stack(b); // Assuming free_stack is implemented
    return 0;
}
