/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_object.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 20:49:08 by dayano            #+#    #+#             */
/*   Updated: 2025/07/29 20:49:24 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

void	make_obj(char **lines, t_world *world)
{
	if (!ft_strcmp(lines[0], "A"))
		make_ambient(lines, world);
	else if (!ft_strcmp(lines[0], "C"))
		make_camera(lines, world);
	else if (!ft_strcmp(lines[0], "L"))
		make_light(lines, world);
	else if (!ft_strcmp(lines[0], "pl"))
		make_plane(lines, world);
	else if (!ft_strcmp(lines[0], "cy"))
		make_cylinder(lines, world);
	else if (!ft_strcmp(lines[0], "sp"))
		make_sphere(lines, world);
	else if (!ft_strcmp(lines[0], "tr"))
		make_triangle(lines, world);
	else if (ft_strcmp(lines[0], "\n"))
	{
		ft_putstr_fd("Error: ", 2);
		ft_putstr_fd(lines[0], 2);
		ft_putstr_fd("\n", 2);
		ft_free_array(lines);
		free_world(world);
		exit(1);
	}
}
