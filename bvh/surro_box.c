/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   surro_box.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 14:17:36 by okaname           #+#    #+#             */
/*   Updated: 2025/05/18 15:06:32 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bvh.h"

t_aabb	surrounding_box(t_aabb box1, t_aabb box2)
{
	t_vec	small;
	t_vec	big;

	small = vec_min(box1.min, box2.min);
	big = vec_max(box1.max, box2.max);
	return ((t_aabb){small, big});
}
