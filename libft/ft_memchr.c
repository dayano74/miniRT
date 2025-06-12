/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 18:26:13 by okaname           #+#    #+#             */
/*   Updated: 2024/11/13 01:38:18 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p;
	size_t				i;

	p = s;
	i = 0;
	while (i < n)
	{
		if (p[i] == (unsigned char)c)
			return ((void *)&p[i]);
		i++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	const char	str[] = "Hello, World!";
// 	char		ch;
// 	size_t		n;
// 	char		*result;

// 	ch = 'o';
// 	n = 10;
// 	result = ft_memchr(str, ch, n);
// 	if (result)
// 	{
// 		printf("Found '%c' at position: %ld\n", ch, result - str);
// 	}
// 	else
// 	{
// 		printf("Character '%c' not found in the first %zu bytes.\n", ch, n);
// 	}
// 	return (0);
// }
