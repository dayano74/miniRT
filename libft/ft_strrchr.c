/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 16:09:39 by okaname           #+#    #+#             */
/*   Updated: 2024/10/27 16:01:08 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i > -1)
	{
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}

// char	*ft_strrchr(const char *str, int c);

// int	main(void)
// {
// 	const char	*str = "Hello, World!";
// 	char		*result;

// 	result = ft_strrchr(str, 'o');
// 	printf("Last occurrence of 'o': %s\n", result ? result : "NULL");
// 	result = ft_strrchr(str, 'l');
// 	printf("Last occurrence of 'l': %s\n", result ? result : "NULL");
// 	result = ft_strrchr(str, 'x'); // 存在しない文字
// 	printf("Last occurrence of 'x': %s\n", result ? result : "NULL");
// 	result = ft_strrchr(str, '\0'); // 終端文字
// 	printf("Last occurrence of '\\0': %s\n", result ? result : "NULL");
// 	return (0);
// }
