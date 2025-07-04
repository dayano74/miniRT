/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_nearest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 15:53:03 by okaname           #+#    #+#             */
/*   Updated: 2025/06/30 13:46:17 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"
#include "insec.h"

static void	substitute_color_normal(t_color *color1, t_color color2,
		t_vec *vec1, t_vec vec2)
{
	*color1 = color2;
	*vec1 = vec2;
}

static void	insec_info(t_ray ray, t_obj *obj, t_insec *insec, double t)
{
	insec->flag = 1;
	insec->t = t;
	insec->insec = vec_add(ray.start, vec_mult(ray.dir, t));
	if (obj->type == SPHERE)
		substitute_color_normal(&(insec->color), obj->u_object.sphere.color,
			&(insec->normal), vec_sub(insec->insec, obj->u_object.sphere.pos));
	else if (obj->type == PLANE)
		substitute_color_normal(&(insec->color), obj->u_object.plane.color,
			&(insec->normal), obj->u_object.plane.normal);
	else if (obj->type == CYLINDER)
		substitute_color_normal(&(insec->color), obj->u_object.cylinder.color,
			&(insec->normal), get_cylinder_normal(insec->insec, obj));
	else if (obj->type == TRIANGLE)
		substitute_color_normal(&(insec->color), obj->u_object.triangle.color,
			&(insec->normal), vec_cross(vec_sub(obj->u_object.triangle.p1,
					obj->u_object.triangle.p2),
				vec_sub(obj->u_object.triangle.p1, obj->u_object.triangle.p3)));
	insec->normal = vec_normalize(insec->normal);
	insec->type = obj->type;
}

static int	ray_hit_bvh(t_tnb *var, t_ray ray, t_bvh_node *node,
		t_insec *closest_hit)
{
	var->obj = node->obj;
	*closest_hit = (t_insec){0};
	closest_hit->flag = 0;
	var->t_min = -1.0;
	while (var->obj)
	{
		var->t = -1;
		if (var->obj->type == SPHERE)
			var->t = intersect_ray_sphere(ray, var->obj->u_object.sphere);
		else if (var->obj->type == PLANE)
			var->t = intersect_ray_plane(ray, var->obj->u_object.plane);
		else if (var->obj->type == CYLINDER)
			var->t = intersect_ray_cylinder(ray, var->obj->u_object.cylinder);
		else if (var->obj->type == TRIANGLE)
			var->t = intersect_ray_triangle(ray, var->obj->u_object.triangle);
		if (var->t > 0 && (var->t_min < 0 || var->t < var->t_min))
		{
			var->t_min = var->t;
			insec_info(ray, var->obj, &var->temp_hit, var->t);
			*closest_hit = var->temp_hit;
		}
		var->obj = var->obj->next;
	}
	return (closest_hit->flag == 1);
}

static void	substitute_bool(bool *hit_left, bool *hit_right)
{
	*hit_left = false;
	*hit_right = false;
}

bool	trace_nearest_bvh(t_ray ray, t_bvh_node *node, t_insec *closest_hit)
{
	t_tnb	var;

	if (!intersect_ray_aabb(ray, node->box))
		return (false);
	if (node->left == NULL && node->right == NULL && node->obj != NULL)
		return (ray_hit_bvh(&var, ray, node, closest_hit));
	substitute_bool(&var.hit_left, &var.hit_right);
	if (node->left)
		var.hit_left = trace_nearest_bvh(ray, node->left, &var.left_hit);
	if (node->right)
		var.hit_right = trace_nearest_bvh(ray, node->right, &var.right_hit);
	if (var.hit_left && var.hit_right)
	{
		if (var.left_hit.t < var.right_hit.t)
			*closest_hit = var.left_hit;
		else
			*closest_hit = var.right_hit;
	}
	else if (var.hit_left)
		*closest_hit = var.left_hit;
	else if (var.hit_right)
		*closest_hit = var.right_hit;
	else
		return (false);
	return (true);
}
