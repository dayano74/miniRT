/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:14:29 by okaname           #+#    #+#             */
/*   Updated: 2025/05/18 14:36:12 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_H
# define VEC_H

# include <math.h>

typedef struct s_vec
{
	double	x;
	double	y;
	double	z;
}			t_vec;

t_vec		vec_init(double x, double y, double z);
t_vec		vec_add(t_vec v1, t_vec v2);
t_vec		vec_sub(t_vec v1, t_vec v2);
t_vec		vec_mult(t_vec v, double k);
double		vec_dot(t_vec v1, t_vec v2);
t_vec		vec_cross(t_vec v1, t_vec v2);
double		vec_mag(t_vec v);
t_vec		vec_normalize(t_vec v);
void		print_vec(t_vec vec);
t_vec		vec_min(t_vec v1, t_vec v2);
t_vec		vec_max(t_vec v1, t_vec v2);

#endif