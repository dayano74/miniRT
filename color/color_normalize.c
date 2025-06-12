/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_normalize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:05:55 by okaname           #+#    #+#             */
/*   Updated: 2025/05/18 14:42:39 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

// 範囲を0~255⇒0~1
// t_color	color_normalize(t_color c)
// {
// 	t_color	color;

// 	color.red = c.red / 255;
// 	color.green = c.green / 255;
// 	color.blue = c.blue / 255;
// 	return (color);
// }

t_color	color_normalize(t_color c)
{
	return ((t_color){c.red / 255, c.green / 255, c.blue / 255});
}
