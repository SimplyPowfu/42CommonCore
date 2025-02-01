#ifndef	PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_stack
{
	int		content;
	struct s_stack	*next;
}	t_stack;

void	ft_free(char **tab, int wrld);
void	free_stack(t_stack *a);
int		ft_stacksize(t_stack *lst);

#endif