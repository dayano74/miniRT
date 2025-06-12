/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 11:57:59 by okaname           #+#    #+#             */
/*   Updated: 2024/10/27 15:25:51 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dest_plus;
	const unsigned char	*src_plus;

	dest_plus = dest;
	src_plus = src;
	if (dest_plus == src_plus || n == 0)
		return (dest);
	if (dest_plus < src_plus)
	{
		i = -1;
		while (++i < n)
			dest_plus[i] = src_plus[i];
	}
	else
	{
		i = n;
		while (i)
		{
			dest_plus[i - 1] = src_plus[i - 1];
			i--;
		}
	}
	return (dest);
}

// void	print_test_result(const char *test_name, const char *expected,
// 		const char *result)
// {
// 	printf("%s: %s\n", test_name, strcmp(expected,
// 			result) == 0 ? "PASS" : "FAIL");
// }

// int	main(void)
// {
// 	char	buffer1[50] = "Hello, World!";
// 	char	buffer2[50];
// 	char	overlap_buffer[50] = "1234567890";
// 	char	buffer3[50] = "No Change";
// 	char	buffer4[50] = "Overlapping Test";

// 	// テスト 1: 基本的なコピー
// 	ft_memmove(buffer2, buffer1, 13);
// 	print_test_result("Test 1", "Hello, World!", buffer2);
// 	// テスト 2: 重複しているメモリ領域のコピー
// 	ft_memmove(overlap_buffer + 2, overlap_buffer, 8);
// 	print_test_result("Test 2", "1212345670", overlap_buffer);
// 	// テスト 3: ソースとデスティネーションが同じ場合
// 	ft_memmove(buffer1, buffer1, 5);
// 	print_test_result("Test 3", "Hello, World!", buffer1); // 変わらないはず
// 	// テスト 4: nが0の場合
// 	ft_memmove(buffer3, buffer3, 0);
// 	print_test_result("Test 4", "No Change", buffer3); // 変わらないはず
// 	// テスト 5: 負のケース (オーバーフローのテスト)
// 	ft_memmove(buffer4 + 5, buffer4, 10); // 自分自身を後ろにずらす
// 	print_test_result("Test 5", "OverlTesting Test", buffer4);
// 	return (0);
// }
