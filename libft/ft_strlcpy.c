/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 15:19:09 by okaname           #+#    #+#             */
/*   Updated: 2024/11/01 17:52:22 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	src_size;

	i = 0;
	src_size = ft_strlen(src);
	if (size == 0)
	{
		return (src_size);
	}
	i = 0;
	while (src[i] != '\0' && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_size);
}

// int	main(void)
// {
// 	char		dest[20];
// 	const char	*src = "Hello, World!";
// 	size_t		result;
// 	char		dest2[10];
// 	const char	*empty_src = "";
// 	char		small_dest[5];

// 	// Test 1: Normal case
// 	result = ft_strlcpy(dest, src, sizeof(dest));
// 	printf("Test 1: %s (Returned: %zu)\n", dest, result);
// 	// Test 2: Size smaller than source
// 	result = ft_strlcpy(dest2, src, sizeof(dest2));
// 	printf("Test 2: %s (Returned: %zu)\n", dest2, result);
// 	// Test 3: Size is 0
// 	result = ft_strlcpy(dest, src, 0);
// 	printf("Test 3: %s (Returned: %zu)\n", dest, result);
// 	// dest should remain unchanged
// 	// Test 4: Source is empty
// 	result = ft_strlcpy(dest, empty_src, sizeof(dest));
// 	printf("Test 4: %s (Returned: %zu)\n", dest, result);
// 	// dest should be empty
// 	// Test 5: Destination buffer too small
// 	result = ft_strlcpy(small_dest, src, sizeof(small_dest));
// 	printf("Test 5: %s (Returned: %zu)\n", small_dest, result);
// 	return (0);
// }
