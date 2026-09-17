/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cyl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 16:28:41 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/09/17 16:29:32 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static double	side_disc(t_obj *o, t_ray r, double *a, double *b)
{
	t_vec	oc;
	double	dv;
	double	ov;
	double	rr;

	oc = ft_subtract_vectors(r.origin, o->center);
	dv = ft_dot_product(r.dir, o->axis);
	ov = ft_dot_product(oc, o->axis);
	*a = ft_dot_product(r.dir, r.dir) - dv * dv;
	*b = 2 * (ft_dot_product(r.dir, oc) - dv * ov);
	rr = o->diameter / 2;
	return (*b * *b - 4 * *a * (ft_dot_product(oc, oc) - ov * ov - rr * rr));
}

static bool	side_check(t_obj *o, t_ray r, double t, t_hit *rec)
{
	t_vec	p;
	double	m;
	double	h;

	p = ray_at(r, t);
	m = ft_dot_product(ft_subtract_vectors(p, o->center), o->axis);
	h = o->height / 2;
	if (m < -h || m > h)
		return (false);
	rec->t = t;
	rec->point = p;
	rec->color = o->color;
	set_face(r, rec, ft_unit_vector(ft_subtract_vectors(
				ft_subtract_vectors(p, o->center),
				ft_scalar_multi(o->axis, m))));
	rec->hit = true;
	return (true);
}

static bool	hit_side(t_obj *o, t_ray r, double tmax, t_hit *rec)
{
	double	a;
	double	b;
	double	disc;
	double	sq;
	double	t;

	disc = side_disc(o, r, &a, &b);
	if (disc < 0 || fabs(a) < 1e-8)
		return (false);
	sq = sqrt(disc);
	t = (-b - sq) / (2 * a);
	if (t > EPS && t < tmax && side_check(o, r, t, rec))
		return (true);
	t = (-b + sq) / (2 * a);
	if (t > EPS && t < tmax && side_check(o, r, t, rec))
		return (true);
	return (false);
}

static bool	hit_cap(t_hitctx *c)
{
	t_vec	cc;
	t_vec	n;
	double	den;
	double	t;
	t_vec	p;

	cc = ft_add_vectors(c->obj->center,
			ft_scalar_multi(c->obj->axis, c->val * c->obj->height / 2));
	n = ft_scalar_multi(c->obj->axis, c->val);
	den = ft_dot_product(c->ray.dir, n);
	if (fabs(den) < 1e-6)
		return (false);
	t = ft_dot_product(ft_subtract_vectors(cc, c->ray.origin), n) / den;
	if (t < EPS || t > c->tmax)
		return (false);
	p = ray_at(c->ray, t);
	if (ft_vector_length(ft_subtract_vectors(p, cc))
		> c->obj->diameter / 2)
		return (false);
	c->rec->t = t;
	c->rec->point = p;
	c->rec->color = c->obj->color;
	set_face(c->ray, c->rec, n);
	c->rec->hit = true;
	return (true);
}

bool	hit_cylinder(t_obj *o, t_ray r, double tmax, t_hit *rec)
{
	t_hit		best;
	t_hit		tmp;
	t_hitctx	c;

	best.t = tmax;
	best.hit = false;
	c.obj = o;
	c.ray = r;
	c.rec = &tmp;
	c.val = 1.0;
	if (hit_side(o, r, best.t, &tmp))
		best = tmp;
	while (c.val >= -1.0)
	{
		tmp.hit = false;
		c.tmax = best.t;
		if (hit_cap(&c))
			best = tmp;
		c.val -= 2.0;
	}
	*rec = best;
	return (best.hit);
}
