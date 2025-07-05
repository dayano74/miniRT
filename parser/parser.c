/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 22:21:43 by okaname           #+#    #+#             */
/*   Updated: 2025/07/05 18:05:30 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

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

void	print_no_set(char *obj, int *flag)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(obj, 2);
	ft_putstr_fd(" unset\n", 2);
	*flag = 1;
}

void	check_unset_obj(t_world *world)
{
	int	set_obj;
	int	flag;

	set_obj = world->set_obj;
	flag = 0;
	if (!(set_obj & 1))
		print_no_set("Ambient", &flag);
	if (!(set_obj & 2))
		print_no_set("Camera", &flag);
	if (!(set_obj & 8))
		print_no_set("Light", &flag);
	if (!(set_obj & 4))
		print_no_set("Object", &flag);
	if (flag)
	{
		free_world(world);
		exit(1);
	}
}

int	parser(t_world *world, char *file)
{
	int		fd;
	char	*line;
	char	**lines;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		free_world(world);
		error_open(file);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		lines = ft_split(line, ' ');
		free(line);
		if (lines == NULL)
			return (error_malloc(NULL, world), 1);
		if (lines[0] != NULL)
			make_obj(lines, world);
		ft_free_array(lines);
	}
	check_unset_obj(world);
	return (0);
}
