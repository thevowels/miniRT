/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 16:17:35 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/09/17 16:17:37 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	setup_basis(t_data *data)
{
	t_vec	look;
	t_vec	up;

	look = data->scene.cam.dir;
	data->cb.w = ft_unit_vector(ft_scalar_multi(look, -1));
	up = ft_new_vector(0, 1, 0);
	if (fabs(data->cb.w.y) > 0.999)
		up = ft_new_vector(0, 0, 1);
	data->cb.u = ft_unit_vector(ft_cross_product(up, data->cb.w));
	data->cb.v = ft_cross_product(data->cb.w, data->cb.u);
	data->cb.origin = data->scene.cam.origin;
}

void	setup_camera(t_data *data)
{
	double	theta;
	double	half_h;
	double	aspect;

	setup_basis(data);
	theta = data->scene.cam.fov * M_PI / 180.0;
	half_h = tan(theta / 2.0);
	aspect = (double)data->width / data->height;
	data->cb.horizontal = ft_scalar_multi(data->cb.u, 2 * half_h * aspect);
	data->cb.vertical = ft_scalar_multi(data->cb.v, 2 * half_h);
	data->cb.lower_left = ft_subtract_vectors(data->cb.origin, data->cb.w);
	data->cb.lower_left = ft_subtract_vectors(data->cb.lower_left, \
		ft_scalar_div(data->cb.horizontal, 2));
	data->cb.lower_left = ft_subtract_vectors(data->cb.lower_left, \
		ft_scalar_div(data->cb.vertical, 2));
}

t_ray	make_ray(t_data *data, double u, double v)
{
	t_ray	ray;
	t_vec	p;

	p = ft_add_vectors(data->cb.lower_left, \
		ft_scalar_multi(data->cb.horizontal, u));
	p = ft_add_vectors(p, ft_scalar_multi(data->cb.vertical, v));
	ray.origin = data->cb.origin;
	ray.dir = ft_unit_vector(ft_subtract_vectors(p, ray.origin));
	return (ray);
}
