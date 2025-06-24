/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 19:03:59 by okaname           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/06/24 18:52:16 by dayano           ###   ########.fr       */
=======
/*   Updated: 2025/06/24 18:50:03 by okaname          ###   ########.fr       */
>>>>>>> main
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"
#include <math.h>

void	make_camera(char **tokenlist, t_world *world)
{
	t_camera	*camera;
	t_vec		up;

	up = vec_init(0, 1, 0);
	camera = (t_camera *)malloc(sizeof(t_camera));
	if (camera == NULL)
	{
		ft_free_array(tokenlist);
		free_world(world);
		error_malloc();
	}
	camera->pos = token_to_vec(tokenlist[1]);
	camera->dir = vec_normalize(token_to_vec(tokenlist[2]));
	camera->fov = ft_atof(tokenlist[3]);
	camera->view = vec_mult(camera->dir, (world->screen_width / 2)
			/ tan((camera->fov / 2) * (3.14 / 180)));
	if (vec_mag(vec_cross(up, camera->view)) < EPSILON)
		up = vec_init(0, 0, 1);
	camera->sx = vec_normalize(vec_cross(up, camera->view));
	camera->sy = vec_normalize(vec_cross(camera->view, camera->sx));
	world->cameras = camera;
	world->set_obj |= 2;
}
