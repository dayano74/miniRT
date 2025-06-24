/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_cylinder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:54:46 by okaname           #+#    #+#             */
/*   Updated: 2025/06/24 22:00:37 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

void	make_cylinder(char **tokenlist, t_world *world)
{
	t_obj		*obj;
	t_cylinder	cylinder;

	obj = (t_obj *)malloc(sizeof(t_obj));
	if (obj == NULL)
	{
		ft_free_array(tokenlist);
		free_world(world);
		error_malloc();
	}
	cylinder.pos = token_to_vec(tokenlist[1]);
	cylinder.axis = token_to_vec(tokenlist[2]);
	cylinder.dia = ft_atof(tokenlist[3]);
	cylinder.height = ft_atof(tokenlist[4]);
	cylinder.color = color_normalize(token_to_color(tokenlist[5]));
	obj->type = CYLINDER;
	obj->u_object.cylinder = cylinder;
	obj->next = NULL;
	if (world->objects == NULL)
		world->objects = obj;
	else
		world->last_objects->next = obj;
	world->last_objects = obj;
	world->set_obj |= 4;
}
