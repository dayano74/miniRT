/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_ambient.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 22:58:03 by okaname           #+#    #+#             */
/*   Updated: 2025/06/28 22:25:57 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

#define BRIGHT_MAX 1.0
#define BRIGHT_MIN 0.0

void	make_ambient(char **tokenlist, t_world *world)
{
	t_color	color;
	double	brightness;

	if (array_count(tokenlist) != 3)
	{
		free_world(world);
		ft_free_array(tokenlist);
		syntax_error();
	}
	if (!token_to_color(tokenlist[2], &color))
	{
		free_world(world);
		ft_free_array(tokenlist);
		exit(1);
	}
	if (!atof_with_error(tokenlist[1], BRIGHT_MAX, BRIGHT_MIN, &brightness))
	{
		free_world(world);
		ft_free_array(tokenlist);
		exit(1);
	}
	world->ambient = color_normalize(color_const_mult(color, brightness));
	world->set_obj |= 1;
}
