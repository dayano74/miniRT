/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_invalid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 11:46:01 by okaname           #+#    #+#             */
/*   Updated: 2025/07/05 17:55:19 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	error_invalid(char **tokenlist, t_world *world)
{
	free_world(world);
	ft_free_array(tokenlist);
	exit(1);
}
