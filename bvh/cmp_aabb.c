/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmp_aabb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 15:23:36 by okaname           #+#    #+#             */
/*   Updated: 2025/05/18 15:47:29 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bvh.h"

static t_vec	aabb_center(t_aabb box)
{
	return (vec_mult(vec_add(box.min, box.max), 0.5));
}

int	cmp_aabb_x(t_obj *a, t_obj *b)
{
	t_vec	centera;
	t_vec	centerb;

	centera = aabb_center(a->box);
	centerb = aabb_center(b->box);
	return ((centera.x > centerb.x) - (centera.x < centerb.x));
}

int	cmp_aabb_y(t_obj *a, t_obj *b)
{
	t_vec	centera;
	t_vec	centerb;

	centera = aabb_center(a->box);
	centerb = aabb_center(b->box);
	return ((centera.y > centerb.y) - (centera.y < centerb.y));
}

int	cmp_aabb_z(t_obj *a, t_obj *b)
{
	t_vec	centera;
	t_vec	centerb;

	centera = aabb_center(a->box);
	centerb = aabb_center(b->box);
	return ((centera.z > centerb.z) - (centera.z < centerb.z));
}
