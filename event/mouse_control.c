/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 19:26:41 by dayano            #+#    #+#             */
/*   Updated: 2025/07/29 14:34:29 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

static void	zoom_camera(t_world *world, double zoom_factor)
{
	t_vec	dir;
	double	move_distance;

	dir.x = world->camera->dir.x;
	dir.y = world->camera->dir.y;
	dir.z = world->camera->dir.z;
	vec_normalize(dir);
	if (zoom_factor > 1.0)
		move_distance = 0.5;
	else
		move_distance = -0.5;
	world->camera->pos.x += dir.x * move_distance;
	world->camera->pos.y += dir.y * move_distance;
	world->camera->pos.z += dir.z * move_distance;
}

int	mouse_press(int button, int x, int y, t_world *world)
{
	if (button == 1)
	{
		world->input.mouse_pressed = true;
		world->input.last_mouse_x = x;
		world->input.last_mouse_y = y;
		world->input.mouse_initialized = true;
	}
	else if (button == 4)
	{
		zoom_camera(world, 1.5);
		world->mosaic_size = 21;
		raytracing(world);
		mlx_put_image_to_window(world->mlx, world->win, world->img, 0, 0);
	}
	else if (button == 5)
	{
		zoom_camera(world, 0.5);
		world->mosaic_size = 21;
		raytracing(world);
		mlx_put_image_to_window(world->mlx, world->win, world->img, 0, 0);
	}
	return (0);
}

int	mouse_release(int button, int x, int y, t_world *world)
{
	(void)x;
	(void)y;
	if (button == 1)
		world->input.mouse_pressed = false;
	return (0);
}

int	mouse_move(int x, int y, t_world *world)
{
	int	delta_x;
	int	delta_y;

	if (!world->input.mouse_pressed || !world->input.mouse_initialized)
		return (0);
	delta_x = x - world->input.last_mouse_x;
	delta_y = y - world->input.last_mouse_y;
	if (delta_x != 0)
	{
		look_right_left(world, -delta_x * 0.05);
		world->mosaic_size = 21;
	}
	if (delta_y != 0)
	{
		look_up_down(world, -delta_y * 0.05);
		world->mosaic_size = 21;
	}
	world->input.last_mouse_x = x;
	world->input.last_mouse_y = y;
	return (0);
}
