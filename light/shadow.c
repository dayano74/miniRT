/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 18:00:49 by okaname           #+#    #+#             */
/*   Updated: 2025/06/30 13:08:21 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../insec_point/insec.h"
#include "../minirt.h"
#include <stdbool.h>

static bool	hit_aabb2(t_hit_aabb *var)
{
	var->invd = 1.0 / var->dir;
	var->t0 = (var->min - var->origin) * var->invd;
	var->t1 = (var->max - var->origin) * var->invd;
	if (var->invd < 0.0)
	{
		var->temp = var->t0;
		var->t0 = var->t1;
		var->t1 = var->temp;
	}
	if (var->t0 > var->tmin)
		var->tmin = var->t0;
	if (var->t1 < var->tmax)
		var->tmax = var->t1;
	if (var->tmax <= var->tmin)
		return (false);
	return (true);
}

bool	hit_aabb(t_ray ray, t_aabb box, double max_dist)
{
	t_hit_aabb	var;

	var.tmin = 0.0;
	var.tmax = max_dist;
	var.i = -1;
	while (++var.i < 3)
	{
		var.origin = (&ray.start.x)[var.i];
		var.dir = (&ray.dir.x)[var.i];
		var.min = (&box.min.x)[var.i];
		var.max = (&box.max.x)[var.i];
		if (var.dir == 0.0)
		{
			if (var.origin < var.min || var.origin > var.max)
				return (false);
			else
				continue ;
		}
		if (!hit_aabb2(&var))
			return (false);
	}
	return (true);
}

static double	intersect_object(t_ray ray, t_obj *obj)
{
	t_obj	*tmp;
	double	t;
	double	t_min;

	tmp = obj;
	t_min = -1;
	while (tmp)
	{
		t = -1;
		if (tmp->type == SPHERE)
			t = intersect_ray_sphere(ray, tmp->u_object.sphere);
		else if (tmp->type == PLANE)
			t = intersect_ray_plane(ray, tmp->u_object.plane);
		else if (tmp->type == CYLINDER)
			t = intersect_ray_cylinder(ray, tmp->u_object.cylinder);
		else if (tmp->type == TRIANGLE)
			t = intersect_ray_triangle(ray, tmp->u_object.triangle);
		if (t > 0 && (t_min < 0 || t < t_min))
			t_min = t;
		tmp = tmp->next;
	}
	return (t_min);
}

static bool	trace_shadow_bvh(t_tsb *var)
{
	double	t;
	t_tsb	left_var;
	t_tsb	right_var;

	if (!var->node || !hit_aabb(var->ray, var->node->box, var->max_dist))
		return (false);
	if (var->node->obj)
	{
		t = intersect_object(var->ray, var->node->obj);
		if (vec_dot(var->ray.dir, var->insec->normal)
			* vec_dot(var->insec->normal, vec_sub(var->pos,
					var->insec->insec)) < 0)
			return (false);
		return (t > EPSILON && t < var->max_dist);
	}
	left_var = *var;
	left_var.node = var->node->left;
	if (trace_shadow_bvh(&left_var))
		return (true);
	right_var = *var;
	right_var.node = var->node->right;
	if (trace_shadow_bvh(&right_var))
		return (true);
	return (false);
}

void	in_shadow(t_insec *insec, t_bvh_node *bvh, t_light *light,
		t_camera *camera)
{
	t_tsb	var;

	var.ray.dir = vec_normalize(vec_sub(light->pos, insec->insec));
	var.ray.start = vec_add(insec->insec, vec_mult(var.ray.dir, EPSILON));
	var.insec = insec;
	var.node = bvh;
	var.pos = camera->pos;
	var.max_dist = vec_mag(vec_sub(light->pos, insec->insec));
	if (trace_shadow_bvh(&var))
		insec->flag = 0;
}
