/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insec_ray_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 15:57:34 by okaname           #+#    #+#             */
/*   Updated: 2025/06/24 19:15:02 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

// typedef struct s_cylinder
// {
// 	t_vec				pos;
// 	t_vec				axis;
// 	double				dia;
// 	double				height;
// 	t_color				color;
// }						t_cylinder;

// typedef struct s_obj
// {
// 	enum e_objtype		type;
// 	union
// 	{
// 		t_sphere		sphere;
// 		t_plane			plane;
// 		t_cylinder		cylinder;
// 		t_triangle		triangle;
// 	} u_object;
// 	t_aabb				box;
// 	struct s_obj		*next;
// }						t_obj;

// typedef struct s_ray
// {
// 	t_vec				start;
// 	t_vec				dir;
// }						t_ray;


// t_vec	vec_sub(t_vec v1, t_vec v2)
// {
// 	return ((t_vec){v1.x - v2.x, v1.y - v2.y, v1.z - v2.z});
// }

// t_vec	vec_mult(t_vec v, double k)
// {
// 	return ((t_vec){v.x * k, v.y * k, v.z * k});
// }

// // 内積
// double	vec_dot(t_vec v1, t_vec v2)
// {
// 	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
// }

// t_vec	vec_normalize(t_vec v)
// {
// 	double	mag;

// 	mag = vec_mag(v);
// 	return ((t_vec){v.x / mag, v.y / mag, v.z / mag});
// }

// オブジェクトとの交点の法線ベクトルを計算する関数
t_vec	get_cylinder_normal(t_vec insec, t_obj *obj)
{
	// t_cylinder	c;
	// t_vec	d;
	// t_vec	radial;
	// t_vec	p;

	// c = obj->u_object.cylinder;
	// p = insec;
	// d = vec_sub(p, c.pos);
	// radial = vec_sub(d, vec_mult(c.axis, vec_dot(d, c.axis)));
	// return (vec_normalize(radial));
	/* ---------- 変数宣言 ---------- */
	t_cylinder c;
	t_vec      d;
	t_vec      radial;
	t_vec      norm;

	/* ---------- 値の取得 ---------- */
	c = obj->u_object.cylinder;          /* 円柱データをコピー       */
	d = vec_sub(insec, c.pos);           /* d = P - C                */

	/* ---------- 半径方向の抽出 ---------- */
	radial = vec_sub(
				d,
				vec_mult(c.axis, vec_dot(d, c.axis))
			);                          /* radial = d - n(d·n)      */

	/* ---------- 正規化して法線に ---------- */
	norm = vec_normalize(radial);

	/* ---------- デバッグ出力 ---------- */
	// printf("[DBG] NORMAL: "
	// 	"P=(%.4f, %.4f, %.4f)  "
	// 	"N=(%.4f, %.4f, %.4f)\n",
	// 	insec.x, insec.y, insec.z,
	// 	norm.x,  norm.y,  norm.z);
	// fflush(stdout);
	return norm;
}

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
	const double	r = cylinder.dia * 0.5;
	const t_vec		n = cylinder.axis;
	const t_vec		oc = vec_sub(ray.start, cylinder.pos);

	// printf("[DBG] axis=(%.3f, %.3f, %.3f) |axis|=%.3f  r=%.3f\n",
	//        n.x, n.y, n.z,
	//        sqrt(vec_dot(n, n)),   /* ← 軸ベクトルの長さ           */
	//        r);                    /* ← 半径                       */
	// fflush(stdout);
	/* ---------- ① 側面との交差 (二次方程式) ---------- */
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
		disc = B*B - 4*A*C; /* 判別式 */
		// printf("[DBG] SIDE: A=%f B=%f C=%f disc=%f\n", A, B, C, disc);
		if (disc >= 0.0)
		{
			sqrtD = sqrt(disc);
			t1 = (-B - sqrtD) / (2*A);
			t2 = (-B + sqrtD) / (2*A);
			// printf("[DBG] SIDE roots: t1=%f  t2=%f\n", t1, t2);
			if (t1 > EPSILON)
				t_side = t1;
			if (t2 > EPSILON && t2 < t_side)
				t_side = t2;
			/* 有限円柱の高さチェック */
			if (t_side != INF)
			{
				P = vec_add(ray.start, vec_mult(ray.dir, t_side));
				h = vec_dot(vec_sub(P, cylinder.pos), n);
				// if (h < 0.0 || h > cylinder.height * 0.5) /* はみ出し → 無効化 */
				if (fabs(h) > cylinder.height * 0.5) /* はみ出し → 無効化 */
					t_side = INF;
				// printf("[DBG] SIDE after height: t_side=%f  h=%f\n", t_side, h);
			}
		}
	}

	/* ---------- ② 上下キャップとの交差 (円ディスク) ---------- */
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
		// printf("[DBG] CAP: denom=%f  t0=%f  t_up=%f  t_cap=%f\n", denom, t0, t_up, t_cap);
	}

	/* ---------- ③ 最も近いヒットを返す ---------- */
	double t_hit;
	t_hit = (t_side < t_cap) ? t_side : t_cap;
	// printf("[DBG] RESULT: t_side=%f  t_cap=%f  t_hit=%f\n", t_side, t_cap, t_hit);
	return (t_hit == INF) ? 0.0 : t_hit;
}
