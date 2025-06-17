/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insec_ray_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 15:57:34 by okaname           #+#    #+#             */
/*   Updated: 2025/06/17 21:51:15 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

// オブジェクトとの交点の法線ベクトルを計算する関数
t_vec	get_cylinder_normal(t_vec insec, t_obj *obj)
{
	t_cylinder	cylinder;
	t_vec	axis_vec;
	t_vec	point_to_center;
	t_vec	projection;
	t_vec	normal;

	double	t;

	cylinder = obj->u_object.cylinder;
	point_to_center = vec_sub(insec, cylinder.pos);
	axis_vec = vec_normalize(cylinder.axis);
	t = vec_dot(point_to_center, axis_vec);
	projection = vec_add(cylinder.pos, vec_mult(axis_vec, t));
	if (t > 0 && t < cylinder.height)
	{
		normal = vec_sub(insec, projection);
	}
	else if (t <= 0)
	{
		normal = vec_mult(axis_vec, -1);
	}
	else
	{
		normal = axis_vec;
	}
	return (vec_normalize(normal));
}

// レイと円柱オブジェクトとの交差判定を行い、交差点までの距離（パラメータt）を取得する関数。
// 交差していない場合、0を返す
double	intersect_ray_cylinder(t_ray ray, t_cylinder cylinder)
{
	t_vec	oc;
	t_vec	axis;
	double	a, b, c, discriminant;
	double	t1, t2, t_side, t_cap1, t_cap2, t_min;
	t_vec	p;

	// 円柱の軸ベクトル（正規化）
	axis = vec_normalize(cylinder.axis);

	// レイの始点から円柱の中心への方向ベクトル
	oc = vec_sub(ray.start, cylinder.pos);

	// レイの方向と円柱軸の内積
	double	ray_dot_axis = vec_dot(ray.dir, axis);
	double	oc_dot_axis = vec_dot(oc, axis);

	// 円柱の側面との交差判定のための2次方程式の係数を計算
	a = vec_dot(ray.dir, ray.dir) - ray_dot_axis * ray_dot_axis;
	b = 2.0 * (vec_dot(ray.dir, oc) - ray_dot_axis * oc_dot_axis);
	c = vec_dot(oc, oc) - oc_dot_axis * oc_dot_axis - (cylinder.dia / 2) * (cylinder.dia / 2);

	// 判別式
	discriminant = b * b - 4 * a * c;

	// 交差点なし
	if (discriminant < 0)
		return (0);

	// 側面との交差点
	t1 = (-b - sqrt(discriminant)) / (2 * a);
	t2 = (-b + sqrt(discriminant)) / (2 * a);

	// t1, t2が有効かどうかを確認（側面上にあるかどうか）
	double height1 = oc_dot_axis + t1 * ray_dot_axis;
	double height2 = oc_dot_axis + t2 * ray_dot_axis;

	t_side = 0;
	if (t1 > 0 && height1 >= 0 && height1 <= cylinder.height)
		t_side = t1;
	else if (t2 > 0 && height2 >= 0 && height2 <= cylinder.height)
		t_side = t2;

	// 底面との交差判定
	t_cap1 = 0;
	t_cap2 = 0;

	// 下底面との交差
	if (ray_dot_axis != 0)
	{
		double t = -oc_dot_axis / ray_dot_axis;
		if (t > 0)
		{
			p = vec_add(ray.start, vec_mult(ray.dir, t));
			if (vec_mag(vec_sub(p, cylinder.pos)) <= cylinder.dia / 2)
				t_cap1 = t;
		}
	}

	// 上底面との交差
	if (ray_dot_axis != 0)
	{
		double t = (cylinder.height - oc_dot_axis) / ray_dot_axis;
		if (t > 0)
		{
			p = vec_add(ray.start, vec_mult(ray.dir, t));
			t_vec cap_center = vec_add(cylinder.pos, vec_mult(axis, cylinder.height));
			if (vec_mag(vec_sub(p, cap_center)) <= cylinder.dia / 2)
				t_cap2 = t;
		}
	}

	// 最も近い交差点を選択
	t_min = 0;
	if (t_side > 0)
		t_min = t_side;
	if (t_cap1 > 0 && (t_min == 0 || t_cap1 < t_min))
		t_min = t_cap1;
	if (t_cap2 > 0 && (t_min == 0 || t_cap2 < t_min))
		t_min = t_cap2;

	return (t_min);
}
