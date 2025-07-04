/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_bvh.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 15:02:54 by okaname           #+#    #+#             */
/*   Updated: 2025/07/04 22:10:24 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

float	surface_area(t_aabb box)
{
	t_vec	size;

	size = vec_sub(box.max, box.min);
	return (2 * (size.x * size.y + size.y * size.z + size.z * size.x));
}

void	cal_cost(t_obj **objects, int start, int end, t_cal_sah *sah)
{
	sort_obj(objects, start, end, sah->axis);
	sah->prefix[0] = objects[start]->box;
	sah->i = 0;
	while (++sah->i < sah->n)
		sah->prefix[sah->i] = surrounding_box(sah->prefix[sah->i - 1],
				objects[start + sah->i]->box);
	sah->surfix[sah->n - 1] = objects[end - 1]->box;
	sah->i = sah->n - 1;
	while (--sah->i >= 0)
		sah->surfix[sah->i] = surrounding_box(objects[start + sah->i]->box,
				sah->surfix[sah->i + 1]);
	sah->i = 0;
	while (++sah->i < sah->n)
	{
		sah->cost = surface_area(sah->prefix[sah->i - 1]) * sah->i
			+ surface_area(sah->surfix[sah->i]) * (sah->n - sah->i);
		if (sah->cost < sah->best_cost)
		{
			sah->best_cost = sah->cost;
			sah->sah.best_axis = sah->axis;
			sah->sah.best_split = start + sah->i;
		}
	}
}

t_sah	cal_sah(t_obj **objects, int start, int end)
{
	t_cal_sah	sah;

	sah.n = end - start;
	sah.prefix = malloc(sizeof(t_aabb) * sah.n);
	sah.surfix = malloc(sizeof(t_aabb) * sah.n);
	if (!sah.prefix || !sah.surfix)
		return (free(sah.prefix), free(sah.surfix), sah.sah);
	sah.best_cost = 1e30f;
	sah.axis = -1;
	while (++sah.axis < 3)
		cal_cost(objects, start, end, &sah);
	free(sah.prefix);
	free(sah.surfix);
	return (sah.sah);
}

static void	make_bvh_node(t_bvh_node **node, t_obj **objects, int start,
		int end)
{
	int	i;

	i = start - 1;
	while (++i < end - 1)
		objects[i]->next = objects[i + 1];
	objects[end - 1]->next = NULL;
	(*node)->obj = objects[start];
	(*node)->left = NULL;
	(*node)->right = NULL;
	(*node)->box = get_aabb(objects[start]);
	i = start;
	while (++i < end)
		(*node)->box = surrounding_box((*node)->box, get_aabb(objects[i]));
}

t_bvh_node	*build_bvh(t_obj **objects, int start, int end)
{
	t_bvh_node	*node;
	int			count;
	t_sah		sah;

	count = end - start;
	if (count <= 0)
		return (NULL);
	node = malloc(sizeof(t_bvh_node));
	if (!node)
		return (NULL);
	if (count <= 2)
	{
		make_bvh_node(&node, objects, start, end);
		return (node);
	}
	sah = cal_sah(objects, start, end);
	sort_obj(objects, start, end, sah.best_axis);
	node->left = build_bvh(objects, start, sah.best_split);
	node->right = build_bvh(objects, sah.best_split, end);
	node->obj = NULL;
	node->box = surrounding_box(node->left->box, node->right->box);
	return (node);
}
