/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_mult_set.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 21:15:46 by okaname           #+#    #+#             */
/*   Updated: 2025/07/05 18:11:26 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	error_mult_set(char *obj, char **tokenlist)
{
	ft_free_array(tokenlist);
	ft_putstr_fd("Error: mult ", 2);
	ft_putstr_fd(obj, 2);
	ft_putstr_fd("\n", 2);
	exit(1);
}
