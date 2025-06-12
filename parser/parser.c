/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 22:21:43 by okaname           #+#    #+#             */
/*   Updated: 2025/05/19 21:56:24 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"
#include "parser.h"

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
}

int	paser(t_world *world, char *file)
{
	int		fd;
	char	*line;
	char	**lines;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (1);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			return (1);
		lines = ft_split(line, ' ');
		free(line);
		if (lines == NULL)
			return (1);
		make_obj(lines, world);
		ft_free_array(lines);
	}
	return (0);
}
