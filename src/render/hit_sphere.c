/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 16:18:16 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/09/17 16:30:34 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static bool	sphere_root(t_hitctx *c)
{
	double	sq;
	double	t;
	t_vec	out;

	sq = sqrt(c->val);
	t = (-c->b - sq) / (2 * c->a);
	if (t < EPS || t > c->tmax)
		t = (-c->b + sq) / (2 * c->a);
	if (t < EPS || t > c->tmax)
		return (false);
	c->rec->t = t;
	c->rec->point = ray_at(c->ray, t);
	c->rec->color = c->obj->color;
	out = ft_scalar_div(ft_subtract_vectors(c->rec->point,
				c->obj->center), c->obj->diameter / 2);
	set_face(c->ray, c->rec, out);
	c->rec->hit = true;
	return (true);
}

bool	hit_sphere(t_obj *o, t_ray r, double tmax, t_hit *rec)
{
	t_vec		oc;
	t_hitctx	c;

	oc = ft_subtract_vectors(r.origin, o->center);
	c.obj = o;
	c.ray = r;
	c.tmax = tmax;
	c.rec = rec;
	c.a = ft_dot_product(r.dir, r.dir);
	c.b = 2.0 * ft_dot_product(oc, r.dir);
	c.val = c.b * c.b - 4 * c.a * (ft_dot_product(oc, oc)
			- (o->diameter / 2) * (o->diameter / 2));
	if (c.val < 0)
		return (false);
	return (sphere_root(&c));
}
