/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insec_ray_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 15:57:34 by okaname           #+#    #+#             */
/*   Updated: 2025/06/28 22:36:51 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_cylinder_side_calc	init_cyl_side_calc(t_ray ray, t_cylinder cylinder)
{
	t_cylinder_side_calc	calc;

	calc.radius = cylinder.dia * 0.5;
	calc.n = vec_normalize(cylinder.axis);
	calc.oc = vec_sub(ray.start, cylinder.pos);
	calc.dxn = vec_cross(ray.dir, calc.n);
	calc.ocxn = vec_cross(calc.oc, calc.n);
	calc.a = vec_dot(calc.dxn, calc.dxn);
	calc.b = 2.0 * vec_dot(calc.dxn, calc.ocxn);
	calc.c = vec_dot(calc.ocxn, calc.ocxn) - calc.radius * calc.radius;
	return (calc);
}

double	intersect_ray_cyl_side(t_ray ray, t_cylinder cylinder, double t_side)
{
	t_cylinder_side_calc	calc;

	calc = init_cyl_side_calc(ray, cylinder);
	if (calc.a > EPSILON)
	{
		calc.disc = calc.b * calc.b - 4.0 * calc.a * calc.c;
		if (calc.disc >= 0.0)
		{
			calc.sqrt_disc = sqrt(calc.disc);
			calc.t1 = (-calc.b - calc.sqrt_disc) / (2.0 * calc.a);
			calc.t2 = (-calc.b + calc.sqrt_disc) / (2.0 * calc.a);
			if (calc.t1 > EPSILON)
				t_side = calc.t1;
			if (calc.t2 > EPSILON && calc.t2 < t_side)
				t_side = calc.t2;
			if (t_side != INF)
			{
				calc.P = vec_add(ray.start, vec_mult(ray.dir, t_side));
				calc.h = vec_dot(vec_sub(calc.P, cylinder.pos), calc.n);
				if (fabs(calc.h) > cylinder.height * 0.5)
					t_side = INF;
			}
		}
	}
	return (t_side);
}

t_cylinder_cap_calc	init_cyl_cap_calc(t_ray ray, t_cylinder cyl)
{
	t_cylinder_cap_calc	calc;

	calc.r = cyl.dia * 0.5;
	calc.n = vec_normalize(cyl.axis);
	calc.dot = vec_dot(ray.dir, calc.n);
	calc.btm_ctr = vec_sub(cyl.pos, vec_mult(calc.n, cyl.height * 0.5));
	calc.btm_t = vec_dot(vec_sub(calc.btm_ctr, ray.start), calc.n) / calc.dot;
	calc.top_ctr = vec_add(cyl.pos, vec_mult(calc.n, cyl.height * 0.5));
	calc.top_t = vec_dot(vec_sub(calc.top_ctr, ray.start), calc.n) / calc.dot;
	calc.top_dist = (t_vec){0, 0, 0};
	calc.top_dist_sq = 0.0;
	return (calc);
}

double	intersect_ray_cylinder_cap(t_ray ray, t_cylinder cyl, double t_cap)
{
	t_cylinder_cap_calc	calc;

	calc = init_cyl_cap_calc(ray, cyl);
	if (fabs(calc.dot) > EPSILON)
	{
		if (calc.btm_t > EPSILON)
		{
			calc.btm_hp = vec_add(ray.start, vec_mult(ray.dir, calc.btm_t));
			calc.btm_dist = vec_sub(calc.btm_hp, calc.btm_ctr);
			if (vec_dot(calc.btm_dist, calc.btm_dist) <= calc.r * calc.r)
				t_cap = calc.btm_t;
		}
		if (calc.top_t > EPSILON)
		{
			calc.top_hp = vec_add(ray.start, vec_mult(ray.dir, calc.top_t));
			calc.top_dist = vec_sub(calc.top_hp, calc.top_ctr);
			calc.top_dist_sq = vec_dot(calc.top_dist, calc.top_dist);
			if (calc.top_dist_sq <= calc.r * calc.r && calc.top_t < t_cap)
				t_cap = calc.top_t;
		}
	}
	return (t_cap);
}

double	intersect_ray_cylinder(t_ray ray, t_cylinder cylinder)
{
	double	t_side;
	double	t_cap;
	double	t_hit;

	t_side = INF;
	t_cap = INF;
	t_side = intersect_ray_cyl_side(ray, cylinder, t_side);
	t_cap = intersect_ray_cylinder_cap(ray, cylinder, t_cap);
	if (t_side < t_cap)
		t_hit = t_side;
	else
		t_hit = t_cap;
	if (t_hit == INF)
		return (0.0);
	else
		return (t_hit);
}
