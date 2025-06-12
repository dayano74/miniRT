/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insec_ray_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 15:55:26 by okaname           #+#    #+#             */
/*   Updated: 2025/05/18 19:05:32 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

double	intersect_ray_sphere(t_ray ray, t_sphere sphere)
{
	t_vec	oc;
	double	a;
	double	b;
	double	c;
	double	d;

	oc = vec_sub(ray.start, sphere.pos);
	a = vec_dot(ray.dir, ray.dir);
	b = 2.0 * vec_dot(ray.dir, oc);
	c = vec_dot(oc, oc) - sphere.rad * sphere.rad;
	d = b * b - 4 * a * c;
	if (d <= 0)
		return (0);
	if ((-b - sqrt(d)) / (2.0 * a) > EPSILON)
		return ((-b - sqrt(d)) / (2.0 * a));
	if ((-b + sqrt(d)) / (2.0 * a) > EPSILON)
		return ((-b + sqrt(d)) / (2.0 * a));
	return (0);
}
