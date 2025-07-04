/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 20:20:55 by okaname           #+#    #+#             */
/*   Updated: 2025/06/30 11:36:09 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	syntax_error(char **tokenlist, t_world *world)
{
	free_world(world);
	ft_free_array(tokenlist);
	ft_putstr_fd("syntax error\n", 2);
	exit(2);
}
