/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 09:33:56 by okaname           #+#    #+#             */
/*   Updated: 2025/07/18 19:38:28 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_H
# define EVENT_H

void	my_mlx_pixel_put(t_world *world, int x, int y, int color);

void	setup_hooks(t_world *world);
void	go_front(t_world *world);
void	go_back(t_world *world);
void	go_left(t_world *world);
void	go_right(t_world *world);

void	look_right_left(t_world *world, int sign);
void	look_up_down(t_world *world, int sign);

void	moza_down(t_world *world);
void	moza_up(t_world *world);
void	gradual_mosaic_reveal(t_world *world);

int		mouse_press(int button, int x, int y, t_world *world);
int		mouse_release(int button, int x, int y, t_world *world);
int		mouse_move(int x, int y, t_world *world);

#endif
