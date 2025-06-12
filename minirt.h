/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 16:43:06 by okaname           #+#    #+#             */
/*   Updated: 2025/05/19 21:57:44 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "bvh/bvh.h"
# include "color/color.h"
# include "insec_point/insec.h"
# include "mlx/mlx.h"
# include "parser/parser.h"
# include "vector/vec.h"
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

# define EPSILON 0.0001

t_color	ambient_light(t_color ambient, t_color obj, int flag);
t_color	diffuse_reflection(t_light *light, t_insec insec, int type);
t_color	specular_reflection(t_ray ray, t_insec insec, t_light *light);
void	raytracing(t_world *world);
void	my_mlx_pixel_put(t_world *world, int x, int y, int color);
t_vec	ray_dir(t_world *world, t_camera *camera, int i, int j);
void	in_shadow(t_insec *insec, t_bvh_node *bvh, t_light *light);
bool	trace_nearest_bvh(t_ray ray, t_bvh_node *node, t_insec *closest_hit);

void	setup_hooks(t_world *world);
void	go_front(t_world *world);
void	go_back(t_world *world);
void	go_left(t_world *world);
void	go_right(t_world *world);

void	look_right_left(t_world *world, int sign);
void	look_up_down(t_world *world, int sign);

#endif