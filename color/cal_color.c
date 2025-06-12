/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:06:40 by okaname           #+#    #+#             */
/*   Updated: 2025/05/17 00:13:48 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include <stdio.h>

int	cal_color(t_color ambient, t_color diffuse, t_color specular)
{
	t_color	color;
	int		r;
	int		g;
	int		b;

	color = color_add(color_add(ambient, diffuse), specular);
	if (color.red > 1.0)
		color.red = 1.0;
	if (color.green > 1.0)
		color.green = 1.0;
	if (color.blue > 1.0)
		color.blue = 1.0;
	r = (int)(color.red * 255.999);
	g = (int)(color.green * 255.999);
	b = (int)(color.blue * 255.999);
	return ((r << 16) | (g << 8) | b);
}
