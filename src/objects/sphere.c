/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 16:41:13 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/09/05 17:14:53 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool hit_sphere(const t_sphere *sp, const t_ray *r, double t_max, t_hit_record *rec)
{
	t_vec3	oc;
	double	a;
	double	half_b;
	double	c;
	double	discriminant;
	double	sqrtd;
	double	root;

	oc = vec_sub(r->orig, sp->center);
	a = vec_dot(r->dir, r->dir);
	half_b = vec_dot(oc, r->dir);
	c = vec_dot(oc, oc) - (sp->radius * sp->radius);
	discriminant = (half_b * half_b) - (a * c);
	if(discriminant < 0.0)
		return (false);
	sqrtd = sqrt(discriminant);

	root = (-half_b - sqrtd) / a;
	if(root < EPSILON || root > t_max)
	{
		root = (-half_b + sqrtd) / a;
		if(root < EPSILON || root > t_max)
			return (false);
	}
	rec->t = root;
	rec->p = vec_add(r->orig, vec_scale(r->dir, rec->t));
	rec->normal = vec_scale(vec_sub(rec->p, sp->center), 1.0/ sp->radius);
	rec->color = sp->color;
	return (true);
}