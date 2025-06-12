/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:00:42 by okaname           #+#    #+#             */
/*   Updated: 2024/10/27 15:24:38 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	return (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z'));
}

// int	main(void)
// {
// 	char	test_chars[] = {'A', 'a', '1', '#', 'Z', '0', '9', '!', ' '};

// 	for (size_t i = 0; i < sizeof(test_chars) / sizeof(test_chars[0]); i++)
// 	{
// 		printf("'%c' is alpha: %d\n", test_chars[i], ft_isalpha(test_chars[i]));
// 	}
// 	return (0);
// }
