/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 19:03:59 by okaname           #+#    #+#             */
/*   Updated: 2025/06/22 15:34:32 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"
#include <math.h>

void	make_camera(char **tokenlist, t_world *world)
{
	t_camera	*camera;

	camera = (t_camera *)malloc(sizeof(t_camera));
	if (camera == NULL)
	{
		ft_free_array(tokenlist);
		free_world(world);
		error_malloc();
	}
	camera->pos = token_to_vec(tokenlist[1]);
	camera->dir = vec_normalize(token_to_vec(tokenlist[2]));
	camera->fov = ft_atof(tokenlist[3]);
	camera->sx = vec_normalize(vec_init(1, 0, -(camera->dir.x
					/ camera->dir.z)));
	camera->sy = vec_normalize(vec_cross(camera->dir, camera->sx));
	camera->view = vec_mult(camera->dir, (world->screen_width / 2)
			/ tan((camera->fov / 2) * (3.14 / 180)));
	world->cameras = camera;
	world->set_obj |= 2;
	// t_camera	*camera;
	// t_vec		forward, world_up, right, up;
	// double		half_w, fov_r, focal;

	// /* メモリ確保・エラー処理省略 */

	// /* 1. 位置・前向き・FOV を読み込み */
	// camera->pos = token_to_vec(tokenlist[1]);
	// forward     = vec_normalize(token_to_vec(tokenlist[2]));
	// camera->fov = ft_atof(tokenlist[3]);

	// /* 2. 世界の上向き */
	// world_up = vec_init(0, 1, 0);
	// /* （forward と平行にならないようにすれば OK） */

	// /* 3. 右方向 = world_up × forward */
	// right = vec_cross(world_up, forward);
	// right = vec_normalize(right);

	// /* 4. 上方向 = forward × right */
	// up = vec_cross(forward, right);

	// /* 5. スクリーン中心までの距離（focal length） */
	// half_w = world->screen_width * 0.5;
	// fov_r  = camera->fov * M_PI / 180.0;
	// focal  = half_w / tan(fov_r * 0.5);

	// /* 6. view ベクトルを設定 */
	// camera->view = vec_mult(forward, focal);

	// /* 7. カメラ基底を格納 */
	// camera->dir = forward;
	// camera->sx  = right;
	// camera->sy  = up;

	// /* 構造体チェーンに追加 */
	// world->cameras = camera;
	// world->set_obj |= 2;
}
