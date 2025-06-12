/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_plane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:52:51 by okaname           #+#    #+#             */
/*   Updated: 2025/05/17 00:53:10 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

void	make_plane(char **tokenlist, t_world *world)
{
	t_obj	*obj;
	t_plane	plane;

	obj = (t_obj *)malloc(sizeof(t_obj));
	if (obj == NULL)
		return ;
	plane.pos = token_to_vec(tokenlist[1]);
	plane.normal = token_to_vec(tokenlist[2]);
	plane.color = color_normalize(token_to_color(tokenlist[3]));
	obj->type = PLANE;
	obj->u_object.plane = plane;
	obj->next = NULL;
	if (world->objects == NULL)
		world->objects = obj;
	else
		world->last_objects->next = obj;
	world->last_objects = obj;
}
