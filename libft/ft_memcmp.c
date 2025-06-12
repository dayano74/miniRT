/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 11:39:18 by okaname           #+#    #+#             */
/*   Updated: 2024/10/27 15:24:17 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*buf1;
	const unsigned char	*buf2;

	i = 0;
	buf1 = s1;
	buf2 = s2;
	while (i < n)
	{
		if (buf1[i] != buf2[i])
		{
			return (buf1[i] - buf2[i]);
		}
		i++;
	}
	return (0);
}

// int	main(void)

// {
// 	char s[] = "ABCD5EFGH";
// 	char s2[] = "ABC123456";

// 	if (ft_memcmp(s, s2, 3) == 0)
// 	{
// 		puts("先頭から3バイトは一致しています。");
// 	}
// 	else
// 	{
// 		puts("一致していません。");
// 	}

// 	return (0);
// }
