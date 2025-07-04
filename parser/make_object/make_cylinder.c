/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_cylinder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:54:46 by okaname           #+#    #+#             */
/*   Updated: 2025/06/30 11:49:51 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

void	make_cylinder(char **tokenlist, t_world *world)
{
	t_obj		*obj;
	t_cylinder	cylinder;
	t_color		color;

	if (array_count(tokenlist) != 6)
		syntax_error(tokenlist, world);
	obj = (t_obj *)malloc(sizeof(t_obj));
	if (obj == NULL)
		error_malloc(tokenlist, world);
	cylinder.pos = token_to_vec(tokenlist[1]);
	cylinder.axis = token_to_vec(tokenlist[2]);
	cylinder.dia = ft_atof(tokenlist[3]);
	cylinder.height = ft_atof(tokenlist[4]);
	if (!token_to_color(tokenlist[5], &color))
		error_invalid(tokenlist, world);
	cylinder.color = color_normalize(color);
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
