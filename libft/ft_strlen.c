/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 15:45:28 by okaname           #+#    #+#             */
/*   Updated: 2024/10/27 15:27:28 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

// int	main(void)
// {
// 	const char	*testStr = "Hello, World!";
// 	int			length;

// 	length = ft_strlen(testStr);
// 	printf("Length of '%s' is %d\n", testStr, length); // 結果: 13
// 	return (0);
// }
