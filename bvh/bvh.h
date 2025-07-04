/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bvh.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 14:17:55 by okaname           #+#    #+#             */
/*   Updated: 2025/06/30 10:34:07 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BVH_H
# define BVH_H

# include "../parser/parser.h"

# define INF 1e5

typedef struct s_get_aabb_cylinder
{
	t_vec	half_height;
	t_vec	top;
	t_vec	rvec;
	t_aabb	top_box;
	t_aabb	bottom_box;
	t_vec	bottom;
}			t_get_aabb_cylinder;

typedef struct s_sah
{
	int		best_split;
	int		best_axis;
}			t_sah;

typedef struct s_cal_sah
{
	t_sah	sah;
	float	best_cost;
	t_aabb	left_box;
	t_aabb	right_box;
	int		n_left;
	int		n_right;
	float	cost;
	int		axis;
	int		i;
}			t_cal_sah;

t_aabb		get_aabb(t_obj *obj);
t_aabb		surrounding_box(t_aabb box1, t_aabb box2);
t_obj_array	list_to_array(t_obj *obj);
int			cmp_aabb_x(t_obj *a, t_obj *b);
int			cmp_aabb_y(t_obj *a, t_obj *b);
int			cmp_aabb_z(t_obj *a, t_obj *b);
void		sort_obj(t_obj **obj_array, int start, int end, int axis);
t_bvh_node	*build_bvh(t_obj **objects, int start, int end);

#endif