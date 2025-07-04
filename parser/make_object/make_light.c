/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_light.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 19:10:01 by okaname           #+#    #+#             */
/*   Updated: 2025/06/28 22:09:22 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

void	make_light(char **tokenlist, t_world *world)
{
	t_light	*light;
	t_color	color;
	double	brightness;

	if (array_count(tokenlist) != 4)
	{
		free_world(world);
		ft_free_array(tokenlist);
		syntax_error();
	}
	light = (t_light *)ft_calloc(1, sizeof(t_light));
	if (light == NULL)
	{
		ft_free_array(tokenlist);
		free_world(world);
		error_malloc();
	}
	world->lights = light;
	light->next = NULL;
	light->pos = token_to_vec(tokenlist[1]);
	if (!atof_with_error(tokenlist[2], BRIGHT_MAX, BRIGHT_MIN, &(brightness)))
	{
		ft_free_array(tokenlist);
		free_world(world);
		exit(1);
	}
	if (!token_to_color(tokenlist[3], &color))
	{
		ft_free_array(tokenlist);
		free_world(world);
		exit(1);
	}
	light->color = color_normalize(color_const_mult(color, brightness));
	world->set_obj |= 8;
}
