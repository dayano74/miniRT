/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 22:21:43 by okaname           #+#    #+#             */
/*   Updated: 2025/06/21 22:37:55 by dayano           ###   ########.fr       */
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
}

void	print_no_set(char *obj, int *flag)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(obj, 2);
	ft_putstr_fd(" not set\n", 2);
	*flag = 1;
}

void	check_set_obj(t_world *world)
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

int	paser(t_world *world, char *file)
{
	int		fd;
	char	*line;
	char	**lines;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		error_open(file);
	printf("[DBG] opened %s = %d\n", file, fd); fflush(stdout);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		printf("[DBG] line: \"%s\"\n", line); fflush(stdout);
		lines = ft_split(line, ' ');
		free(line);
		if (lines == NULL)
			return (free_world(world), error_malloc(), 1);
		make_obj(lines, world);
		ft_free_array(lines);
	}
	check_set_obj(world);
	return (0);
}
