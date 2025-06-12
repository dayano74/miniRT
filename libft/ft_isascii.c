/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:05:52 by okaname           #+#    #+#             */
/*   Updated: 2024/10/27 15:24:41 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	return (0 <= c && c <= 127);
}

// int	main(void)
// {
// 	int	test_chars[] = {0, 32, 65, 127, 128, 'A', 'a', '!', ' '};

// 	for (size_t i = 0; i < sizeof(test_chars) / sizeof(test_chars[0]); i++)
// 	{
// 		printf("%d is ascii: %d\n", test_chars[i], ft_isascii(test_chars[i]));
// 	}
// 	return (0);
// }
