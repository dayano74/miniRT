/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_to_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 23:26:11 by okaname           #+#    #+#             */
/*   Updated: 2025/06/17 20:40:10 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

t_color	token_to_color(char *token)
{
	char	**rgb;
	t_color	color;

	rgb = ft_split(token, ',');
	if (rgb == NULL)
		return (color_init(0, 0, 0));
	color = color_init(ft_atof(rgb[0]), ft_atof(rgb[1]), ft_atof(rgb[2]));
	ft_free_array(rgb);
	return (color);
}
