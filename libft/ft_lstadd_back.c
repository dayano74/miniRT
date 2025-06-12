/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 19:57:51 by okaname           #+#    #+#             */
/*   Updated: 2024/11/01 17:41:08 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (*lst == NULL)
		*lst = new;
	else
		ft_lstlast(*lst)->next = new;
}

// int	main(void)
// {
// 	t_list	*head;
// 	t_list	*node2;
// 	t_list	*node3;
// 	t_list	*temp;

// 	head = ft_lstnew("Node 1");
// 	node2 = ft_lstnew("Node 2");
// 	node3 = ft_lstnew("Node 3");
// 	ft_lstadd_back(&head, node2);
// 	ft_lstadd_back(&head, node3);
// 	// リストを表示して確認
// 	temp = head;
// 	while (temp)
// 	{
// 		printf("Node content: %s\n", (char *)temp->content);
// 		temp = temp->next;
// 	}
// 	// メモリ解放
// 	free(head);
// 	free(node2);
// 	free(node3);
// 	return (0);
// }
