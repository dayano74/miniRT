/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_sphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 16:27:43 by okaname           #+#    #+#             */
/*   Updated: 2025/06/17 21:12:21 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

void	make_sphere(char **tokenlist, t_world *world)
{
	t_obj		*obj;
	t_sphere	sphere;

	obj = (t_obj *)malloc(sizeof(t_obj));
	if (obj == NULL)
	{
		ft_free_array(tokenlist);
		free_world(world);
		error_malloc();
	}
	sphere.pos = token_to_vec(tokenlist[1]);
	sphere.rad = ft_atof(tokenlist[2]) / 2.0;
	sphere.color = color_normalize(token_to_color(tokenlist[3]));
	obj->type = SPHERE;
	obj->u_object.sphere = sphere;
	obj->next = NULL;
	if (world->objects == NULL)
		world->objects = obj;
	else
		world->last_objects->next = obj;
	world->last_objects = obj;
	world->set_obj |= 4;
}
