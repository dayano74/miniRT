/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 19:30:27 by okaname           #+#    #+#             */
/*   Updated: 2025/07/05 18:17:10 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	free_world(t_world *world)
{
	free(world->camera);
	free_lights(world->lights);
	free_objects(world->objects);
	free_bvh(world->bvh);
	mlx_destroy_image(world->mlx, world->img);
	mlx_destroy_window(world->mlx, world->win);
	mlx_destroy_display(world->mlx);
	free(world->mlx);
}
