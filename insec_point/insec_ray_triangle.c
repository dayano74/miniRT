/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insec_ray_triangle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 20:45:43 by okaname           #+#    #+#             */
/*   Updated: 2025/05/12 22:07:56 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

double	intersect_ray_triangle(t_ray ray, t_triangle triangle)
{
	double	d_arr[4];
	t_vec	v_arr[5];
	double	t;

	v_arr[0] = vec_sub(triangle.p2, triangle.p1);
	v_arr[1] = vec_sub(triangle.p3, triangle.p1);
	v_arr[2] = vec_cross(ray.dir, v_arr[1]);
	d_arr[0] = vec_dot(v_arr[0], v_arr[2]);
	if (d_arr[0] > -EPSILON && d_arr[0] < EPSILON)
		return (0);
	d_arr[1] = 1.0 / d_arr[0];
	v_arr[3] = vec_sub(ray.start, triangle.p1);
	d_arr[2] = d_arr[1] * vec_dot(v_arr[3], v_arr[2]);
	if (d_arr[2] < 0.0 || d_arr[2] > 1.0)
		return (false);
	v_arr[4] = vec_cross(v_arr[3], v_arr[0]);
	d_arr[3] = d_arr[1] * vec_dot(ray.dir, v_arr[4]);
	t = d_arr[1] * vec_dot(v_arr[1], v_arr[4]);
	if (d_arr[2] >= 0 && d_arr[3] >= 0 && d_arr[2] + d_arr[3] <= 1
		&& t > EPSILON)
		return (t);
	return (0.0);
}
