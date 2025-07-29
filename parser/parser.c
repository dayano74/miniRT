/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 22:21:43 by okaname           #+#    #+#             */
/*   Updated: 2025/07/29 21:00:17 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

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

int	get_fd(char *file, t_world *world)
{
	int	fd;

	if (!file || !*file)
	{
		free_world(world);
		error_open(file);
	}
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		free_world(world);
		error_open(file);
	}
	return (fd);
}

void	check_extension(char *file, char *ext, t_world *world)
{
	int	file_len;
	int	ext_len;

	if (!file || !ext)
	{
		free_world(world);
		ft_putstr_fd("Error: Invalid file or extension\n", 2);
		exit(1);
	}
	file_len = ft_strlen(file);
	ext_len = ft_strlen(ext);
	if (file_len < ext_len || ft_strcmp(file + file_len - ext_len, ext) != 0)
	{
		free_world(world);
		ft_putstr_fd("Error: Invalid file extension\n", 2);
		exit(1);
	}
}

int	parser(t_world *world, char *file)
{
	int		fd;
	char	*line;
	char	**lines;

	check_extension(file, ".rt", world);
	fd = get_fd(file, world);
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
