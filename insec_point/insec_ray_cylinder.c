/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insec_ray_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 15:57:34 by okaname           #+#    #+#             */
/*   Updated: 2025/06/30 12:13:24 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

// オブジェクトとの交点の法線ベクトルを計算する関数
t_vec	get_cylinder_normal(t_vec insec, t_obj *obj)
{
	t_cylinder	c;
	t_vec		d;
	double		h;
	t_vec		radial;

	// /* ---------- 変数宣言 ---------- */
	// t_cylinder c;
	// t_vec      d;
	// t_vec      radial;
	// t_vec      norm;
	// /* ---------- 値の取得 ---------- */
	// c = obj->u_object.cylinder;          /* 円柱データをコピー       */
	// d = vec_sub(insec, c.pos);           /* d = P - C                */
	// /* ---------- 半径方向の抽出 ---------- */
	// radial = vec_sub(
	// 			d,
	// 			vec_mult(c.axis, vec_dot(d, c.axis))
	// 		);                          /* radial = d - n(d·n)      */
	// /* ---------- 正規化して法線に ---------- */
	// norm = vec_normalize(radial);
	// /* ---------- デバッグ出力 ---------- */
	// // printf("[DBG] NORMAL: "
	// // 	"P=(%.4f, %.4f, %.4f)  "
	// // 	"N=(%.4f, %.4f, %.4f)\n",
	// // 	insec.x, insec.y, insec.z,
	// // 	norm.x,  norm.y,  norm.z);
	// // fflush(stdout);
	// return (norm);
	/* ---------- 1. 円柱データを取り出し & axis を正規化 ---------- */
	c = obj->u_object.cylinder;
	t_vec axis = vec_normalize(c.axis); // 軸方向を単位ベクトルに
	double half_h = c.height * 0.5;     // 高さの半分
	/* ---------- 2. 交点を円柱中心基準に変換 ---------- */
	//  d = P - C(center)
	d = vec_sub(insec, c.pos);
	/* ---------- 3. 軸方向成分 h を計算 ---------- */
	// h = d · axis  → -half_h…+half_h の範囲なら「側面」
	h = vec_dot(d, axis);
	/* ---------- 4. キャップ判定 ---------- */
	if (h >= half_h - EPSILON)
	{
		// 上キャップ：法線は +axis
		return (axis);
	}
	else if (h <= -half_h + EPSILON)
	{
		// 下キャップ：法線は -axis
		return (vec_mult(axis, -1));
	}
	/* ここまで来たら「側面」 */
	/* ---------- 5. 側面の法線(radial)を計算 ---------- */
	// 側面では、Pから軸方向の成分を引いたベクトルが半径方向になる
	// radial = d - axis * (d·axis)
	radial = vec_sub(d, vec_mult(axis, h));
	/* ---------- 6. radial を正規化して返す ---------- */
	return (vec_normalize(radial));
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
	const t_vec		dxn = vec_cross(ray.dir, n);
	const t_vec		ocxn = vec_cross(oc, n);
	const double	A = vec_dot(dxn, dxn);
	const double	B = 2.0 * vec_dot(dxn, ocxn);
	const double	C = vec_dot(ocxn, ocxn) - r * r;
	double			t_side;
	double			disc;
	double			sqrtD;
	double			t1;
	double			t2;
	t_vec			P;
	double			h;
	double			t_cap;
	double			denom;
	double			t0;
	t_vec			P0;
	t_vec			topCenter;
	double			t_up;
	t_vec			P1;
	t_vec			bottom;
	t_vec			d0;
	double			t_hit;

	// printf("[DBG] axis=(%.3f, %.3f, %.3f) |axis|=%.3f  r=%.3f\n",
	//        n.x, n.y, n.z,
	//        sqrt(vec_dot(n, n)),   /* ← 軸ベクトルの長さ           */
	//        r);                    /* ← 半径                       */
	// fflush(stdout);
	/* ---------- ① 側面との交差 (二次方程式) ---------- */
	t_side = INF;
	if (A > EPSILON)
	{
		disc = B * B - 4 * A * C; /* 判別式 */
		// printf("[DBG] SIDE: A=%f B=%f C=%f disc=%f\n", A, B, C, disc);
		if (disc >= 0.0)
		{
			sqrtD = sqrt(disc);
			t1 = (-B - sqrtD) / (2 * A);
			t2 = (-B + sqrtD) / (2 * A);
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
				// printf("[DBG] SIDE after height: t_side=%f  h=%f\n", t_side,
				// h);
			}
		}
	}
	/* ---------- ② 上下キャップとの交差 (円ディスク) ---------- */
	t_cap = INF;
	denom = vec_dot(ray.dir, n);
	if (fabs(denom) > EPSILON)
	{
		/* 下キャップ (h = 0) */
		bottom = vec_sub(cylinder.pos, vec_mult(n, cylinder.height * 0.5));
		t0 = vec_dot(vec_sub(bottom, ray.start), n) / denom;
		if (t0 > EPSILON)
		{
			P0 = vec_add(ray.start, vec_mult(ray.dir, t0));
			d0 = vec_sub(P0, bottom);
			if (vec_dot(d0, d0) <= r * r)
				t_cap = t0;
		}
		/* 上キャップ (h = cyl.height) */
		topCenter = vec_add(cylinder.pos, vec_mult(n, cylinder.height * 0.5));
		t_up = vec_dot(vec_sub(topCenter, ray.start), n) / denom;
		if (t_up > EPSILON)
		{
			P1 = vec_add(ray.start, vec_mult(ray.dir, t_up));
			if (vec_dot(vec_sub(P1, topCenter), vec_sub(P1, topCenter)) <= r
				* r)
				if (t_up < t_cap)
					t_cap = t_up;
		}
		// printf("[DBG] CAP: denom=%f  t0=%f  t_up=%f  t_cap=%f\n", denom, t0,
		// t_up, t_cap);
	}
	/* ---------- ③ 最も近いヒットを返す ---------- */
	t_hit = (t_side < t_cap) ? t_side : t_cap;
	// printf("[DBG] RESULT: t_side=%f  t_cap=%f  t_hit=%f\n", t_side, t_cap,
	// t_hit);
	return ((t_hit == INF) ? 0.0 : t_hit);
}
