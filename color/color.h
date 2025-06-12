/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:06:11 by okaname           #+#    #+#             */
/*   Updated: 2025/05/17 00:44:18 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

typedef struct s_color
{
	double	red;
	double	green;
	double	blue;
}			t_color;

t_color		color_init(double red, double green, double blue);
t_color		color_normalize(t_color c);
t_color		color_add(t_color c1, t_color c2);
t_color		color_const_mult(t_color c, double k);
t_color		color_mult(t_color c1, t_color c2);
int			cal_color(t_color ambient, t_color diffuse, t_color specular);
void		print_color(t_color color);

#endif