/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_sphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 16:27:43 by okaname           #+#    #+#             */
/*   Updated: 2025/08/03 15:19:41 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

static void	make_sphere2(t_world *world, t_obj *obj)
{
	if (world->objects == NULL)
		world->objects = obj;
	else
		world->last_objects->next = obj;
	world->last_objects = obj;
	world->set_obj |= 4;
}

void	make_sphere(char **tokenlist, t_world *world)
{
	t_obj		*obj;
	t_sphere	sphere;
	t_color		color;

	if (array_count(tokenlist) != 4)
		syntax_error(tokenlist, world);
	obj = (t_obj *)malloc(sizeof(t_obj));
	if (obj == NULL)
		error_malloc(tokenlist, world);
	if (!token_to_vec(tokenlist[1], &sphere.pos))
		return (free(obj), error_invalid(tokenlist, world));
	if (!atof_with_error(tokenlist[2], INT_MAX, 0, &sphere.rad))
		error_invalid(tokenlist, world);
	sphere.rad /= 2.0;
	if (!token_to_color(tokenlist[3], &color))
		return (free(obj), error_invalid(tokenlist, world));
	sphere.color = color_normalize(color);
	obj->type = SPHERE;
	obj->u_object.sphere = sphere;
	obj->next = NULL;
	make_sphere2(world, obj);
}
