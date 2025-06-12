/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_aabb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 14:44:18 by okaname           #+#    #+#             */
/*   Updated: 2025/05/23 22:46:49 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser/parser.h"
#include "bvh.h"

static t_aabb	get_aabb_sphere(t_sphere sphere)
{
	t_vec	radious_vec;
	t_aabb	box;

	radious_vec = (t_vec){sphere.rad, sphere.rad, sphere.rad};
	box.min = vec_sub(sphere.pos, radious_vec);
	box.max = vec_add(sphere.pos, radious_vec);
	return (box);
}

static t_aabb	get_aabb_plane(t_plane plane)
{
	t_vec	offset;
	t_vec	center;
	t_aabb	box;

	offset = vec_init(INF, INF, INF);
	center = plane.pos;
	box.min = vec_sub(center, offset);
	box.max = vec_add(center, offset);
	return (box);
}

// t_aabb	get_aabb_cylinder(t_cylinder cy)
// {
// 	t_vec	half_height;
// 	t_vec	top;
// 	t_vec	rvec;
// 	t_aabb	top_box;
// 	t_aabb	bottom_box;
// 	t_vec	bottom;

// 	half_height = vec_mult(cy.normal, cy.height / 2.0);
// 	top = vec_add(cy.pos, half_height);
// 	bottom = vec_sub(cy.pos, half_height);
// 	rvec = vec_init(cy.radius, cy.radius, cy.radius);
// 	top_box = {.min = vec_sub(top, rvec), .max = vec_add(top, rvec)};
// 	bottom_box = {.min = vec_sub(bottom, rvec), .max = vec_add(bottom, rvec)};
// 	return (surrounding_box(top_box, bottom_box));
// }

static t_aabb	get_aabb_triangle(t_triangle tr)
{
	t_aabb	box;

	box.min = vec_min(vec_min(tr.p1, tr.p2), tr.p3);
	box.max = vec_max(vec_max(tr.p1, tr.p2), tr.p3);
	return (box);
}

t_aabb	get_aabb(t_obj *obj)
{
	if (obj->type == SPHERE)
		return (get_aabb_sphere(obj->u_object.sphere));
	if (obj->type == PLANE)
		return (get_aabb_plane(obj->u_object.plane));
	// if (obj->type == CYLINDER)
	// 	return (get_aabb_cylinder(obj->u_object.cylinder));
	if (obj->type == TRIANGLE)
		return (get_aabb_triangle(obj->u_object.triangle));
	return ((t_aabb){vec_init(0, 0, 0), vec_init(0, 0, 0)});
}
