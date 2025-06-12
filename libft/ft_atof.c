/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 23:09:56 by okaname           #+#    #+#             */
/*   Updated: 2025/05/12 23:20:35 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_skip_space(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	return (i);
}

// static int	ft_isvalid(char *str)
// {
// 	int	i;
// 	int	flag;

// 	flag = 0;
// 	i = ft_skip_space(str);
// 	if (str[i] == '-' || str[i] == '+')
// 		i++;
// 	while (ft_isdigit(str[i]))
// 		i++;
// 	if (str[i] == '.')
// 		i++;
// 	while (ft_isdigit(str[i]))
// 		i++;
// 	if (str[i] != '\0' || str[i - 1] == '.')
// 		return (0);
// 	if (str[i - 1] == '-' || str[i - 1] == '+')
// 		return (0);
// 	return (1);
// }

double	ft_atof(char *str)
{
	double	result;
	double	fraction;
	int		sign;
	int		i;
	int		index;

	result = 0.0;
	fraction = 0.0;
	sign = 1;
	i = ft_skip_space(str) - 1;
	if (str[i + 1] == '-' || str[i + 1] == '+')
	{
		if (str[++i] == '-')
			sign = -1;
	}
	while (ft_isdigit(str[++i]))
		result = result * 10.0 + (str[i] - '0');
	if (str[i] == '.')
	{
		index = i;
		while (ft_isdigit(str[++i]))
			result += (str[i] - '0') / ft_pow(10.0, (i - index));
	}
	return (sign * result);
}
