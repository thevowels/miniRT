/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 15:28:09 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/09/05 17:02:41 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static inline uint32_t	to_rgba(t_color c)
{
	int r;
	int g;
	int b;

	r = (int)(fmin(1.0, fmax(0.0, c.x)) * 255.0);
	g = (int)(fmin(1.0, fmax(0.0, c.y)) * 255.0);
	b = (int)(fmin(1.0, fmax(0.0, c.z)) * 255.0);
	return ((uint32_t)r << 24 | (uint32_t)g << 16 | (uint32_t)b << 8 | 255);
}

static	t_color	compute_color(const t_scene *scene, const t_ray *r)
{
	t_hit_record	rec;
	t_hit_record	shadow;
	t_ray			shadow_ray;
	t_vec3			light_vec;
	double			light_dist;
	double			diff;
	t_color			out;

	if(!hit_scene(scene, r, INFINITY, &rec))
		return ((t_color){0.05, 0.05, 0.08});
	
	out = vec_scale(rec.color, scene->ambient_ratio);

	light_vec = vec_sub(scene->light.pos, rec.p);
	light_dist = vec_len(light_vec);
	shadow_ray.orig = vec_add(rec.p, vec_scale(rec.normal, EPSILON));
	shadow_ray.dir = vec_norm(light_vec);

	if(!hit_scene(scene, &shadow_ray, light_dist - EPSILON,  &shadow))
	{
		diff = fmax(0.0, vec_dot(rec.normal, shadow_ray.dir)) * scene->light.brightness;
		out = vec_add(out, vec_scale(rec.color, diff));
	}
	return (out);
}

void	render(mlx_image_t *img, const t_scene	*scene)
{
	int	x;
	int	y;
	t_ray	ray;
	t_color	pixel_col;
	
	y = 0;
	while(y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			ray = get_ray(&scene->cam, x, y, WIDTH, HEIGHT);
			pixel_col = compute_color(scene, &ray);
			mlx_put_pixel(img, x, y, to_rgba(pixel_col));
			x++;
		}
		y++;
	}
}
