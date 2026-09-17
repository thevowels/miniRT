/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 16:18:30 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/09/17 16:18:31 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	key_hook(mlx_key_data_t key, void *param)
{
	t_data	*data;

	data = param;
	if (key.key == MLX_KEY_ESCAPE && key.action == MLX_PRESS)
		mlx_close_window(data->mlx);
}

static void	draw_pixel(t_data *data, int x, int y)
{
	double	u;
	double	v;
	t_ray	r;
	t_vec	c;

	u = (double)x / (double)(data->width - 1);
	v = 1.0 - (double)y / (double)(data->height - 1);
	r = make_ray(data, u, v);
	c = ray_color(data, r);
	mlx_put_pixel(data->img, x, y, vec_to_pixel(c));
}

static int	draw_all(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			draw_pixel(data, x, y);
			x++;
		}
		y++;
	}
	return (0);
}

int	render(t_data *data)
{
	setup_camera(data);
	data->mlx = mlx_init(data->width, data->height, "miniRT", true);
	if (!data->mlx)
		return (-1);
	data->img = mlx_new_image(data->mlx, data->width, data->height);
	if (!data->img)
		return (-1);
	draw_all(data);
	if (mlx_image_to_window(data->mlx, data->img, 0, 0) < 0)
		return (-1);
	mlx_key_hook(data->mlx, key_hook, data);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
	data->mlx = NULL;
	return (0);
}
