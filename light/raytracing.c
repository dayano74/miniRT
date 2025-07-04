/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 19:19:43 by okaname           #+#    #+#             */
/*   Updated: 2025/06/30 12:36:52 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

int	raytrace_pixel(t_ray ray, t_world *world, int i, int j)
{
	t_color	diffuse;
	t_color	ambient;
	t_color	specular;
	t_insec	insec;

	ray.dir = ray_dir(world, world->cameras, i, j);
	if (!trace_nearest_bvh(ray, world->bvh, &insec))
		return (0);
	ambient = ambient_light(world->ambient, insec.color, insec.flag);
	in_shadow(&insec, world->bvh, world->lights, world->cameras);
	diffuse = diffuse_reflection(world->lights, insec, insec.type,
			world->cameras->pos);
	specular = specular_reflection(ray, insec, world->lights);
	return (cal_color(ambient, diffuse, specular));
}

void	raytracing(t_world *world)
{
	t_raytracing	var;

	var.i = 0;
	var.ray.start = world->cameras->pos;
	while (var.i < world->screen_width)
	{
		var.j = 0;
		while (var.j < world->screen_height)
		{
			var.color = raytrace_pixel(var.ray, world, var.i,
					world->screen_height - var.j);
			var.x = var.i - 1;
			while (++var.x < var.i + world->mosaic_size
				&& var.x < world->screen_width)
			{
				var.y = var.j - 1;
				while (++var.y < var.j + world->mosaic_size
					&& var.y < world->screen_height)
					my_mlx_pixel_put(world, var.x, var.y, var.color);
			}
			var.j += world->mosaic_size;
		}
		var.i += world->mosaic_size;
	}
}
