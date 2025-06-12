/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 19:19:43 by okaname           #+#    #+#             */
/*   Updated: 2025/05/29 11:05:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../insec_point/insec.h"
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
	in_shadow(&insec, world->bvh, world->lights);
	ambient = ambient_light(world->ambient, insec.color, insec.flag);
	diffuse = diffuse_reflection(world->lights, insec, insec.type);
	specular = specular_reflection(ray, insec, world->lights);
	return (cal_color(ambient, diffuse, specular));
}

void	raytracing(t_world *world)
{
	int		i;
	int		j;
	int		color;
	t_ray	ray;
	int x;
	int y;

	i = 0;
	ray.start = world->cameras->pos;
	while (i < world->screen_width)
	{
		j = 0;
		while (j < world->screen_height)
		{
			color = raytrace_pixel(ray, world, i, j);
			x=i-1;
			while(++x < i + world->mosaic_size
				&& x < world->screen_width)
			{
				y=j-1;
				while(++y < j + world->mosaic_size
					&& y < world->screen_height)
				{
					my_mlx_pixel_put(world, x, y, color);
				}
			}
			j += world->mosaic_size;
		}
		i += world->mosaic_size;
	}
}
