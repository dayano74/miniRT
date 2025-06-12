/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:06:39 by okaname           #+#    #+#             */
/*   Updated: 2024/10/27 20:13:52 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst == NULL || del == NULL)
		return ;
	del(lst->content);
	free(lst);
}

// // 内容の解放用の関数
// void	del_content(void *content)
// {
// 	free(content);
// }

// int	main(void)
// {
// 	// ノードを作成してメモリ割り当て
// 	t_list *node = ft_lstnew(malloc(20)); // 例として20バイトのメモリを確保
// 	// ノードを削除してメモリ解放
// 	ft_lstdelone(node, del_content);
// 	return (0);
// }
