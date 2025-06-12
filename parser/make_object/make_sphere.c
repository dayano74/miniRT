/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_sphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 16:27:43 by okaname           #+#    #+#             */
/*   Updated: 2025/05/18 17:18:08 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

void	make_sphere(char **tokenlist, t_world *world)
{
	t_obj		*obj;
	t_sphere	sphere;

	obj = (t_obj *)malloc(sizeof(t_obj));
	if (obj == NULL)
		return ;
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
}
