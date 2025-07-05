/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_to_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 23:26:11 by okaname           #+#    #+#             */
/*   Updated: 2025/07/05 18:08:44 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

#define COLOR_MAX 255
#define COLOR_MIN 0

bool	token_to_color(char *token, t_color *color)
{
	char	**rgb;
	int		array[3];

	rgb = ft_split(token, ',');
	if (rgb == NULL)
		return (false);
	if (array_count(rgb) != 3)
		return (ft_putstr_fd("Error", 2), ft_putstr_fd(token, 2),
			ft_putstr_fd("\n", 2), ft_free_array(rgb), false);
	if (!atoi_with_error(rgb[0], COLOR_MAX, COLOR_MIN, &array[0])
		|| !atoi_with_error(rgb[1], COLOR_MAX, COLOR_MIN, &array[1])
		|| !atoi_with_error(rgb[2], COLOR_MAX, COLOR_MIN, &array[2]))
		return (ft_free_array(rgb), false);
	*color = color_init(array[0], array[1], array[2]);
	return (ft_free_array(rgb), true);
}
