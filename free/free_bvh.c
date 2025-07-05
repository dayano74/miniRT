/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bvh.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 17:36:52 by okaname           #+#    #+#             */
/*   Updated: 2025/07/05 18:22:29 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	free_bvh(t_bvh_node *bvh)
{
	if (!bvh)
		return ;
	free_bvh(bvh->left);
	free_bvh(bvh->right);
	if (bvh->obj)
		free_objects(bvh->obj);
	free(bvh);
}
