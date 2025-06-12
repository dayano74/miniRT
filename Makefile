# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: okaname <okaname@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/17 21:37:38 by okaname           #+#    #+#              #
#    Updated: 2025/02/28 13:22:34 by okaname          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
# CFLAGS = -O2 -I./includes 
CFLAGS = -Wall -Wextra -Werror -I./includes -g
LDFLAGS = -lm

MANDATORY = minirt

LIBFTDIR = ./libft
LIBFT = $(LIBFTDIR)/libft.a

PRINTFDIR = ./ft_printf
PRINTF = $(PRINTFDIR)/libftprintf.a

MLXDIR = ./mlx
MLX = $(MLXDIR)/libmlx.a
LMLX = -L$(MLXDIR) -lmlx -lXext -lX11

SRCS = main.c\
		setup_hooks.c\
		move_camera_pos.c\
		move_camera_dir.c\
		pixel_put.c\
		light/ambient_light.c\
		light/diffuse_reflection.c\
		light/specular_reflection.c\
		light/raytracing.c\
		light/ray_dir.c\
		light/shadow.c\
		insec_point/insec_ray_aabb.c\
		insec_point/insec_ray_cylinder.c\
		insec_point/insec_ray_plane.c\
		insec_point/insec_ray_sphere.c\
		insec_point/insec_ray_triangle.c\
		insec_point/trace_nearest.c\
		color/color_add.c\
		color/color_const_mult.c\
		color/color_init.c\
		color/color_mult.c\
		color/color_normalize.c\
		color/cal_color.c\
		color/print_color.c\
		vector/vec_add.c\
		vector/vec_cross.c\
		vector/vec_dot.c\
		vector/vec_init.c\
		vector/vec_mag.c\
		vector/vec_mult.c\
		vector/vec_normalize.c\
		vector/vec_sub.c\
		vector/vec_min.c\
		vector/vec_max.c\
		vector/print_vec.c\
		parser/make_object/token_to_color.c\
		parser/make_object/token_to_vec.c\
		parser/make_object/make_cylinder.c\
		parser/make_object/make_ambient.c\
		parser/make_object/make_camera.c\
		parser/make_object/make_light.c\
		parser/make_object/make_plane.c\
		parser/make_object/make_sphere.c\
		parser/make_object/make_triangle.c\
		parser/parser.c\
		bvh/build_bvh.c\
		bvh/cmp_aabb.c\
		bvh/get_aabb.c\
		bvh/list_to_array.c\
		bvh/sort_obj.c\
		bvh/surro_box.c\

OBJS = $(SRCS:.c=.o)

all: $(MANDATORY)

$(MANDATORY): $(LIBFT) $(PRINTF) $(MLX) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) $(LMLX) $(LDFLAGS) -o $@

$(LIBFT):
	make -C $(LIBFTDIR) bonus

$(PRINTF):
	make -C $(PRINTFDIR)

$(MLX):
	make -C $(MLXDIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

run:all
	./$(MANDATORY)

clean:
	rm -f $(OBJS) 
	make -C $(LIBFTDIR) clean
	make -C $(PRINTFDIR) clean
	make -C $(MLXDIR) clean

fclean: clean
	rm -f $(MANDATORY) 
	make -C $(LIBFTDIR) fclean
	make -C $(PRINTFDIR) fclean
	make -C $(MLXDIR) clean

re: fclean all

.PHONY: all clean fclean re