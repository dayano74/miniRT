/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_camera_dir.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 21:30:32 by okaname           #+#    #+#             */
/*   Updated: 2025/06/24 18:53:01 by okaname          ###   ########.fr       */
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

static void	move_view(t_camera *camera)
{
	t_vec	up;

	up = vec_init(0, 1, 0);
	if (vec_mag(vec_cross(up, camera->view)) < EPSILON)
		up = vec_init(0, 0, 1);
	camera->sx = vec_normalize(vec_cross(up, camera->view));
	camera->sy = vec_normalize(vec_cross(camera->view, camera->sx));
}

void	look_right_left(t_world *world, int sign)
{
	world->cameras->view = rotate_y(world->cameras->view, 3.14 / 360 * sign);
	move_view(world->cameras);
	world->mosaic_size = 21;
	raytracing(world);
	mlx_put_image_to_window(world->mlx, world->win, world->img, 0, 0);
}

void	look_up_down(t_world *world, int sign)
{
	world->cameras->view = rotate_x(world->cameras->view, 3.14 / 360 * sign);
	move_view(world->cameras);
	world->mosaic_size = 21;
	raytracing(world);
	mlx_put_image_to_window(world->mlx, world->win, world->img, 0, 0);
}
