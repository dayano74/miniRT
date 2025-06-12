/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 15:52:32 by okaname           #+#    #+#             */
/*   Updated: 2024/11/05 19:23:13 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	find_count;

	i = 0;
	if (little[0] == '\0')
	{
		return ((char *)big);
	}
	while (i < len && big[i] != '\0')
	{
		find_count = 0;
		if (big[i] == little[find_count])
		{
			while (big[i + find_count] == little[find_count] && (i
					+ find_count) < len)
			{
				find_count++;
				if (little[find_count] == '\0')
					return ((char *)&big[i]);
			}
		}
		i++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char		*result4;
// 	const char	*needle4 = "a";
// 	const char	*haystack = NULL;

// 	// char		*result1;
// 	// const char	*needle1 = "World";
// 	// const char	*needle3 = "Hello";
// 	// char		*result2;
// 	// char		*result3;
// 	// const char *needle2 = "world"; // 大文字小文字が違う
// 	// result1 = ft_strnstr("aabcabcd", "cd", 8);
// 	// printf("Found '%s': %s\n", needle1, result1 ? result1 : "NULL");
// 	// result2 = ft_strnstr(haystack, needle2, 13);
// 	// printf("Found '%s': %s\n", needle2, result2 ? result2 : "NULL");
// 	// result3 = ft_strnstr(haystack, needle3, 5);
// 	// printf("Found '%s': %s\n", needle3, result3 ? result3 : "NULL");
// 	result4 = ft_strnstr(haystack, needle4, 0);
// 	printf("Found '%s': %s\n", needle4, result4 ? result4 : "NULL");
// 	return (0);
// }
