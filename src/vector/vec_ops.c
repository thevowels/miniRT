/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_ops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 15:15:22 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/09/05 16:21:04 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"
#include "math.h"

double	vec_dot(t_vec3 a, t_vec3 b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_vec3	vec_cross(t_vec3 a, t_vec3 b)
{
	return ((t_vec3){
		a.y * b.z - a.z * b.y,
		a.z * b.x - a.x * b.z,
		a.x * b.y - a.y * b.x
	});
}

double	vec_len(t_vec3 v)
{
	return (sqrt(vec_dot(v, v)));
}

t_vec3	vec_norm(t_vec3 v)
{
	double	len;

	len = vec_len(v);
	if (len < 1e-8)
		return ((t_vec3){0, 0, 0});
	return (vec_scale(v, 1.0 / len));
}