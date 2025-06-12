/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_triangle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 20:32:58 by okaname           #+#    #+#             */
/*   Updated: 2025/05/17 00:53:35 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

void	make_triangle(char **tokenlist, t_world *world)
{
	t_obj		*obj;
	t_triangle	triangle;

	obj = (t_obj *)malloc(sizeof(t_obj));
	if (obj == NULL)
		return ;
	triangle.p1 = token_to_vec(tokenlist[1]);
	triangle.p2 = token_to_vec(tokenlist[2]);
	triangle.p3 = token_to_vec(tokenlist[3]);
	triangle.color = color_normalize(token_to_color(tokenlist[4]));
	triangle.normal = vec_normalize(vec_cross(vec_sub(triangle.p1, triangle.p2),
				vec_sub(triangle.p1, triangle.p3)));
	obj->type = TRIANGLE;
	obj->u_object.triangle = triangle;
	obj->next = NULL;
	if (world->objects == NULL)
		world->objects = obj;
	else
		world->last_objects->next = obj;
	world->last_objects = obj;
}
