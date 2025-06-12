/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:34:51 by okaname           #+#    #+#             */
/*   Updated: 2024/11/17 17:26:32 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	t_list	*current;

	new_list = NULL;
	if (f == NULL)
		return (NULL);
	while (lst != NULL)
	{
		new_node = ft_lstnew(f(lst->content));
		if (new_node == NULL)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		if (new_list == NULL)
			new_list = new_node;
		else
			current->next = new_node;
		current = new_node;
		lst = lst->next;
	}
	return (new_list);
}
// void	*double_content(void *content)
// {
// 	int	*new_content;

// 	new_content = (int *)malloc(sizeof(int));
// 	if (!new_content)
// 		return (NULL);
// 	*new_content = (*(int *)content) * 2;
// 	return (new_content);
// }

// // 削除用の関数: メモリ解放
// void	del_content(void *content)
// {
// 	free(content);
// }

// // ft_lstmap関数のテスト
// int	main(void)
// {
// 	t_list	*original_list;
// 	t_list	*new_list;

// 	// 元のリストを作成
// 	original_list = ft_lstnew((void *)malloc(sizeof(int)));
// 	*(int *)(original_list->content) = 1;
// 	original_list->next = ft_lstnew((void *)malloc(sizeof(int)));
// 	*(int *)(original_list->next->content) = 2;
// 	original_list->next->next = ft_lstnew((void *)malloc(sizeof(int)));
// 	*(int *)(original_list->next->next->content) = 3;
// 	// マッピングを実行
// 	new_list = ft_lstmap(original_list, double_content, del_content);
// 	// 結果の確認
// 	printf("Original List:\n");
// 	for (t_list *node = original_list; node != NULL; node = node->next)
// 		printf("%d ", *(int *)(node->content));
// 	printf("\nMapped List (doubled):\n");
// 	for (t_list *node = new_list; node != NULL; node = node->next)
// 		printf("%d ", *(int *)(node->content));
// 	// メモリ解放
// 	ft_lstclear(&original_list, del_content);
// 	ft_lstclear(&new_list, del_content);
// 	return (0);
// }
