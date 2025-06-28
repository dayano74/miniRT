/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cylinder_normal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 22:36:26 by dayano            #+#    #+#             */
/*   Updated: 2025/06/28 22:39:09 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

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
		return (axis);
	else if (h <= -half_h + EPSILON)
		return (vec_mult(axis, -1));
	else
		return (vec_normalize(vec_sub(d, vec_mult(axis, h))));
}
