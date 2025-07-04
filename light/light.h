/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 12:31:33 by okaname           #+#    #+#             */
/*   Updated: 2025/06/30 13:02:18 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include "../insec_point/insec.h"

typedef struct s_raytracing
{
	int			i;
	int			j;
	int			color;
	t_ray		ray;
	int			x;
	int			y;
}				t_raytracing;

typedef struct s_hit_aabb
{
	double		tmin;
	double		tmax;
	double		invd;
	double		origin;
	double		dir;
	double		min;
	double		max;
	double		temp;
	int			i;
	double		t0;
	double		t1;
}				t_hit_aabb;

typedef struct s_tsb
{
	t_ray		ray;
	t_bvh_node	*node;
	double		max_dist;
	t_vec		pos;
	t_insec		*insec;
}				t_tsb;

t_color			ambient_light(t_color ambient, t_color obj, int flag);
t_color			diffuse_reflection(t_light *light, t_insec insec, int type,
					t_vec camera);
t_color			specular_reflection(t_ray ray, t_insec insec, t_light *light);
void			raytracing(t_world *world);

t_vec			ray_dir(t_world *world, t_camera *camera, int i, int j);
void			in_shadow(t_insec *insec, t_bvh_node *bvh, t_light *light,
					t_camera *camera);

#endif