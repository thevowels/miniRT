/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 16:18:01 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/09/17 16:18:02 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	hit_plane(t_obj *o, t_ray r, double tmax, t_hit *rec)
{
	double	denom;
	double	t;
	t_vec	diff;

	denom = ft_dot_product(r.dir, o->axis);
	if (fabs(denom) < 1e-6)
		return (false);
	diff = ft_subtract_vectors(o->center, r.origin);
	t = ft_dot_product(diff, o->axis) / denom;
	if (t < EPS || t > tmax)
		return (false);
	rec->t = t;
	rec->point = ray_at(r, t);
	rec->color = o->color;
	set_face(r, rec, o->axis);
	rec->hit = true;
	return (true);
}
