/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 16:18:35 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/09/17 16:53:11 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	in_shadow(t_data *data, t_vec p, t_vec ldir, double ldist)
{
	t_ray	r;
	t_hit	rec;

	r.origin = ft_add_vectors(p, ft_scalar_multi(ldir, EPS * 10));
	r.dir = ldir;
	rec.hit = false;
	if (hit_world(data, r, ldist - EPS, &rec))
		return (true);
	return (false);
}

t_vec	clamp_vec(t_vec v)
{
	if (v.x < 0)
		v.x = 0;
	if (v.x > 1)
		v.x = 1;
	if (v.y < 0)
		v.y = 0;
	if (v.y > 1)
		v.y = 1;
	if (v.z < 0)
		v.z = 0;
	if (v.z > 1)
		v.z = 1;
	return (v);
}

uint32_t	vec_to_pixel(t_vec c)
{
	int	r;
	int	g;
	int	b;

	c = clamp_vec(c);
	r = (int)(c.x * 255);
	g = (int)(c.y * 255);
	b = (int)(c.z * 255);
	return ((r << 24) | (g << 16) | (b << 8) | 255);
}

static t_vec	diffuse(t_data *data, t_hit rec)
{
	t_vec	to_l;
	double	dist;
	double	dot;
	t_vec	out;

	to_l = ft_subtract_vectors(data->scene.light.pos, rec.point);
	dist = ft_vector_length(to_l);
	to_l = ft_scalar_div(to_l, dist);
	dot = ft_dot_product(rec.normal, to_l);
	if (dot < 0)
		dot = 0;
	if (in_shadow(data, rec.point, to_l, dist))
		dot = 0;
	out = ft_scalar_multi(ft_hadamard_product(rec.color,
				data->scene.light.color), dot * data->scene.light.ratio);
	return (out);
}

t_vec	shade(t_data *data, t_hit rec)
{
	t_vec	amb;
	t_vec	dif;

	amb = ft_hadamard_product(rec.color, data->scene.amb.color);
	amb = ft_scalar_multi(amb, data->scene.amb.ratio);
	dif = diffuse(data, rec);
	return (clamp_vec(ft_add_vectors(amb, dif)));
}
