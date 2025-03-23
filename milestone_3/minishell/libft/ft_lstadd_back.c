/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:00:08 by ecarbona          #+#    #+#             */
/*   Updated: 2025/02/01 17:26:59 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	temp = ft_lstlast(*lst);
	temp->next = new;
}
// int main()
// {
// 	t_list *head;
// 	t_list *temp;
// 	head = NULL;
// 	char *content = "1";
// 	char *content1 = "2";
// 	char *content2 = "3";
// 	t_list *new_node;
// 	new_node = ft_lstnew((void *)content);
// 	ft_lstadd_back(&head, new_node);
// 	t_list *new_node1;
// 	new_node1 = ft_lstnew((void *)content1);
// 	ft_lstadd_back(&head, new_node1);
// 	t_list *new_node2;
// 	new_node2 = ft_lstnew((void *)content2);
// 	ft_lstadd_back(&head, new_node2);
// 	temp = head;
// 	while(temp)
// 	{
// 		printf("%s\n", (char *)temp->content);
// 		temp = temp->next;
// 	}
// }
