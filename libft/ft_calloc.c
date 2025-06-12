/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:29:58 by okaname           #+#    #+#             */
/*   Updated: 2024/11/01 15:27:43 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;

	if (size != 0 && nmemb > SIZE_MAX / size)
		return (NULL);
	p = malloc(nmemb * size);
	if (p == NULL)
		return (NULL);
	ft_memset(p, 0, nmemb * size);
	return (p);
}

// int	main(void)
// {
// 	size_t	count;
// 	size_t	size;
// 	int		*arr;

// 	count = 5;
// 	size = sizeof(int);
// 	// int 型の配列を calloc で確保
// 	arr = (int *)ft_calloc(-5, -5);
// 	if (arr == NULL)
// 	{
// 		// メモリ確保に失敗した場合の処理
// 		return (1);
// 	}
// 	// 確保した配列を確認
// 	for (size_t i = 0; i < count; i++)
// 	{
// 		printf("%d ", arr[i]); // すべて 0 が出力される
// 	}
// 	free(arr); // 確保したメモリを解放
// 	return (0);
// }
