/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_triangle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 20:32:58 by okaname           #+#    #+#             */
/*   Updated: 2025/06/28 22:24:42 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

void	make_triangle(char **tokenlist, t_world *world)
{
	t_obj		*obj;
	t_triangle	triangle;
	t_color		color;

	if (array_count(tokenlist) != 5)
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
	triangle.p1 = token_to_vec(tokenlist[1]);
	triangle.p2 = token_to_vec(tokenlist[2]);
	triangle.p3 = token_to_vec(tokenlist[3]);
	if (!token_to_color(tokenlist[4], &color))
	{
		ft_free_array(tokenlist);
		free_world(world);
		exit(1);
	}
	triangle.color = color_normalize(color);
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
	world->set_obj |= 4;
}
