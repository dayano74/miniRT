/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_malloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 20:31:01 by okaname           #+#    #+#             */
/*   Updated: 2025/06/30 11:42:14 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	error_malloc(char **tokenlist, t_world *world)
{
	free_world(world);
	ft_free_array(tokenlist);
	ft_putstr_fd("malloc error\n", 2);
	exit(1);
}
