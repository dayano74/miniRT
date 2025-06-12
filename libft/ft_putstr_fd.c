/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 14:17:05 by okaname           #+#    #+#             */
/*   Updated: 2024/11/05 21:09:14 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s == NULL)
		return ;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}
// int	main(void)
// {
// 	ft_putstr("Hello, stdout!\n", 1); // 標準出力に出力
// 	ft_putstr("Hello, stderr!\n", 2); // 標準エラー出力に出力
// 	return (0);
// }
