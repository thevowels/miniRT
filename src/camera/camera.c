/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 15:16:39 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/09/05 17:12:24 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include <math.h>
void	init_camera(t_camera *cam, int width, int height)
{
	t_vec3	vup;
	double	theta;
	double	h;
	double	vp_h;
	double	vp_w;
	t_vec3	center;
	vup = (t_vec3){0, 1, 0};
	if(fabs(cam->dir.y) > 0.999)
		vup = (t_vec3){0,0,1};
	cam->w = vec_scale(vec_norm(cam->dir) , -1.0);
	cam->u = vec_norm(vec_cross(vup, cam->w));
	cam->v = vec_cross(cam->w, cam->u);
	center = vec_sub(cam->pos, cam->w);
	theta = cam->fov * M_PI / 180.0;
	h = tan(theta / 2.0);
	vp_h = 2.0 * h;
	vp_w = vp_h * ((double)width / (double)height);
	cam->viewport_u = vec_scale(cam->u, vp_w);
	cam->viewport_v = vec_scale(cam->v, -vp_h);
	cam->pixel00_loc = vec_sub(center, vec_scale(cam->viewport_u, 0.5));
	cam->pixel00_loc = vec_sub(cam->pixel00_loc, vec_scale(cam->viewport_v, 0.5));
}


t_ray	get_ray(const t_camera *cam, int x, int y, int width, int height)
{
	t_ray	ray;
	double	s;
	double	t;
	t_point	sample_pixel;

	s = ((double)x + 0.5) / (double)width;
	t = ((double)y + 0.5) / (double)height;

	sample_pixel = vec_add(cam->pixel00_loc, vec_scale(cam->viewport_u, s));
	sample_pixel = vec_add(sample_pixel,vec_scale(cam->viewport_v, t));
	ray.orig = cam->pos;
	ray.dir = vec_norm(vec_sub(sample_pixel, cam->pos));
	return (ray);
}
