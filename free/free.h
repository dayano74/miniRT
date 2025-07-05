/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 19:44:50 by okaname           #+#    #+#             */
/*   Updated: 2025/07/05 17:49:02 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_H
# define FREE_H

# include "../parser/make_object/object.h"

void	free_lights(t_light *lights);
void	free_objects(t_obj *obj);
void	free_world(t_world *world);
void	free_bvh(t_bvh_node *bvh);

#endif