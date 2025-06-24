/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diffuse_reflection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 16:44:15 by okaname           #+#    #+#             */
/*   Updated: 2025/06/24 19:07:43 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_color	diffuse_reflection(t_light *light, t_insec insec, int type,
		t_vec camera)
{
	t_vec	l;
	double	r;

	if (!insec.flag)
		return (color_init(0, 0, 0));
	l = vec_normalize(vec_sub(light->pos, insec.insec));
	r = vec_dot(insec.normal, l);
	if ((type == PLANE || type == TRIANGLE) && r < 0)
		r = -r;
	if (r < 0)
		r = 0;
	if (vec_dot(vec_sub(light->pos, insec.insec), insec.normal)
		* vec_dot(insec.normal, vec_sub(camera, insec.insec)) < 0)
		return (color_init(0, 0, 0));
	return (color_mult(light->color, color_const_mult(insec.color, r)));
}
