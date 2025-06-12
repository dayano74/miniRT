/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:09:28 by okaname           #+#    #+#             */
/*   Updated: 2025/05/18 14:33:30 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

// 定数倍
// t_vec	vec_mult(t_vec v, double k)
// {
// 	t_vec	vec;

// 	vec.x = v.x * k;
// 	vec.y = v.y * k;
// 	vec.z = v.z * k;
// 	return (vec);
// }

t_vec	vec_mult(t_vec v, double k)
{
	return ((t_vec){v.x * k, v.y * k, v.z * k});
}
