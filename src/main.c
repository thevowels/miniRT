/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 16:08:39 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/09/05 16:18:56 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	key_hook(mlx_key_data_t	keydata, void	*param)
{
	t_data	*data;
	
	data = (t_data	*)param;
	if(keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(data->mlx);
}

static void	setup_dummy_scene(t_scene *scene)
{
	scene->cam.pos = (t_point){0.0, 2.0, 5.0};
	scene->cam.dir = (t_vec3){0.0, -0.3, -1.0};
	scene->cam.fov = 70.0;
	init_camera(&scene->cam, WIDTH, HEIGHT);

	scene->light.pos = (t_point){0.0, 5.0, 2.0};
	scene->light.brightness = 0.8;
	scene->light.color = (t_color){1.0, 1.0, 1.0};

	scene->ambient_ratio = 0.15;
	scene->ambient_color = (t_color){1.0, 1.0, 1.0};

	scene->plane.point = (t_point){0.0, 0.0, 0.0};
	scene->plane.normal = (t_vec3){0.0, 1.0, 0.0};
	scene->plane.color = (t_color){0.3, 0.8, 0.3};
}
int	main(void)
{
	t_data	data;

	setup_dummy_scene(&data.scene);
	data.mlx = mlx_init(WIDTH, HEIGHT, "miniRT", false);
	if (!data.mlx)
		return (EXIT_FAILURE);
	data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	if (!data.img || (mlx_image_to_window(data.mlx, data.img, 0, 0) < 0))
	{
		mlx_terminate(data.mlx);
		return (EXIT_FAILURE);
	}
	render(data.img, &data.scene);
	mlx_key_hook(data.mlx, &key_hook, &data);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	return (EXIT_SUCCESS);
}