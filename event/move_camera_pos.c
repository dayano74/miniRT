/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_camera_pos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 21:04:01 by okaname           #+#    #+#             */
/*   Updated: 2025/07/04 21:11:58 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	go_front(t_world *world)
{
	world->camera->pos = vec_add(world->camera->pos,
			vec_normalize(world->camera->view));
	world->mosaic_size = 21;
	raytracing(world);
	mlx_put_image_to_window(world->mlx, world->win, world->img, 0, 0);
}

void	go_back(t_world *world)
{
	world->camera->pos = vec_sub(world->camera->pos,
			vec_normalize(world->camera->view));
	world->mosaic_size = 21;
	raytracing(world);
	mlx_put_image_to_window(world->mlx, world->win, world->img, 0, 0);
}

void	go_left(t_world *world)
{
	world->camera->pos = vec_add(world->camera->pos, vec_cross((t_vec){0, -1,
				0}, vec_normalize(world->camera->view)));
	world->mosaic_size = 21;
	raytracing(world);
	mlx_put_image_to_window(world->mlx, world->win, world->img, 0, 0);
}

void	go_right(t_world *world)
{
	world->camera->pos = vec_sub(world->camera->pos, vec_cross((t_vec){0, -1,
				0}, vec_normalize(world->camera->view)));
	world->mosaic_size = 21;
	raytracing(world);
	mlx_put_image_to_window(world->mlx, world->win, world->img, 0, 0);
}
