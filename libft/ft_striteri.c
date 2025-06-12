/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 14:04:22 by okaname           #+#    #+#             */
/*   Updated: 2024/11/01 18:31:52 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	if (s == NULL || (*f) == NULL)
		return ;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}

// void	to_uppercase(unsigned int i, char *c)
// {
// 	(void)i; // インデックスを使用しないため無視
// 	*c = toupper(*c);
// }

// int	main(void)
// {
// 	char	str[] = "hello";

// 	ft_striteri(str, to_uppercase);
// 	printf("Modified string: %s\n", str);
// 	return (0);
// }
