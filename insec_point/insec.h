/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insec.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 15:58:01 by okaname           #+#    #+#             */
/*   Updated: 2025/07/04 21:08:24 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSEC_H
# define INSEC_H

# include "../parser/parser.h"
# include <stdbool.h>

typedef struct s_inset
{
	t_vec	insec;
	t_vec	normal;
	t_color	color;
	double	t;
	int		flag;
	int		type;
}			t_insec;

typedef struct s_intersect_ray_aabb
{
	double	txmin;
	double	txmax;
	double	tymin;
	double	tymax;
	double	tzmin;
	double	tzmax;
}			t_intersect_ray_aabb;

typedef struct s_ray_in_side
{
	double	*ray_dir;
	double	*ray_start;
	double	*box_max;
	double	*box_min;
	double	*tmax;
	double	*tmin;
}			t_ray_in_side;

typedef struct s_tnb
{
	t_insec	left_hit;
	t_insec	right_hit;
	bool	hit_left;
	bool	hit_right;
	t_obj	*obj;
	double	t_min;
	t_insec	temp_hit;
	double	t;
}			t_tnb;

t_vec		get_cylinder_normal(t_vec insec, t_obj *obj);
double		intersect_ray_cylinder(t_ray ray, t_cylinder cylinder);
double		intersect_ray_plane(t_ray ray, t_plane plane);
double		intersect_ray_sphere(t_ray ray, t_sphere sphere);
double		intersect_ray_triangle(t_ray ray, t_triangle triangle);
bool		intersect_ray_aabb(t_ray ray, t_aabb box);
bool		trace_nearest_bvh(t_ray ray, t_bvh_node *node,
				t_insec *closest_hit);

#endif