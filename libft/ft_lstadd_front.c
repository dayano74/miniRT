/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 19:35:12 by okaname           #+#    #+#             */
/*   Updated: 2024/11/17 17:23:01 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst == NULL || new == NULL)
		return ;
	new->next = *lst;
	*lst = new;
}
// int	main(void)
// {
// 	t_list	*head;
// 	t_list	*node1;
// 	t_list	*node2;

// 	// 例としてノードを作成
// 	node1 = ft_lstnew("First node");
// 	node2 = ft_lstnew("New front node");
// 	head = node1;
// 	printf("Before adding new node:\n");
// 	printf("Head content: %s\n", (char *)head->content);
// 	// 新しいノードを先頭に追加
// 	ft_lstadd_front(&head, node2);
// 	printf("\nAfter adding new node to front:\n");
// 	printf("Head content: %s\n", (char *)head->content);
// 	printf("Next content: %s\n", (char *)head->next->content);
// 	// メモリ解放
// 	free(node1);
// 	free(node2);
// 	return (0);
// }
