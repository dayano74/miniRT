/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_to_vec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 23:29:45 by okaname           #+#    #+#             */
/*   Updated: 2025/08/22 17:01:39 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

bool	token_to_vec(char *token, t_vec *vec)
{
	char	**xyz;

	xyz = ft_split(token, ',');
	if (xyz == NULL)
		return (false);
	if (count_char(token, ',') != 2 || array_count(xyz) != 3)
		return (ft_putstr_fd("Error", 2), ft_putstr_fd(token, 2),
			ft_putstr_fd("\n", 2), ft_free_array(xyz), false);
	*vec = vec_init(ft_atof(xyz[0]), ft_atof(xyz[1]), ft_atof(xyz[2]));
	ft_free_array(xyz);
	return (true);
}
