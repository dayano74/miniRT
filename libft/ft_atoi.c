/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:14:57 by okaname           #+#    #+#             */
/*   Updated: 2024/11/04 21:34:22 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int		i;
	long	num;
	int		sign;

	i = 0;
	num = 0;
	sign = 1;
	while (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '\n'
		|| nptr[i] == '\v' || nptr[i] == '\f' || nptr[i] == '\r')
		i++;
	if ((nptr[i] == '+') || (nptr[i] == '-'))
	{
		if (nptr[i] == '-')
			sign = -sign;
		i++;
	}
	while ('0' <= nptr[i] && nptr[i] <= '9')
	{
		if (sign == 1 && (num > (LONG_MAX - (nptr[i] - '0')) / 10))
			return ((int)LONG_MAX);
		else if (sign == -1 && (-num < (LONG_MIN + (nptr[i] - '0')) / 10))
			return ((int)LONG_MIN);
		num = num * 10 + (nptr[i++] - '0');
	}
	return ((int)num * sign);
}

// void	test_atoi(const char *str)
// {
// 	int	original_result;
// 	int	custom_result;

// 	original_result = atoi(str);
// 	custom_result = ft_atoi(str);
// 	printf("Input: \"%s\"\n", str);
// 	printf("atoi:   %d\n", original_result);
// 	printf("ft_atoi:%d\n", custom_result);
// }

// int	main(void)
// {
// 	// 通常の数値
// 	test_atoi("12345");
// 	test_atoi("-12345");
// 	// 空白と符号付き数値
// 	test_atoi("   +6789");
// 	test_atoi("   -6789");
// 	// 先頭に空白がある入力
// 	test_atoi("   42");
// 	// 数字以外の文字が含まれる
// 	test_atoi("123abc45");
// 	// INT_MAX、INT_MINのテスト
// 	test_atoi("2147483647");  // INT_MAX
// 	test_atoi("-2147483648"); // INT_MIN
// 	// オーバーフローのテスト
// 	test_atoi("2147483648");  // INT_MAX + 1
// 	test_atoi("-2147483649"); // INT_MIN - 1
// 	// 極端に大きな数
// 	test_atoi("999999999999999999999");
// 	test_atoi("-999999999999999999999");
// 	// NULL文字列
// 	test_atoi("");
// 	// その他の特殊な文字
// 	test_atoi("+-123");
// 	test_atoi("--123");
// 	test_atoi("++123");
// 	return (0);
// }
