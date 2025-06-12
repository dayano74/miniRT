/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_to_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 15:14:58 by okaname           #+#    #+#             */
/*   Updated: 2025/05/18 15:46:58 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bvh.h"

t_obj_array	list_to_array(t_obj *obj)
{
	int		count;
	int		i;
	t_obj	*tmp;
	t_obj	**obj_array;

	count = 0;
	tmp = obj;
	while (tmp)
	{
		count++;
		tmp = tmp->next;
	}
	obj_array = (t_obj **)malloc(sizeof(t_obj *) * count);
	if (obj_array == NULL)
		exit(1);
	tmp = obj;
	i = 0;
	while (i < count)
	{
		obj_array[i] = tmp;
		tmp->box = get_aabb(tmp);
		i++;
		tmp = tmp->next;
	}
	return ((t_obj_array){obj_array, count});
}
