/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_ambient.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 22:58:03 by okaname           #+#    #+#             */
/*   Updated: 2025/05/17 00:47:35 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

void	make_ambient(char **tokenlist, t_world *world)
{
	world->ambient = color_normalize(color_const_mult(token_to_color(tokenlist[2]),
				ft_atof(tokenlist[1])));
}
