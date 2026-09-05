/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 15:25:27 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/09/05 16:57:49 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	hit_plane(const t_plane *pl, const t_ray *r, double t_max,
		t_hit_record *rec)
{
	double denom;
	double t;
	t_vec3 p0_minus_o;

	denom = vec_dot(r->dir, pl->normal);
	if (fabs(denom) < 1e-6)
		return (false);
	p0_minus_o = vec_sub(pl->point, r->orig);
	t = vec_dot(p0_minus_o, pl->normal) / denom;
	if (t < EPSILON || t > t_max)
		return (false);
	rec->t = t;
	rec->p = vec_add(r->orig, vec_scale(r->dir, t));
	if (denom > 0.0)
		rec->normal = vec_scale(pl->normal, -1.0);
	else
		rec->normal = pl->normal;
	rec->color = pl->color;
	return (true);
}