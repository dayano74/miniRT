/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 15:14:04 by okaname           #+#    #+#             */
/*   Updated: 2025/05/18 16:34:53 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bvh.h"

static void	swap_ptr(t_obj **a, t_obj **b)
{
	t_obj	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static int	partition(t_obj **arr, int low, int high, int (*cmp)(t_obj *,
			t_obj *))
{
	t_obj	*pivot;
	int		i;
	int		j;

	pivot = arr[high];
	i = low - 1;
	j = low;
	while (j < high)
	{
		if (cmp(arr[j], pivot) <= 0)
		{
			i++;
			swap_ptr(&arr[i], &arr[j]);
		}
		j++;
	}
	swap_ptr(&arr[i + 1], &arr[high]);
	return (i + 1);
}

static void	quick_sort(t_obj **arr, int low, int high, int (*cmp)(t_obj *,
			t_obj *))
{
	int	pi;

	if (low < high)
	{
		pi = partition(arr, low, high, cmp);
		quick_sort(arr, low, pi - 1, cmp);
		quick_sort(arr, pi + 1, high, cmp);
	}
}

void	sort_obj(t_obj **obj_array, int start, int end, int axis)
{
	if (axis == 1)
		quick_sort(obj_array, start, end - 1, cmp_aabb_x);
	else if (axis == 2)
		quick_sort(obj_array, start, end - 1, cmp_aabb_y);
	else if (axis == 3)
		quick_sort(obj_array, start, end - 1, cmp_aabb_z);
}
