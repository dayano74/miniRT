/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insec.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 15:58:01 by okaname           #+#    #+#             */
/*   Updated: 2025/05/19 21:57:34 by okaname          ###   ########.fr       */
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

t_vec		get_cylinder_normal(t_vec insec, t_obj *obj);
double		intersect_ray_cylinder(t_ray ray, t_cylinder cylinder);
double		intersect_ray_plane(t_ray ray, t_plane plane);
double		intersect_ray_sphere(t_ray ray, t_sphere sphere);
double		intersect_ray_triangle(t_ray ray, t_triangle triangle);
bool		intersect_ray_aabb(t_ray ray, t_aabb box);

#endif