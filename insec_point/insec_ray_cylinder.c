/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insec_ray_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 15:57:34 by okaname           #+#    #+#             */
/*   Updated: 2025/06/28 18:51:44 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

// オブジェクトとの交点の法線ベクトルを計算する関数
t_vec	get_cylinder_normal(t_vec insec, t_obj *obj)
{
	t_cylinder	c;
	t_vec		axis;
	double		half_h;
	t_vec		d;
	double		h;

	c = obj->u_object.cylinder;
	axis = vec_normalize(c.axis);
	half_h = c.height * 0.5;
	d = vec_sub(insec, c.pos);
	h = vec_dot(d, axis);
	if (h >= half_h - EPSILON)
		return axis;
	else if (h <= -half_h + EPSILON)
		return vec_mult(axis, -1);
	else
		return (vec_normalize(vec_sub(d, vec_mult(axis, h))));
}

// decrease values with
double	intersect_ray_cylinder_side(t_ray ray, t_cylinder cylinder)
{
	const double	r = cylinder.dia * 0.5;
	const t_vec		n = cylinder.axis;
	const t_vec		oc = vec_sub(ray.start, cylinder.pos);

	const t_vec	dxn = vec_cross(ray.dir, n);
	const t_vec	ocxn = vec_cross(oc, n);
	const double	A = vec_dot(dxn, dxn);
	const double	B = 2.0 * vec_dot(dxn, ocxn);
	const double	C = vec_dot(ocxn, ocxn) - r*r;

	double t_side = INF;

	double	disc;
	double	sqrtD;
	double	t1;
	double	t2;
	t_vec	P;
	double	h;

	if (A > EPSILON)
	{
		disc = B*B - 4*A*C;
		if (disc >= 0.0)
		{
			sqrtD = sqrt(disc);
			t1 = (-B - sqrtD) / (2*A);
			t2 = (-B + sqrtD) / (2*A);
			if (t1 > EPSILON)
				t_side = t1;
			if (t2 > EPSILON && t2 < t_side)
				t_side = t2;
			if (t_side != INF)
			{
				P = vec_add(ray.start, vec_mult(ray.dir, t_side));
				h = vec_dot(vec_sub(P, cylinder.pos), n);
				if (fabs(h) > cylinder.height * 0.5)
					t_side = INF;
			}
		}
	}
	return (t_side);
}

double	intersect_ray_cylinder_cap(t_ray ray, t_cylinder cylinder)
{
	const double	r = cylinder.dia * 0.5;
	const	t_vec		n = cylinder.axis;

	double	t_cap = INF;
	double	denom = vec_dot(ray.dir, n);
	double	t0;
	t_vec	P0;
	t_vec	topCenter;
	double	t_up;
	t_vec	P1;
	if (fabs(denom) > EPSILON)
	{
		/* 下キャップ (h = 0) */
		t_vec bottom = vec_sub(cylinder.pos, vec_mult(n, cylinder.height * 0.5));
		t0 = vec_dot(vec_sub(bottom, ray.start), n) / denom;
		if (t0 > EPSILON)
		{
			P0 = vec_add(ray.start, vec_mult(ray.dir, t0));
			t_vec d0 = vec_sub(P0, bottom);
			if (vec_dot(d0, d0) <= r*r)
				t_cap = t0;
		}
		/* 上キャップ (h = cyl.height) */
		topCenter = vec_add(cylinder.pos, vec_mult(n, cylinder.height * 0.5));
		t_up = vec_dot(vec_sub(topCenter, ray.start), n) / denom;
		if (t_up > EPSILON)
		{
			P1 = vec_add(ray.start, vec_mult(ray.dir, t_up));
			if (vec_dot(vec_sub(P1, topCenter), vec_sub(P1, topCenter)) <= r*r)
				if (t_up < t_cap) t_cap = t_up;
		}
	}
	return (t_cap);
}

// refact funnctions that has over 25 lines
/*
**  円柱とレイの最近交差距離を返す（ヒットなし→0）
**
**  前提： cylinder.pos   … 円柱高さの【中心点】
**        cylinder.axis  … 単位ベクトル
**        cylinder.dia   … 直径 (= 2r)
**        cylinder.height… 全高
*/
double	intersect_ray_cylinder(t_ray ray, t_cylinder cylinder)
{
	double t_side = INF;
	double	t_cap = INF;
	double t_hit;

	t_side = intersect_ray_cylinder_side(ray, cylinder);
	t_cap = intersect_ray_cylinder_cap(ray, cylinder);
	if (t_side < t_cap)
		t_hit = t_side;
	else
		t_hit = t_cap;
	if (t_hit == INF)
		return (0.0);
	else
		return (t_hit);
}
