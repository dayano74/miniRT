/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_cross.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:08:00 by okaname           #+#    #+#             */
/*   Updated: 2025/05/18 14:32:45 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

// 外積
// t_vec	vec_cross(t_vec v1, t_vec v2)
// {
// 	t_vec	vec;

// 	vec.x = v1.y * v2.z - v1.z * v2.y;
// 	vec.y = v1.z * v2.x - v1.x * v2.z;
// 	vec.z = v1.x * v2.y - v1.y * v2.x;
// 	return (vec);
// }

t_vec	vec_cross(t_vec v1, t_vec v2)
{
	return ((t_vec){v1.y * v2.z - v1.z * v2.y, v1.z * v2.x - v1.x * v2.z, v1.x
		* v2.y - v1.y * v2.x});
}
