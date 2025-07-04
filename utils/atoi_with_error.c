/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_with_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 21:03:04 by okaname           #+#    #+#             */
/*   Updated: 2025/06/30 09:54:04 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

static int	ft_atoi_with_error(char *n, int *error_flag)
{
	int		i;
	long	num;
	int		sign;

	i = 0;
	num = 0;
	sign = 1;
	if ((n[i] == '+') || (n[i] == '-'))
	{
		if (n[i] == '-')
			sign = -sign;
		i++;
	}
	while (ft_isdigit(n[i]))
	{
		if ((sign == 1 && (num > (INT_MAX - (n[i] - '0')) / 10)) || (sign == -1
				&& (-num < (INT_MIN + (n[i] - '0')) / 10)))
			*error_flag = 1;
		num = num * 10 + (n[i++] - '0');
	}
	if (!((n[i] == '\n' && n[i + 1] == '\0') || n[i] == '\0'))
		*error_flag = 1;
	return ((int)num * sign);
}

bool	atoi_with_error(char *n, int max, int min, int *num)
{
	int	flag;

	flag = 0;
	*num = ft_atoi_with_error(n, &flag);
	if (flag || *num > max || *num < min)
	{
		ft_putstr_fd("Error: ", 2);
		ft_putstr_fd(n, 2);
		ft_putstr_fd(" is invalid\n", 2);
		return (false);
	}
	return (true);
}
