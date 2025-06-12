/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_cylinder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:54:46 by okaname           #+#    #+#             */
/*   Updated: 2025/05/16 22:08:02 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

// t_obj	*make_cylinder(t_vec pos, double dia, double height, t_color color)
// {
// 	t_obj		*obj;
// 	t_cylinder	cylinder;

// 	obj = (t_obj *)malloc(sizeof(t_obj));
// 	if (obj == NULL)
// 		return (NULL);
// 	cylinder.pos = pos;
// 	cylinder.dia = dia;
// 	cylinder.height = height;
// 	cylinder.color = color;
// 	obj->type = CYLINDER;
// 	obj->u_object.cylinder = cylinder;
// 	obj->next = NULL;
// 	return (obj);
// }

void	make_cylinder(char **lines, t_world *world)
{
	(void)lines;
	(void)world;
}
