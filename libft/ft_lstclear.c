/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:22:36 by ecarbona          #+#    #+#             */
/*   Updated: 2024/11/25 19:04:32 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*head;
	t_list	*tmp;

	if (!lst || !del)
		return ;
	head = *lst;
	while (head)
	{
		tmp = head -> next;
		(*del)(head -> content);
		free(head);
		head = tmp;
	}
	*lst = NULL;
}
// static void	ft_del(void *content)
// {
// 	free (content);
// }
// int main()
// {
// 	t_list *head = NULL;
// 	t_list *new_node;
// 	t_list *new_node1;
// 	t_list *temp;
// 	char *content1 = ft_strdup("1");
// 	char *content2 = ft_strdup("2");
// 	new_node = ft_lstnew((void *)content1);
// 	ft_lstadd_front(&head, new_node);
// 	new_node1 = ft_lstnew((void *)content2);
// 	ft_lstadd_front(&head, new_node1);
// 	temp = head;
// 	while(temp)
// 	{
// 		printf("%s\n", (char *)temp->content);
// 		temp = temp->next;
// 	}
// 	ft_lstclear(&head, ft_del);
// 	if(!head)
// 		printf("Free\n");
// }
