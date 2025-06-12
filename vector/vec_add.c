/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:07:07 by okaname           #+#    #+#             */
/*   Updated: 2025/05/18 14:31:53 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

//和
// t_vec	vec_add(t_vec v1, t_vec v2)
// {
// 	t_vec	vec;

// 	vec.x = v1.x + v2.x;
// 	vec.y = v1.y + v2.y;
// 	vec.z = v1.z + v2.z;
// 	return (vec);
// }

t_vec	vec_add(t_vec v1, t_vec v2)
{
	return ((t_vec){v1.x + v2.x, v1.y + v2.y, v1.z + v2.z});
}
