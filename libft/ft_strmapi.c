/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 13:56:01 by okaname           #+#    #+#             */
/*   Updated: 2024/11/01 18:32:50 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*result;

	i = 0;
	if (s == NULL || (*f) == NULL)
		return (NULL);
	result = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (result == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}

// char	to_uppercase(unsigned int i, char c)
// {
// 	(void)i; // インデックスは使わないので無視
// 	return (toupper(c));
// }

// int	main(void)
// {
// 	const char	*str = "hello";
// 	char		*result;

// 	result = ft_strmapi(str, to_uppercase);
// 	if (result)
// 	{
// 		printf("Original: %s\n", str);
// 		printf("Modified: %s\n", result);
// 		free(result); // 動的に確保したメモリの解放
// 	}
// 	else
// 	{
// 		printf("Memory allocation failed\n");
// 	}
// 	return (0);
// }
