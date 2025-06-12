/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:51:55 by okaname           #+#    #+#             */
/*   Updated: 2024/10/27 15:24:34 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	return (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z') || ('0' <= c
			&& c <= '9'));
}

// int	main(void)
// {
// 	char	test_chars[] = {'A', 'a', '1', '#', 'Z', '0', '9', '!', ' '};

// 	for (size_t i = 0; i < sizeof(test_chars) / sizeof(test_chars[0]); i++)
// 	{
// 		printf("'%c' is alphanumeric: %d\n", test_chars[i],
// 			ft_isalnum(test_chars[i]));
// 	}
// 	return (0);
// }
