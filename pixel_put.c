/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_pixel_put.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 19:20:46 by okaname           #+#    #+#             */
/*   Updated: 2025/04/27 19:21:03 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	my_mlx_pixel_put(t_world *world, int x, int y, int color)
{
	char	*dst;

	dst = world->addr + (y * world->line_length + x * (world->bits_per_pixel
				/ 8));
	*(unsigned int *)dst = color;
}
