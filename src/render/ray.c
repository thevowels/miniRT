/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 16:18:25 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/09/17 16:18:26 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	set_face(t_ray r, t_hit *rec, t_vec outward)
{
	rec->front = ft_dot_product(r.dir, outward) < 0;
	if (rec->front)
		rec->normal = outward;
	else
		rec->normal = ft_scalar_multi(outward, -1);
}

t_vec	ray_at(t_ray r, double t)
{
	return (ft_add_vectors(r.origin, ft_scalar_multi(r.dir, t)));
}

bool	hit_world(t_data *data, t_ray r, double tmax, t_hit *rec)
{
	t_obj	*o;
	t_hit	tmp;
	double	best;

	best = tmax;
	rec->hit = false;
	o = data->scene.objs;
	while (o)
	{
		tmp.hit = false;
		if (o->type == SPHERE)
			hit_sphere(o, r, best, &tmp);
		if (o->type == PLANE)
			hit_plane(o, r, best, &tmp);
		if (o->type == CYLINDER)
			hit_cylinder(o, r, best, &tmp);
		if (tmp.hit)
		{
			best = tmp.t;
			*rec = tmp;
		}
		o = o->next;
	}
	return (rec->hit);
}

t_vec	ray_color(t_data *data, t_ray r)
{
	t_hit	rec;

	rec.hit = false;
	if (hit_world(data, r, INF, &rec))
		return (shade(data, rec));
	return (ft_new_vector(0, 0, 0));
}
