/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_mult.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:05:36 by okaname           #+#    #+#             */
/*   Updated: 2025/05/18 14:41:55 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

// 積
// t_color	color_mult(t_color c1, t_color c2)
// {
// 	t_color	color;

// 	color.red = c1.red * c2.red;
// 	color.green = c1.green * c2.green;
// 	color.blue = c1.blue * c2.blue;
// 	return (color);
// }

t_color	color_mult(t_color c1, t_color c2)
{
	return ((t_color){c1.red * c2.red, c1.green * c2.green, c1.blue * c2.blue});
}
