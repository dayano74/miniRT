/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:26:24 by okaname           #+#    #+#             */
/*   Updated: 2024/11/17 17:24:36 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (f == NULL)
		return ;
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}

void	print_content(void *content)
{
	printf("%s\n", (char *)content);
}

// int	main(void)
// {
// 	t_list	*head;
// 	t_list	*node2;
// 	t_list	*node3;

// 	head = ft_lstnew(strdup("Node 1"));
// 	node2 = ft_lstnew(strdup("Node 2"));
// 	node3 = ft_lstnew(strdup("Node 3"));
// 	head->next = node2;
// 	node2->next = node3;
// 	ft_lstiter(head, NULL);
// 	// リストを削除し、メモリを解放
// 	ft_lstclear(&head, free);
// 	return (0);
// }
