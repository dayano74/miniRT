/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_ambient.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 22:58:03 by okaname           #+#    #+#             */
/*   Updated: 2025/07/05 18:16:38 by okaname          ###   ########.fr       */
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
		syntax_error(tokenlist, world);
	if (world->set_obj & 1)
		return (free_world(world), error_mult_set("ambient", tokenlist));
	if (!token_to_color(tokenlist[2], &color))
		error_invalid(tokenlist, world);
	if (!atof_with_error(tokenlist[1], BRIGHT_MAX, BRIGHT_MIN, &brightness))
		error_invalid(tokenlist, world);
	world->ambient = color_normalize(color_const_mult(color, brightness));
	world->set_obj |= 1;
}
