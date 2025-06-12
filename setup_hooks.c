/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 20:26:16 by okaname           #+#    #+#             */
/*   Updated: 2025/05/18 22:43:28 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

#define MINUSKEY 45
#define EQUALKEY 61
#define ZEROKEY 48
#define WKEY 119
#define AKEY 97
#define SKEY 115
#define DKEY 100
#define RIGHTARROR 65361
#define UPARROR 65362
#define LEFTA0RROR 65363
#define DOWNARROR 65364

void	moza_down(t_world *world)
{
	if (world->screen_height - world->mosaic_size <= 5)
		return ;
	world->mosaic_size += 5;
	raytracing(world);
	mlx_put_image_to_window(world->mlx, world->win, world->img, 0, 0);
}

void	moza_up(t_world *world)
{
	if (world->mosaic_size <= 5)
		return ;
	world->mosaic_size -= 5;
	raytracing(world);
	mlx_put_image_to_window(world->mlx, world->win, world->img, 0, 0);
}

void	gradual_mosaic_reveal(t_world *world)
{
	if (world->mosaic_size > 1)
	{
		world->mosaic_size -= 4;
		if (world->mosaic_size < 1)
			world->mosaic_size = 1;
		raytracing(world);
		mlx_put_image_to_window(world->mlx, world->win, world->img, 0, 0);
	}
}

int	update_loop(t_world *world)
{
	if (world->input.move_forward)
		go_front(world);
	else if (world->input.move_backward)
		go_back(world);
	else if (world->input.move_left)
		go_left(world);
	else if (world->input.move_right)
		go_right(world);
	else if (world->input.look_left)
		look_right_left(world, 1);
	else if (world->input.look_right)
		look_right_left(world, -1);
	else if (world->input.look_up)
		look_up_down(world, -1);
	else if (world->input.look_down)
		look_up_down(world, 1);
	else if (world->input.moza_up)
		moza_up(world);
	else if (world->input.moza_down)
		moza_down(world);
	else
		gradual_mosaic_reveal(world);
	return (0);
}

int	key_press(int keycode, t_world *world)
{
	if (keycode == WKEY)
		world->input.move_forward = true;
	if (keycode == SKEY)
		world->input.move_backward = true;
	if (keycode == AKEY)
		world->input.move_left = true;
	if (keycode == DKEY)
		world->input.move_right = true;
	if (keycode == RIGHTARROR)
		world->input.look_right = true;
	if (keycode == LEFTA0RROR)
		world->input.look_left = true;
	if (keycode == UPARROR)
		world->input.look_up = true;
	if (keycode == DOWNARROR)
		world->input.look_down = true;
	if (keycode == MINUSKEY)
		world->input.moza_down = true;
	if (keycode == EQUALKEY)
		world->input.moza_up = true;
	return (0);
}

int	key_release(int keycode, t_world *world)
{
	if (keycode == WKEY)
		world->input.move_forward = false;
	if (keycode == SKEY)
		world->input.move_backward = false;
	if (keycode == AKEY)
		world->input.move_left = false;
	if (keycode == DKEY)
		world->input.move_right = false;
	if (keycode == RIGHTARROR)
		world->input.look_right = false;
	if (keycode == LEFTA0RROR)
		world->input.look_left = false;
	if (keycode == UPARROR)
		world->input.look_up = false;
	if (keycode == DOWNARROR)
		world->input.look_down = false;
	if (keycode == MINUSKEY)
		world->input.moza_down = false;
	if (keycode == EQUALKEY)
		world->input.moza_up = false;
	return (0);
}

void	setup_hooks(t_world *world)
{
	mlx_hook(world->win, 2, 1L << 0, key_press, world);
	mlx_hook(world->win, 3, 1L << 1, key_release, world);
	mlx_loop_hook(world->mlx, update_loop, world);
}
