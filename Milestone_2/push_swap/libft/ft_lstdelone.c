/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 19:16:59 by ecarbona          #+#    #+#             */
/*   Updated: 2024/11/25 18:10:21 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	(*del)(lst -> content);
	free (lst);
}
// static void ft_del(void *content)
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
// 	ft_lstadd_back(&head, new_node);
// 	new_node1 = ft_lstnew((void *)content2);
// 	ft_lstadd_back(&head, new_node1);
// 	temp = head;
// 	while(temp)
// 	{
// 		printf("%s\n", (char *)temp->content);
// 		temp = temp->next;
// 	}
// 	temp = head->next;//assegni a temp il nodo seguente
// 	ft_lstdelone(head, ft_del);//cancelli il nodo
// 	head = temp;//assegni ad head il nodo dopo la cancellazione
// 	while (head)
// 	{
// 		printf("%s\n", (char *)head->content);
// 		head = head->next;
// 	}
// }