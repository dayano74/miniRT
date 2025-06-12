/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:16:29 by okaname           #+#    #+#             */
/*   Updated: 2024/11/04 22:45:56 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;
	size_t			i;

	p = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		p[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

// int	main(void)
// {
// 	char	buffer[10];

// 	// buffer を 'A' で埋める
// 	ft_memset(buffer, 'A', sizeof(buffer));
// 	// 出力して確認
// 	for (size_t i = 0; i < sizeof(buffer); i++)
// 	{
// 		printf("%c ", buffer[i]); // すべて 'A' が出力される
// 	}
// 	return (0);
// }
