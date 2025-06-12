/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 19:51:41 by okaname           #+#    #+#             */
/*   Updated: 2024/11/01 17:22:23 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

// int	main(void)
// {
// 	t_list	*node1;
// 	t_list	*node2;
// 	t_list	*node3;
// 	t_list	*last;
// 	node1 = ft_lstnew("Node 1");
// 	node2 = ft_lstnew("Node 2");
// 	node3 = ft_lstnew("Node 3");
// 	// ノードをリンクさせる
// 	node1->next = node2;
// 	node2->next = node3;
// 	// リストの最後の要素を取得
// 	last = ft_lstlast(node1);
// 	if (last)
// 		printf("Last node content: %s\n", (char *)last->content); // 出力: Node 3
// 	// メモリ解放
// 	free(node1);
// 	free(node2);
// 	free(node3);
// 	return (0);
// }
