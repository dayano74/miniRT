/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_camera_dir.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 21:30:32 by okaname           #+#    #+#             */
/*   Updated: 2025/06/30 09:38:06 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"
#include <math.h>

static t_vec	rotate_xz(t_vec v, double angle)
{
	t_vec	r;

	r.x = cos(angle) * v.x + sin(angle) * v.z;
	r.y = v.y;
	r.z = -sin(angle) * v.x + cos(angle) * v.z;
	return (r);
}

static t_vec	rotate_axis(t_vec v, t_vec axis, double angle)
{
	t_vec	r;
	double	c;
	double	s;
	double	one_c;

	c = cos(angle);
	s = sin(angle);
	one_c = 1.0 - c;
	axis = vec_normalize(axis);
	r.x = v.x * (c + axis.x * axis.x * one_c) + v.y * (axis.x * axis.y * one_c
			- axis.z * s) + v.z * (axis.x * axis.z * one_c + axis.y * s);
	r.y = v.x * (axis.y * axis.x * one_c + axis.z * s) + v.y * (c + axis.y
			* axis.y * one_c) + v.z * (axis.y * axis.z * one_c - axis.x * s);
	r.z = v.x * (axis.z * axis.x * one_c - axis.y * s) + v.y * (axis.z * axis.y
			* one_c + axis.x * s) + v.z * (c + axis.z * axis.z * one_c);
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
	world->cameras->view = rotate_xz(world->cameras->view, 3.14 / 360 * sign);
	move_view(world->cameras);
	world->mosaic_size = 21;
	raytracing(world);
	mlx_put_image_to_window(world->mlx, world->win, world->img, 0, 0);
}

void	look_up_down(t_world *world, int sign)
{
	t_vec	axis;

	axis = vec_normalize(world->cameras->sx);
	world->cameras->view = rotate_axis(world->cameras->view, axis, 3.14 / 360
			* sign);
	move_view(world->cameras);
	world->mosaic_size = 21;
	raytracing(world);
	mlx_put_image_to_window(world->mlx, world->win, world->img, 0, 0);
}
