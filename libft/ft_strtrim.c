/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 19:28:06 by okaname           #+#    #+#             */
/*   Updated: 2024/11/01 17:46:30 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isset(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*trimmed_str;
	int		length;

	if (!s1)
		return (NULL);
	start = 0;
	while (s1[start] && ft_isset(s1[start], set))
		start++;
	end = ft_strlen(s1) - 1;
	while (end > start && ft_isset(s1[end], set))
		end--;
	length = end - start + 1;
	trimmed_str = (char *)malloc(length + 1);
	if (!trimmed_str)
		return (NULL);
	ft_strlcpy(trimmed_str, s1 + start, length + 1);
	return (trimmed_str);
}

// int	main(void)
// {
// 	const char	*s1 = "     x xxxxxxxxxxxx x    x  xxxxxx xxx x x xx x  x x xx";
// 	const char	*set = "x";
// 	char		*result;

// 	result = ft_strtrim(s1, set);
// 	if (result)
// 	{
// 		printf("Trimmed String: '%s'\n", result); // "Hello, World!"
// 		free(result);                             // メモリを解放
// 	}
// 	return (0);
// }
