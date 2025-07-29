/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_cylinder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:54:46 by okaname           #+#    #+#             */
/*   Updated: 2025/07/29 14:45:14 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

static void	set_obj(t_world **world, t_obj *obj)
{
	if ((*world)->objects == NULL)
		(*world)->objects = obj;
	else
		(*world)->last_objects->next = obj;
	(*world)->last_objects = obj;
}

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
	if (!atof_with_error(tokenlist[3], INT_MAX, 0, &cylinder.dia))
		error_invalid(tokenlist, world);
	if (!atof_with_error(tokenlist[4], INT_MAX, 0, &cylinder.height))
		error_invalid(tokenlist, world);
	if (!token_to_color(tokenlist[5], &color))
		return (free(obj), error_invalid(tokenlist, world));
	cylinder.color = color_normalize(color);
	obj->type = CYLINDER;
	obj->u_object.cylinder = cylinder;
	obj->next = NULL;
	set_obj(&world, obj);
	world->set_obj |= 4;
}
