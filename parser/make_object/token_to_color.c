/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_to_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 23:26:11 by okaname           #+#    #+#             */
/*   Updated: 2025/06/24 21:36:59 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

#define COLOR_MAX 255
#define COLOR_MIN 0

t_color	token_to_color(char *token)
{
	char	**rgb;
	t_color	color;

	rgb = ft_split(token, ',');
	if (rgb == NULL)
		return (color_init(0, 0, 0));
	if (array_count(rgb) != 3)
		syntax_error();
	color = color_init(atoi_with_error(rgb[0], COLOR_MAX, COLOR_MIN),
			atoi_with_error(rgb[1], COLOR_MAX, COLOR_MIN),
			atoi_with_error(rgb[2], COLOR_MAX, COLOR_MIN));
	ft_free_array(rgb);
	return (color);
}
