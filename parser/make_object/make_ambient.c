/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_ambient.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 22:58:03 by okaname           #+#    #+#             */
/*   Updated: 2025/06/24 21:52:55 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

#define BRIGHT_MAX 1.0
#define BRIGHT_MIN 0.0

void	make_ambient(char **tokenlist, t_world *world)
{
	if (array_count(tokenlist) != 3)
		syntax_error();
	world->ambient = color_normalize(color_const_mult(token_to_color(tokenlist[2]),
				atof_with_error(tokenlist[1], BRIGHT_MAX, BRIGHT_MIN)));
	world->set_obj |= 1;
}
