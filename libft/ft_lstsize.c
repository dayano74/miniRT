/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 19:46:15 by okaname           #+#    #+#             */
/*   Updated: 2024/10/27 19:50:37 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *list)
{
	int	count;

	count = 0;
	while (list)
	{
		count++;
		list = list->next;
	}
	return (count);
}

// int	main(void)
// {
// 	t_list	*node1;
// 	t_list	*node2;
// 	t_list	*node3;
// 	int		size;

// 	node1 = ft_lstnew("Node 1");
// 	node2 = ft_lstnew("Node 2");
// 	node3 = ft_lstnew("Node 3");
// 	// ノードをリンクさせる
// 	node1->next = node2;
// 	node2->next = node3;
// 	// リストのサイズを取得
// 	size = ft_lstsize(node1);
// 	printf("List size: %d\n", size); // 出力: List size: 3
// 	// メモリ解放
// 	free(node1);
// 	free(node2);
// 	free(node3);
// 	return (0);
// }
