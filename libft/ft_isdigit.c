/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:09:59 by okaname           #+#    #+#             */
/*   Updated: 2024/10/27 15:24:45 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

// int	main(void)
// {
// 	char	test_chars[] = {'0', '5', '9', 'A', '!', '2', 'z'};

// 	for (size_t i = 0; i < sizeof(test_chars) / sizeof(test_chars[0]); i++)
// 	{
// 		printf("'%c' is digit: %d\n", test_chars[i], ft_isdigit(test_chars[i]));
// 	}
// 	return (0);
// }
