/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:02:51 by okaname           #+#    #+#             */
/*   Updated: 2024/10/27 15:24:26 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;
	size_t			i;

	p = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		p[i] = 0;
		i++;
	}
}

// int	main(void)
// {
// 	char	buffer[10];

// 	// buffer をゼロで埋める
// 	ft_bzero(buffer, sizeof(buffer));
// 	// 出力して確認
// 	for (size_t i = 0; i < sizeof(buffer); i++)
// 	{
// 		printf("%d ", buffer[i]); // すべて 0 が出力される
// 	}
// 	return (0);
// }
