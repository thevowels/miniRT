/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 16:08:39 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/09/05 17:04:26 by aphyo-ht         ###   ########.fr       */
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

static void	setup_dummy_scene(t_scene *scene, t_plane *pl, t_sphere *sp, t_object *objs)
{
scene->cam.pos = (t_point){0.0, 2.0, 5.0};
	scene->cam.dir = (t_vec3){0.0, -0.2, -1.0};
	scene->cam.fov = 70.0;
	init_camera(&scene->cam, WIDTH, HEIGHT);

	scene->light.pos = (t_point){3.0, 6.0, 3.0};
	scene->light.brightness = 0.8;
	scene->light.color = (t_color){1.0, 1.0, 1.0};

	scene->ambient_ratio = 0.15;
	scene->ambient_color = (t_color){1.0, 1.0, 1.0};

	// Ground plane: y = 0 facing up
	pl->point = (t_point){0.0, 0.0, 0.0};
	pl->normal = (t_vec3){0.0, 1.0, 0.0};
	pl->color = (t_color){0.4, 0.8, 0.4};

	// Red sphere resting on the plane
	sp->center = (t_point){0.0, 1.0, 0.0};
	sp->radius = 1.0;
	sp->color = (t_color){0.9, 0.2, 0.2};

	objs[0].type = PLANE;
	objs[0].data = pl;
	objs[1].type = SPHERE;
	objs[1].data = sp;

	scene->objects = objs;
	scene->obj_count = 2;}
int	main(void)
{
	t_data	data;
	t_plane plane;
	t_sphere sphere;
	t_object objs[2];

	setup_dummy_scene(&data.scene, &plane, &sphere, objs);
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