/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_nearest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 15:53:03 by okaname           #+#    #+#             */
/*   Updated: 2025/05/18 20:00:24 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"
#include "insec.h"

static void	insec_info(t_ray ray, t_obj *obj, t_insec *insec, double t)
{
	insec->flag = 1;
	insec->t = t;
	insec->insec = vec_add(ray.start, vec_mult(ray.dir, t));
	if (obj->type == SPHERE)
	{
		insec->color = obj->u_object.sphere.color;
		insec->normal = vec_sub(insec->insec, obj->u_object.sphere.pos);
	}
	else if (obj->type == PLANE)
	{
		insec->color = obj->u_object.plane.color;
		insec->normal = obj->u_object.plane.normal;
	}
	else if (obj->type == CYLINDER)
	{
		insec->color = obj->u_object.cylinder.color;
		insec->normal = get_cylinder_normal(insec->insec, obj);
	}
	else if (obj->type == TRIANGLE)
	{
		insec->color = obj->u_object.triangle.color;
		insec->normal = vec_cross(vec_sub(obj->u_object.triangle.p1,
					obj->u_object.triangle.p2),
				vec_sub(obj->u_object.triangle.p1, obj->u_object.triangle.p3));
	}
	insec->normal = vec_normalize(insec->normal);
	insec->type = obj->type;
}

// t_insec	trace_nearest(t_ray ray, t_obj *obj)
// {
// 	t_obj	*tmp;
// 	t_insec	insec;
// 	double	t_min;
// 	double	t;

// 	tmp = obj;
// 	t_min = -1.0;
// 	insec.flag = 0;
// 	while (tmp)
// 	{
// 		if (tmp->type == SPHERE)
// 			t = intersect_ray_sphere(ray, tmp->u_object.sphere);
// 		else if (tmp->type == PLANE)
// 			t = intersect_ray_plane(ray, tmp->u_object.plane);
// 		else if (tmp->type == CYLINDER)
// 			t = intersect_ray_cylinder(ray, tmp->u_object.cylinder);
// 		else if (tmp->type == TRIANGLE)
// 			t = intersect_ray_triangle(ray, tmp->u_object.triangle);
// 		if (t > 0 && (t_min < 0 || t < t_min))
// 		{
// 			t_min = t;
// 			insec_info(ray, tmp, &insec, t_min);
// 		}
// 		tmp = tmp->next;
// 	}
// 	return (insec);
// }

bool	trace_nearest_bvh(t_ray ray, t_bvh_node *node, t_insec *closest_hit)
{
	t_insec	left_hit;
	t_insec	right_hit;
	bool	hit_left;
	bool	hit_right;
	t_obj	*obj;
	double	t_min;
	t_insec	temp_hit;
	double	t;

	if (!intersect_ray_aabb(ray, node->box))
		return (false);
	if (node->left == NULL && node->right == NULL && node->obj != NULL)
	{
		obj = node->obj;
		*closest_hit = (t_insec){0};
		closest_hit->flag = 0;
		t_min = -1.0;
		while (obj)
		{
			t = -1;
			if (obj->type == SPHERE)
				t = intersect_ray_sphere(ray, obj->u_object.sphere);
			else if (obj->type == PLANE)
				t = intersect_ray_plane(ray, obj->u_object.plane);
			else if (obj->type == CYLINDER)
				t = intersect_ray_cylinder(ray, obj->u_object.cylinder);
			else if (obj->type == TRIANGLE)
				t = intersect_ray_triangle(ray, obj->u_object.triangle);
			if (t > 0 && (t_min < 0 || t < t_min))
			{
				t_min = t;
				insec_info(ray, obj, &temp_hit, t);
				*closest_hit = temp_hit;
			}
			obj = obj->next;
		}
		return (closest_hit->flag == 1);
	}
	hit_left = false;
	hit_right = false;
	if (node->left)
		hit_left = trace_nearest_bvh(ray, node->left, &left_hit);
	if (node->right)
		hit_right = trace_nearest_bvh(ray, node->right, &right_hit);
	if (hit_left && hit_right)
	{
		if (left_hit.t < right_hit.t)
			*closest_hit = left_hit;
		else
			*closest_hit = right_hit;
	}
	else if (hit_left)
		*closest_hit = left_hit;
	else if (hit_right)
		*closest_hit = right_hit;
	else
		return (false);
	return (true);
}
