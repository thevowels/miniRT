/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 14:54:11 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/09/05 17:10:14 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <math.h>
# include <stdbool.h>
# include <stdlib.h>

#include "vec3.h"

#include "MLX42/MLX42.h"


# define WIDTH 800
# define HEIGHT	600
# define EPSILON 1e-4


typedef struct s_ray
{
	t_point	orig;
	t_vec3	dir;
}	t_ray;

typedef struct s_hit_record
{
	double	t;
	t_point	p;
	t_vec3	normal;
	t_color	color;
}	t_hit_record;

typedef struct s_plane
{
	t_point	point;
	t_vec3	normal;
	t_color color;
}	t_plane;

typedef	struct s_light
{
	t_point	pos;
	double	brightness;
	t_color	color;
}	t_light;

typedef struct s_camera
{
	t_point	pos;
	t_vec3	dir;
	double	fov;
	t_vec3	u;
	t_vec3	v;
	t_vec3	w;
	t_vec3	viewport_u;
	t_vec3	viewport_v;
	t_point	pixel00_loc;
}	t_camera;

typedef enum e_obj_type
{
	PLANE,
	SPHERE
}	t_obj_type;

typedef struct s_object
{
	t_obj_type	type;
	void		*data;
}	t_object;

typedef	struct s_scene
{
	t_camera	cam;
	t_light		light;
	double		ambient_ratio;
	t_color		ambient_color;
	t_object	*objects;
	int			obj_count;
}	t_scene;

typedef struct s_data
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_scene		scene;
}	t_data;


typedef struct s_sphere
{
	t_point		center;
	double		radius;
	t_color		color;
}	t_sphere;


// Camera
void	init_camera(t_camera *cam, int width, int height);
t_ray	get_ray(const t_camera *cam, int x, int y, int width, int height);

// Objects

// Plane
bool	hit_plane(const t_plane *pl, const t_ray *r, double t_max, t_hit_record *rec);

// Sphere
bool hit_sphere(const t_sphere *sp, const t_ray *r, double t_max, t_hit_record *rec);


// Render
void	render(mlx_image_t *img, const t_scene *scene);

// Scene
bool	hit_scene(const t_scene *scene, const t_ray *r, double t_max, t_hit_record *rec);

#endif