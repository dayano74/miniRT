/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_light.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 19:10:01 by okaname           #+#    #+#             */
/*   Updated: 2025/07/05 18:16:50 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

void	make_light(char **tokenlist, t_world *world)
{
	t_light	*light;
	t_color	color;
	double	brightness;

	if (array_count(tokenlist) != 4)
		syntax_error(tokenlist, world);
	if (world->set_obj & 8)
		return (free_world(world), error_mult_set("light", tokenlist));
	light = (t_light *)ft_calloc(1, sizeof(t_light));
	if (light == NULL)
		error_malloc(tokenlist, world);
	world->lights = light;
	light->next = NULL;
	light->pos = token_to_vec(tokenlist[1]);
	if (!atof_with_error(tokenlist[2], BRIGHT_MAX, BRIGHT_MIN, &(brightness)))
		error_invalid(tokenlist, world);
	if (!token_to_color(tokenlist[3], &color))
		error_invalid(tokenlist, world);
	light->color = color_normalize(color_const_mult(color, brightness));
	world->set_obj |= 8;
}
