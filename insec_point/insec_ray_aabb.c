/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insec_ray_aabb.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 15:53:38 by okaname           #+#    #+#             */
/*   Updated: 2025/06/30 13:10:25 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

static void	swap_double(double *n1, double *n2)
{
	double	tmp;

	tmp = *n1;
	*n1 = *n2;
	*n2 = tmp;
}

static int	ray_in_side(t_ray_in_side *ris)
{
	if (fabs(*ris->ray_dir) < EPSILON)
	{
		if (*ris->ray_start < *ris->box_min || *ris->ray_start > *ris->box_max)
			return (1);
		*ris->tmin = -INFINITY;
		*ris->tmax = INFINITY;
	}
	else
	{
		*ris->tmin = (*ris->box_min - *ris->ray_start) / *ris->ray_dir;
		*ris->tmax = (*ris->box_max - *ris->ray_start) / *ris->ray_dir;
		if (*ris->tmin > *ris->tmax)
			swap_double(ris->tmin, ris->tmax);
	}
	return (0);
}

bool	intersect_ray_aabb(t_ray ray, t_aabb box)
{
	t_intersect_ray_aabb	var;
	t_ray_in_side			ris;

	ris = (t_ray_in_side){&ray.dir.x, &ray.start.x, &box.max.x, &box.min.x,
		&var.txmax, &var.txmin};
	if (ray_in_side(&ris))
		return (false);
	ris = (t_ray_in_side){&ray.dir.y, &ray.start.y, &box.max.y, &box.min.y,
		&var.tymax, &var.tymin};
	if (ray_in_side(&ris))
		return (false);
	if ((var.txmin > var.tymax) || (var.tymin > var.txmax))
		return (false);
	if (var.tymin > var.txmin)
		var.txmin = var.tymin;
	if (var.tymax < var.txmax)
		var.txmax = var.tymax;
	ris = (t_ray_in_side){&ray.dir.z, &ray.start.z, &box.max.z, &box.min.z,
		&var.tzmax, &var.tzmin};
	if (ray_in_side(&ris))
		return (false);
	if ((var.txmin > var.tzmax) || (var.tzmin > var.txmax))
		return (false);
	return (true);
}
