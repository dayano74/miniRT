/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_light.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 19:10:01 by okaname           #+#    #+#             */
/*   Updated: 2025/06/24 21:53:27 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

void	make_light(char **tokenlist, t_world *world)
{
	t_light	*light;

	light = (t_light *)malloc(sizeof(t_light));
	if (light == NULL)
	{
		ft_free_array(tokenlist);
		free_world(world);
		error_malloc();
	}
	light->pos = token_to_vec(tokenlist[1]);
	light->brightness = atof_with_error(tokenlist[2], BRIGHT_MAX, BRIGHT_MIN);
	light->color = color_normalize(color_const_mult(token_to_color(tokenlist[3]),
				light->brightness));
	light->next = NULL;
	world->lights = light;
	world->set_obj |= 8;
}
