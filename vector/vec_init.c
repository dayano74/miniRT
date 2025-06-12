/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:08:40 by okaname           #+#    #+#             */
/*   Updated: 2025/05/18 14:32:50 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

// 作成
// t_vec	vec_init(double x, double y, double z)
// {
// 	t_vec	vec;

// 	vec.x = x;
// 	vec.y = y;
// 	vec.z = z;
// 	return (vec);
// }

t_vec	vec_init(double x, double y, double z)
{
	return ((t_vec){x, y, z});
}
