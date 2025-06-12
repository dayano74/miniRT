/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 00:49:05 by okaname           #+#    #+#             */
/*   Updated: 2025/05/17 00:55:53 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_color	ambient_light(t_color ambient, t_color obj, int flag)
{
	if (!flag)
		return (color_init(0, 0, 0));
	return (color_mult(ambient, obj));
}
