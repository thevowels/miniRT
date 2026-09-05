/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 16:48:54 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/09/05 17:06:27 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	hit_scene(const t_scene *scene, const t_ray *r, double t_max, t_hit_record *rec)
{
	t_hit_record	temp_rec;
	bool			hit_anything;
	double			closest_so_far;
	int				i;

	i = 0;
	hit_anything = false;
	closest_so_far = t_max;
	while(i < scene->obj_count)
	{
		bool hit = false;
		if(scene->objects[i].type == PLANE)
			hit = hit_plane((t_plane *)scene->objects[i].data, r, closest_so_far, &temp_rec);
		else if(scene->objects[i].type == SPHERE)
			hit = hit_sphere((t_sphere *)scene->objects[i].data, r, closest_so_far, &temp_rec);
		if(hit)
		{
			hit_anything = true;
			closest_so_far = temp_rec.t;
			*rec = temp_rec;
		}
		i++;
	}
	return (hit_anything);
}