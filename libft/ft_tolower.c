/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 16:24:21 by okaname           #+#    #+#             */
/*   Updated: 2024/10/27 15:52:07 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return (c + ('a' - 'A'));
	}
	return (c);
}

// int	main(void)
// {
// 	char	str[] = "Hello, World!";

// 	printf("Original: %s\n", str);
// 	ft_tolower((int *)str);
// 	printf("Lowercase: %s\n", str);
// 	return (0);
// }
