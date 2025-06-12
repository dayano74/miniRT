/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specular_reflection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 09:08:41 by okaname           #+#    #+#             */
/*   Updated: 2025/05/17 00:54:09 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_color	specular_reflection(t_ray ray, t_insec insec, t_light *light)
{
	t_vec	l;
	t_vec	r;
	double	rdotv;

	if (!insec.flag)
		return (color_init(0, 0, 0));
	l = vec_normalize(vec_sub(insec.insec, light->pos));
	r = vec_normalize(vec_sub(vec_mult(insec.normal, 2 * vec_dot(insec.normal,
						l)), l));
	rdotv = vec_dot(r, ray.dir);
	if (rdotv < 0)
		rdotv = 0;
	return (color_const_mult(light->color, (0.3 * pow(rdotv, 8))));
}
