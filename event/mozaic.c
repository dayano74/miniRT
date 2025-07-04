/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mozaic.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 09:38:44 by okaname           #+#    #+#             */
/*   Updated: 2025/06/30 09:39:13 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	moza_down(t_world *world)
{
	if (world->screen_height - world->mosaic_size <= 5)
		return ;
	world->mosaic_size += 5;
	raytracing(world);
	mlx_put_image_to_window(world->mlx, world->win, world->img, 0, 0);
}

void	moza_up(t_world *world)
{
	if (world->mosaic_size <= 5)
		return ;
	world->mosaic_size -= 5;
	raytracing(world);
	mlx_put_image_to_window(world->mlx, world->win, world->img, 0, 0);
}

void	gradual_mosaic_reveal(t_world *world)
{
	if (world->mosaic_size > 1)
	{
		world->mosaic_size -= 4;
		if (world->mosaic_size < 1)
			world->mosaic_size = 1;
		raytracing(world);
		mlx_put_image_to_window(world->mlx, world->win, world->img, 0, 0);
	}
}
