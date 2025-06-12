/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 11:46:36 by okaname           #+#    #+#             */
/*   Updated: 2024/11/04 22:49:37 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dest_plus;
	const unsigned char	*src_plus;

	if (dest == NULL && src == NULL)
		return (NULL);
	i = 0;
	dest_plus = dest;
	src_plus = src;
	while (i < n)
	{
		dest_plus[i] = src_plus[i];
		i++;
	}
	return (dest);
}

// int	main(void)
// {
// 	char	buf1[16];
// 	char	buf2[16];

// 	// 変数定義
// 	// 変数初期化
// 	memset(buf1, '\0', 16);
// 	memset(buf2, '\0', 16);
// 	// メモリ領域を特定の文字で埋める
// 	memset(buf1, 'b', 4); // buf1の最初の4バイトをaにする
// 	memset(buf1, 'a', 2); // buf1の最初の2バイトをbにする
// 	// 配列の内容を表示
// 	printf("配列の要素を表示(コピー前)。\n");
// 	printf("buf1:%s\n", buf1);
// 	printf("buf2:%s\n", buf2);
// 	// メモリをコピーする
// 	ft_memcpy(buf2, buf1, 3); // buf1の先頭3バイトをbuf2にコピーする
// 	// 配列の内容を表示
// 	printf("配列の要素を表示(コピー後)。\n");
// 	printf("buf1:%s\n", buf1);
// 	printf("buf2:%s\n", buf2);
// 	return (0);
// }
