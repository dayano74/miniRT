/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_dir.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 16:54:02 by okaname           #+#    #+#             */
/*   Updated: 2025/05/17 00:29:40 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_vec	ray_dir(t_world *world, t_camera *camera, int i, int j)
{
	t_vec	dir;
	t_vec	p;
	t_vec	px;
	t_vec	py;

	px = vec_mult(camera->sx, (double)i - (world->screen_width / 2));
	py = vec_mult(camera->sy, (double)j - (world->screen_height / 2));
	p = vec_add(px, py);
	dir = vec_normalize(vec_add(p, camera->view));
	return (dir);
}
