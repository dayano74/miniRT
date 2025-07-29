/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atof_with_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 20:31:44 by okaname           #+#    #+#             */
/*   Updated: 2025/07/29 17:01:57 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

bool	atof_with_error(char *str, double max, double min, double *num)
{
	*num = ft_atof(str);
	if (*num > max || *num < min)
	{
		ft_putstr_fd(str, 2);
		ft_putstr_fd(" is invalid\n", 2);
		return (false);
	}
	return (true);
}
