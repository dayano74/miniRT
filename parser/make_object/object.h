/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:37:33 by okaname           #+#    #+#             */
/*   Updated: 2025/05/18 22:41:06 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "../../color/color.h"
# include "../../libft/libft.h"
# include "../../vector/vec.h"
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

enum					e_objtype
{
	SPHERE,
	PLANE,
	CYLINDER,
	TRIANGLE
};

typedef struct s_sphere
{
	t_vec				pos;
	double				rad;
	t_color				color;
}						t_sphere;

typedef struct s_plane
{
	t_vec				pos;
	t_vec				normal;
	t_color				color;
}						t_plane;

typedef struct s_cylinder
{
	t_vec				pos;
	double				dia;
	double				height;
	t_color				color;
}						t_cylinder;

typedef struct s_triangle
{
	t_vec				p1;
	t_vec				p2;
	t_vec				p3;
	t_vec				normal;
	t_color				color;
}						t_triangle;

typedef struct s_aabb
{
	t_vec				min;
	t_vec				max;
}						t_aabb;

typedef struct s_obj
{
	enum e_objtype		type;
	union
	{
		t_sphere		sphere;
		t_plane			plane;
		t_cylinder		cylinder;
		t_triangle		triangle;
	} u_object;
	t_aabb				box;
	struct s_obj		*next;
}						t_obj;

typedef struct s_camera
{
	t_vec				pos;
	t_vec				dir;
	double				fov;
	t_vec				sx;
	t_vec				sy;
	t_vec				view;
}						t_camera;

typedef struct s_light
{
	t_vec				pos;
	double				brightness;
	t_color				color;
	struct s_light		*next;
}						t_light;

typedef struct s_ray
{
	t_vec				start;
	t_vec				dir;
}						t_ray;

typedef struct s_bvh_node
{
	t_aabb				box;
	t_obj				*obj;
	struct s_bvh_node	*left;
	struct s_bvh_node	*right;
}						t_bvh_node;

typedef struct s_obj_array
{
	t_obj				**obj_array;
	int					count;
}						t_obj_array;

typedef struct s_input
{
	bool				move_forward;
	bool				move_backward;
	bool				move_left;
	bool				move_right;
	bool				look_left;
	bool				look_right;
	bool				look_up;
	bool				look_down;
	bool				moza_up;
	bool				moza_down;
}						t_input;

typedef struct s_world
{
	void				*mlx;
	void				*win;
	void				*img;
	char				*addr;
	int					bits_per_pixel;
	int					line_length;
	int					endain;
	int					screen_width;
	int					screen_height;
	t_camera			*cameras;
	t_obj				*objects;
	t_obj				*last_objects;
	t_obj_array			obj_array;
	t_bvh_node			*bvh;
	t_color				ambient;
	t_light				*lights;
	int					mosaic_size;
	t_input				input;
}						t_world;

// t_obj				*make_cylinder(t_vec pos, double dia, double height,
// 						t_color color);
// t_obj				*make_plane(t_vec pos, t_vec normal, t_color color);
// t_obj				*make_sphere(t_vec pos, double dia, t_color color);
// t_obj				*make_triangle(t_vec p1, t_vec p2, t_vec p3,
// t_color color);
// t_camera			*make_camera(t_vec pos, t_vec dir, double fob, int width);
// t_light				*make_light(t_vec pos, double brightness,
// t_color color);

void					make_ambient(char **tokenlist, t_world *world);
void					make_cylinder(char **tokenlist, t_world *world);
void					make_plane(char **tokenlist, t_world *world);
void					make_sphere(char **tokenlist, t_world *world);
void					make_triangle(char **tokenlist, t_world *world);
void					make_camera(char **tokenlist, t_world *world);
void					make_light(char **tokenlist, t_world *world);

t_vec					token_to_vec(char *token);
t_color					token_to_color(char *token);

#endif