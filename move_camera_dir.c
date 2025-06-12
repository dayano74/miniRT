/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_camera_dir.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 21:30:32 by okaname           #+#    #+#             */
/*   Updated: 2025/05/23 22:56:39 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <math.h>

t_vec	rotate_y(t_vec v, double angle)
{
	t_vec	r;

	r.x = cos(angle) * v.x + sin(angle) * v.z;
	r.y = v.y;
	r.z = -sin(angle) * v.x + cos(angle) * v.z;
	return (r);
}

t_vec	rotate_x(t_vec v, double angle)
{
	t_vec	r;

	r.y = cos(angle) * v.y + sin(angle) * v.z;
	r.x = v.x;
	r.z = -sin(angle) * v.y + cos(angle) * v.z;
	return (r);
}

void	look_right_left(t_world *world, int sign)
{
	world->cameras->view = rotate_y(world->cameras->view, 3.14 / 360 * sign);
	world->mosaic_size = 21;
	raytracing(world);
	mlx_put_image_to_window(world->mlx, world->win, world->img, 0, 0);
}

void	look_up_down(t_world *world, int sign)
{
	world->cameras->view = rotate_x(world->cameras->view, 3.14 / 360 * sign);
	world->mosaic_size = 21;
	raytracing(world);
	mlx_put_image_to_window(world->mlx, world->win, world->img, 0, 0);
}
