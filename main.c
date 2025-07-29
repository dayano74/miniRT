/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:12:49 by okaname           #+#    #+#             */
/*   Updated: 2025/07/18 19:37:50 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parser/parser.h"
#include <stdio.h>

void	input_init(t_world *world)
{
	world->input.move_forward = false;
	world->input.move_backward = false;
	world->input.move_left = false;
	world->input.move_right = false;
	world->input.look_right = false;
	world->input.look_left = false;
	world->input.look_up = false;
	world->input.look_down = false;
	world->input.moza_down = false;
	world->input.moza_up = false;
	world->input.mouse_pressed = false;
	world->input.last_mouse_x = 0;
	world->input.last_mouse_y = 0;
	world->input.mouse_initialized = false;
}

void	window_init(t_world *world)
{
	world->screen_width = 1000;
	world->screen_height = 1000;
	world->mosaic_size = 1;
	world->camera = NULL;
	world->objects = NULL;
	world->lights = NULL;
	world->bvh = NULL;
	world->obj_array.obj_array = NULL;
	world->set_obj = 0;
	world->mlx = mlx_init();
	if (!world->mlx)
		exit(1);
	world->win = mlx_new_window(world->mlx, world->screen_width,
			world->screen_height, "minirt");
	if (!world->win)
	{
		free(world->mlx);
		exit(1);
	}
	world->img = mlx_new_image(world->mlx, world->screen_width,
			world->screen_height);
	world->addr = mlx_get_data_addr(world->img, &world->bits_per_pixel,
			&world->line_length, &world->endain);
	input_init(world);
}

int	main(int argc, char *argv[])
{
	t_world	world;

	if (argc != 2)
	{
		ft_putstr_fd("./miniRT scenes/<file.rt>\n", 2);
		exit(1);
	}
	window_init(&world);
	parser(&world, argv[1]);
	world.obj_array = list_to_array(world.objects);
	world.bvh = build_bvh(world.obj_array.obj_array, 0, world.obj_array.count);
	free(world.obj_array.obj_array);
	world.objects = NULL;
	raytracing(&world);
	printf("finished\n");
	mlx_put_image_to_window(world.mlx, world.win, world.img, 0, 0);
	setup_hooks(&world);
	mlx_loop(world.mlx);
	free_world(&world);
	return (0);
}
