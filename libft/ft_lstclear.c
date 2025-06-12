/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:15:32 by okaname           #+#    #+#             */
/*   Updated: 2024/10/27 20:24:58 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (lst == NULL || del == NULL)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temp;
	}
	*lst = NULL;
}

// // ノードの内容を削除するための関数
// void	del_content(void *content)
// {
// 	free(content);
// }

// int	main(void)
// {
// 	t_list	*node2;
// 	t_list	*node3;

// 	// リストのノードを作成
// 	t_list *head = ft_lstnew(malloc(20)); // contentに20バイトのメモリを割り当て
// 	node2 = ft_lstnew(malloc(30));
// 	node3 = ft_lstnew(malloc(40));
// 	// ノードをリンクさせる
// 	head->next = node2;
// 	node2->next = node3;
// 	// リストを削除し、メモリを解放
// 	ft_lstclear(&head, del_content);
// 	// 確認
// 	if (head == NULL)
// 		printf("The list has been cleared.\n");
// 	return (0);
// }
