/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insec_ray_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 15:57:34 by okaname           #+#    #+#             */
/*   Updated: 2025/05/11 15:57:51 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_vec	get_cylinder_normal(t_vec insec, t_obj *obj)
{
	(void)insec;
	(void)obj;
	return (vec_init(0, 0, 0));
}

double	intersect_ray_cylinder(t_ray ray, t_cylinder cylinder)
{
	(void)ray;
	(void)cylinder;
	return (0);
}
