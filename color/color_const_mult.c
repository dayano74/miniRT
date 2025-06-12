/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_const_mult.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:03:55 by okaname           #+#    #+#             */
/*   Updated: 2025/05/18 14:40:45 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

// 定数倍
// t_color	color_const_mult(t_color c, double k)
// {
// 	t_color	color;

// 	color.red = c.red * k;
// 	color.green = c.green * k;
// 	color.blue = c.blue * k;
// 	return (color);
// }

t_color	color_const_mult(t_color c, double k)
{
	return ((t_color){c.red * k, c.green * k, c.blue * k});
}
