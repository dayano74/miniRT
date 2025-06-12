/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 14:02:00 by okaname           #+#    #+#             */
/*   Updated: 2024/11/05 18:55:48 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

// #include <stdio.h>

// int	main(void)
// {
// 	const char	*str = "Hello, World!";
// 	char		*result;
// 	char		*null_result;

// 	// 通常の文字列のテスト
// 	result = ft_strchr(str, 'o');
// 	if (result)
// 		printf("Found 'o' at: %s\n", result); // 出力: "o, World!"
// 	else
// 		printf("'o' not found.\n");
// 	// NULLポインタのテスト
// 	null_result = ft_strchr(NULL, 'o');
// 	if (null_result == NULL)
// 		printf("NULL input correctly returned NULL.\n");
// 			// 出力: NULL input correctly returned NULL.
// 	// NULL文字のテスト
// 	result = ft_strchr(str, '\0');
// 	if (result)
// 		printf("Found NULL terminator at: %s\n", result); // 出力: ""
// 	return (0);
// }
