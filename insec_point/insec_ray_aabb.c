/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insec_ray_aabb.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 15:53:38 by okaname           #+#    #+#             */
/*   Updated: 2025/05/18 19:42:37 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "insec.h"
#include <float.h> // DBL_EPSILON
#include <math.h>
#include <stdbool.h>

bool	intersect_ray_aabb(t_ray ray, t_aabb box)
{
	double			tmp;
	const double	epsilon = 1e-8;

	double txmin, txmax, tymin, tymax, tzmin, tzmax;
	if (fabs(ray.dir.x) < epsilon)
	{
		if (ray.start.x < box.min.x || ray.start.x > box.max.x)
			return (false);
		txmin = -INFINITY;
		txmax = INFINITY;
	}
	else
	{
		txmin = (box.min.x - ray.start.x) / ray.dir.x;
		txmax = (box.max.x - ray.start.x) / ray.dir.x;
		if (txmin > txmax)
		{
			tmp = txmin;
			txmin = txmax;
			txmax = tmp;
		}
	}
	if (fabs(ray.dir.y) < epsilon)
	{
		if (ray.start.y < box.min.y || ray.start.y > box.max.y)
			return (false);
		tymin = -INFINITY;
		tymax = INFINITY;
	}
	else
	{
		tymin = (box.min.y - ray.start.y) / ray.dir.y;
		tymax = (box.max.y - ray.start.y) / ray.dir.y;
		if (tymin > tymax)
		{
			tmp = tymin;
			tymin = tymax;
			tymax = tmp;
		}
	}
	if ((txmin > tymax) || (tymin > txmax))
		return (false);
	if (tymin > txmin)
		txmin = tymin;
	if (tymax < txmax)
		txmax = tymax;
	if (fabs(ray.dir.z) < epsilon)
	{
		if (ray.start.z < box.min.z || ray.start.z > box.max.z)
			return (false);
		tzmin = -INFINITY;
		tzmax = INFINITY;
	}
	else
	{
		tzmin = (box.min.z - ray.start.z) / ray.dir.z;
		tzmax = (box.max.z - ray.start.z) / ray.dir.z;
		if (tzmin > tzmax)
		{
			tmp = tzmin;
			tzmin = tzmax;
			tzmax = tmp;
		}
	}
	if ((txmin > tzmax) || (tzmin > txmax))
		return (false);
	return (true);
}
