/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insec_ray_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 15:57:34 by okaname           #+#    #+#             */
/*   Updated: 2025/06/21 19:47:12 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

typedef struct s_cylinder
{
	t_vec				pos;
	t_vec				axis;
	double				dia;
	double				height;
	t_color				color;
}						t_cylinder;

typedef struct s_obj
{
	enum e_objtype		type;
	union
	{
		t_sphere		sphere;
		t_plane			plane;
		t_cylinder		cylinder;
		t_triangle		triangle;
	} u_object;
	t_aabb				box;
	struct s_obj		*next;
}						t_obj;

typedef struct s_ray
{
	t_vec				start;
	t_vec				dir;
}						t_ray;


t_vec	vec_sub(t_vec v1, t_vec v2)
{
	return ((t_vec){v1.x - v2.x, v1.y - v2.y, v1.z - v2.z});
}

t_vec	vec_mult(t_vec v, double k)
{
	return ((t_vec){v.x * k, v.y * k, v.z * k});
}

t_vec	vec_normalize(t_vec v)
{
	double	mag;

	mag = vec_mag(v);
	return ((t_vec){v.x / mag, v.y / mag, v.z / mag});
}

// オブジェクトとの交点の法線ベクトルを計算する関数
t_vec	get_cylinder_normal(t_vec insec, t_obj *obj)
{

	t_cylinder	c;
	t_vec	d;
	t_vec	radial;
	t_vec	p;

	c = obj->u_object.cylinder;
	p = insec;
	d = vec_sub(insec, c.pos);
	radial = vec_sub(d, vec_mult(c.axis, vec_dot(d, c.axis)));
	return(vec_normalize(radial));
}

// レイと円柱オブジェクトとの交差判定を行い、交差点までの距離（パラメータt）を取得する関数。
// 交差していない場合、0を返す
double	intersect_ray_cylinder(t_ray ray, t_cylinder cylinder)
{
}
