/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 17:50:00 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/09/05 17:50:00 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	handle_movement(t_data *data, mlx_key_data_t keydata)
{
	if (keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_A)
		camera_yaw(&data->scene.cam, -CAM_ROT_STEP);
	else if (keydata.key == MLX_KEY_RIGHT || keydata.key == MLX_KEY_D)
		camera_yaw(&data->scene.cam, CAM_ROT_STEP);
	else if (keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_W)
		camera_pitch(&data->scene.cam, CAM_ROT_STEP);
	else if (keydata.key == MLX_KEY_DOWN || keydata.key == MLX_KEY_S)
		camera_pitch(&data->scene.cam, -CAM_ROT_STEP);
	else
		return (false);
	init_camera(&data->scene.cam, WIDTH, HEIGHT);
	render(data->img, &data->scene);
	return (true);
}
