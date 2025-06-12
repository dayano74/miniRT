/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_to_vec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 23:29:45 by okaname           #+#    #+#             */
/*   Updated: 2025/05/16 22:20:51 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

t_vec	token_to_vec(char *token)
{
	char	**xyz;
	t_vec	vec;

	xyz = ft_split(token, ',');
	if (xyz == NULL)
		return (vec_init(0, 0, 0));
	vec = vec_init(ft_atof(xyz[0]), ft_atof(xyz[1]), ft_atof(xyz[2]));
	return (vec);
}
