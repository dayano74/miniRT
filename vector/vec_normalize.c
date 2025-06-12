/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_normalize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:09:49 by okaname           #+#    #+#             */
/*   Updated: 2025/05/18 14:34:23 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

// 正規化
// t_vec	vec_normalize(t_vec v)
// {
// 	t_vec	vec;
// 	double	mag;

// 	mag = vec_mag(v);
// 	vec.x = v.x / mag;
// 	vec.y = v.y / mag;
// 	vec.z = v.z / mag;
// 	return (vec);
// }

t_vec	vec_normalize(t_vec v)
{
	double	mag;

	mag = vec_mag(v);
	return ((t_vec){v.x / mag, v.y / mag, v.z / mag});
}
