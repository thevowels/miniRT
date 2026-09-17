/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 16:18:16 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/09/17 16:18:16 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static bool	sphere_root(t_obj *o, t_ray r, double tmax, t_hit *rec, double d)
{
	t_vec	oc;
	double	a;
	double	b;
	double	sq;
	double	t;

	oc = ft_subtract_vectors(r.origin, o->center);
	a = ft_dot_product(r.dir, r.dir);
	b = 2.0 * ft_dot_product(oc, r.dir);
	sq = sqrt(d);
	t = (-b - sq) / (2 * a);
	if (t < EPS || t > tmax)
		t = (-b + sq) / (2 * a);
	if (t < EPS || t > tmax)
		return (false);
	rec->t = t;
	rec->point = ray_at(r, t);
	rec->color = o->color;
	set_face(r, rec, ft_scalar_div(ft_subtract_vectors(rec->point, \
		o->center), o->diameter / 2));
	rec->hit = true;
	return (true);
}

bool	hit_sphere(t_obj *o, t_ray r, double tmax, t_hit *rec)
{
	t_vec	oc;
	double	a;
	double	b;
	double	c;
	double	disc;

	oc = ft_subtract_vectors(r.origin, o->center);
	a = ft_dot_product(r.dir, r.dir);
	b = 2.0 * ft_dot_product(oc, r.dir);
	c = ft_dot_product(oc, oc) - (o->diameter / 2) * (o->diameter / 2);
	disc = b * b - 4 * a * c;
	if (disc < 0)
		return (false);
	return (sphere_root(o, r, tmax, rec, disc));
}
