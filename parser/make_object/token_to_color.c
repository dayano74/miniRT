/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_to_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 23:26:11 by okaname           #+#    #+#             */
/*   Updated: 2025/06/30 11:38:32 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

#define COLOR_MAX 255
#define COLOR_MIN 0

bool	token_to_color(char *token, t_color *color)
{
	char	**rgb;

	rgb = ft_split(token, ',');
	if (rgb == NULL)
		return (false);
	if (array_count(rgb) != 3)
		return (false);
	if (!atof_with_error(rgb[0], COLOR_MAX, COLOR_MIN, &(color->red))
		|| !atof_with_error(rgb[1], COLOR_MAX, COLOR_MIN, &(color->green))
		|| !atof_with_error(rgb[2], COLOR_MAX, COLOR_MIN, &(color->blue)))
		return (ft_free_array(rgb), false);
	return (ft_free_array(rgb), true);
}
