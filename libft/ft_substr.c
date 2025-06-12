/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 18:21:25 by okaname           #+#    #+#             */
/*   Updated: 2024/11/01 15:21:44 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*p;

	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
		return ((char *)ft_calloc(1, sizeof(char)));
	i = 0;
	if (ft_strlen(s) < start + len)
		len = ft_strlen(s) - start;
	p = (char *)malloc(sizeof(char) * (len + 1));
	if (p == NULL)
		return (NULL);
	while (s[i + start] != '\0' && i < len)
	{
		p[i] = s[i + start];
		i++;
	}
	p[i] = '\0';
	return (p);
}

// int	main(void)
// {
// 	const char	*str = "Hello, World!";
// 	char		*result;

// 	result = ft_substr(str, 7, 5);
// 	printf("Substring: %s\n", result); // "World"
// 	free(result);                      // メモリを解放
// 	result = ft_substr(str, 0, 5);
// 	printf("Substring: %s\n", result); // "Hello"
// 	free(result);
// 	result = ft_substr(str, 0, 20);
// 	printf("Substring: %s\n", result); // "Hello, World!"
// 	free(result);
// 	result = ft_substr(str, 20, 5);
// 	printf("Substring: %s\n", result); // ""（空の文字列）
// 	free(result);
// 	return (0);
// }
