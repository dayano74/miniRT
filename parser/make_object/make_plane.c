/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_plane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:52:51 by okaname           #+#    #+#             */
/*   Updated: 2025/06/28 22:03:59 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

void	make_plane(char **tokenlist, t_world *world)
{
	t_obj	*obj;
	t_plane	plane;
	t_color	color;

	if (array_count(tokenlist) != 4)
	{
		free_world(world);
		ft_free_array(tokenlist);
		syntax_error();
	}
	obj = (t_obj *)malloc(sizeof(t_obj));
	if (obj == NULL)
	{
		ft_free_array(tokenlist);
		free_world(world);
		error_malloc();
	}
	plane.pos = token_to_vec(tokenlist[1]);
	plane.normal = token_to_vec(tokenlist[2]);
	if (!token_to_color(tokenlist[3], &color))
	{
		ft_free_array(tokenlist);
		free_world(world);
		exit(1);
	}
	plane.color = color_normalize(color);
	obj->type = PLANE;
	obj->u_object.plane = plane;
	obj->next = NULL;
	if (world->objects == NULL)
		world->objects = obj;
	else
		world->last_objects->next = obj;
	world->last_objects = obj;
	world->set_obj |= 4;
}
