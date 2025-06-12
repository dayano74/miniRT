/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:12:14 by okaname           #+#    #+#             */
/*   Updated: 2024/10/27 15:24:55 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	return (32 <= c && c <= 126);
}

// int	main(void)
// {
// 	int	test_chars[] = {31, 32, 65, 126, 127, 'A', ' '};

// 	for (size_t i = 0; i < sizeof(test_chars) / sizeof(test_chars[0]); i++)
// 	{
// 		printf("%d is printable: %d\n", test_chars[i],
// 			ft_isprint(test_chars[i]));
// 	}
// 	return (0);
// }
