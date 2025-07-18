/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 19:26:41 by dayano            #+#    #+#             */
/*   Updated: 2025/07/18 20:00:33 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

int	mouse_press(int button, int x, int y, t_world *world)
{
	if (button == 1)
	{
		world->input.mouse_pressed = true;
		world->input.last_mouse_x = x;
		world->input.last_mouse_y = y;
		world->input.mouse_initialized = true;
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
	int delta_x;
	int delta_y;

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
