/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 18:18:02 by okaname           #+#    #+#             */
/*   Updated: 2024/11/17 21:47:28 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (new_node == NULL)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

// int	main(void)
// {
// 	char *content = "Hello, world!";
// 	t_list *node = ft_lstnew(content);

// 	if (node)
// 	{
// 		printf("Node content: %s\n", (char *)node->content);
// 		printf("Next node: %p\n", (void *)node->next);
// 		free(node); // 確保したメモリを解放
// 	}
// 	else
// 	{
// 		printf("Failed to allocate memory for new node.\n");
// 	}

// 	return (0);
// }