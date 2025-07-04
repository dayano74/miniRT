/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 19:03:59 by okaname           #+#    #+#             */
/*   Updated: 2025/07/04 21:21:59 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"
#include <math.h>

#define FOV_MAX 180
#define FOV_MIN 0

void	make_camera(char **tokenlist, t_world *world)
{
	t_camera	*camera;
	t_vec		up;
	int			fov;

	if (array_count(tokenlist) != 4)
		syntax_error(tokenlist, world);
	up = vec_init(0, 1, 0);
	camera = (t_camera *)malloc(sizeof(t_camera));
	if (camera == NULL)
		error_malloc(tokenlist, world);
	world->camera = camera;
	camera->pos = token_to_vec(tokenlist[1]);
	camera->dir = vec_normalize(token_to_vec(tokenlist[2]));
	if (!atoi_with_error(tokenlist[3], FOV_MAX, FOV_MIN, &fov))
		error_invalid(tokenlist, world);
	camera->fov = fov;
	camera->view = vec_mult(camera->dir, (world->screen_width / 2)
			/ tan((camera->fov / 2) * (3.14 / 180)));
	if (vec_mag(vec_cross(up, camera->view)) < EPSILON)
		up = vec_init(0, 0, 1);
	camera->sx = vec_normalize(vec_cross(up, camera->view));
	camera->sy = vec_normalize(vec_cross(camera->view, camera->sx));
	if (world->set_obj & 2)
		return (free_world(world), error_mult_set("camera"));
	world->set_obj |= 2;
}
