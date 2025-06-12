/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 15:47:59 by okaname           #+#    #+#             */
/*   Updated: 2024/11/05 18:04:13 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
	{
		if (s1[i] != s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i++;
	}
	return (0);
}

// int	ft_strncmp(const char *s1, const char *s2, size_t n);

// int	main(void)
// {
// 	const char	*str1 = "Hello";
// 	const char	*str2 = "Hello, World!";
// 	int			result;

// 	result = ft_strncmp(str1, str2, 5);
// 	printf("Comparison result (first 5 characters): %d\n", result); // 結果: 0
// 	result = ft_strncmp(str1, str2, 10);
// 	printf("Comparison result (first 10 characters): %d\n", result);
// 		// 結果: < 0 (負の値)
// 	result = ft_strncmp(str1, "Hello", 5);
// 	printf("Comparison result (same strings): %d\n", result); // 結果: 0
// 	result = ft_strncmp(str1, "Hell", 5);
// 	printf("Comparison result (different lengths): %d\n", result);
// 		// 結果: > 0 (正の値)
// 	return (0);
// }
