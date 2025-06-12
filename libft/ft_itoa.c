/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 13:26:19 by okaname           #+#    #+#             */
/*   Updated: 2024/10/27 15:25:23 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_num_digit(int n)
{
	int	num_digit;

	num_digit = 1;
	while (n >= 10 || n <= -10)
	{
		num_digit++;
		n /= 10;
	}
	return (num_digit);
}

char	*ft_itoa(int n)
{
	char	*char_num;
	long	l_num;
	int		num_digit;

	l_num = n;
	num_digit = ft_num_digit(n);
	if (n < 0)
	{
		num_digit++;
		l_num = -l_num;
	}
	char_num = (char *)malloc(sizeof(char) * (num_digit + 1));
	if (char_num == NULL)
		return (NULL);
	if (n < 0)
		char_num[0] = '-';
	char_num[num_digit] = '\0';
	while (l_num >= 10)
	{
		char_num[--num_digit] = '0' + (l_num % 10);
		l_num /= 10;
	}
	char_num[--num_digit] = '0' + (l_num % 10);
	return (char_num);
}

// void	test_ft_itoa(int n, const char *expected)
// {
// 	char	*result;

// 	result = ft_itoa(n);
// 	if (result == NULL)
// 	{
// 		printf("Memory allocation failed for input %d\n", n);
// 		return ;
// 	}
// 	if (strcmp(result, expected) == 0)
// 		printf("Test passed for input %d: %s\n", n, result);
// 	else
// 		printf("Test failed for input %d: got %s, expected %s\n", n, result,
// 			expected);
// 	free(result); // 動的メモリを解放
// }

// int	main(void)
// {
// 	// テストケース
// 	test_ft_itoa(123, "123");
// 	test_ft_itoa(-123, "-123");
// 	test_ft_itoa(0, "0");
// 	test_ft_itoa(2147483647, "2147483647");   // INT_MAX
// 	test_ft_itoa(-2147483648, "-2147483648"); // INT_MIN
// 	return (0);
// }
