/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 14:14:03 by okaname           #+#    #+#             */
/*   Updated: 2024/11/05 18:55:44 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	if (!dst)
		dst_len = 0;
	else
		dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i = 0;
	if (size <= dst_len)
		return (size + src_len);
	while ((src[i] != '\0') && (i < size - dst_len - 1))
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (src_len + dst_len);
}
// int	main(void)
// {
// 	char		dest[20] = "Hello, ";
// 	const char	*src = "world!";
// 	size_t		size;
// 	size_t		result;

// 	size = sizeof(dest);
// 	result = ft_strlcat(dest, src, size);
// 	printf("Resulting string: %s\n", dest);
// 	printf("Total length: %zu\n", result);
// 	return (0);
// }
