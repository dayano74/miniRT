/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 16:27:21 by okaname           #+#    #+#             */
/*   Updated: 2024/10/27 15:51:32 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		return (c - ('a' - 'A'));
	}
	return (c);
}

// int	main(void)
// {
// 	char	str[] = "hello, world!";

// 	printf("Original: %s\n", str);
// 	ft_toupper((int *)str);
// 	printf("Uppercase: %s\n", str);
// 	return (0);
// }
