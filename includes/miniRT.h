#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <stdbool.h>
# include "MLX42/MLX42.h"
# include "libft.h"

# define WIDTH 800
# define HEIGHT 600
# define EPS 0.001
# define INF __DBL_MAX__

typedef enum e_type
{
	SPHERE,
	PLANE,
	CYLINDER
}	t_type;

typedef struct s_ray
{
	t_vec	origin;
	t_vec	dir;
}	t_ray;

typedef struct s_hit
{
	double	t;
	t_vec	point;
	t_vec	normal;
	t_vec	color;
	bool	hit;
	bool	front;
}	t_hit;

typedef struct s_amb
{
	double	ratio;
	t_vec	color;
	bool	set;
}	t_amb;

typedef struct s_cam
{
	t_vec	origin;
	t_vec	dir;
	double	fov;
	bool	set;
}	t_cam;

typedef struct s_light
{
	t_vec	pos;
	double	ratio;
	t_vec	color;
	bool	set;
}	t_light;

typedef struct s_obj
{
	int				type;
	t_vec			center;
	t_vec			axis;
	double			diameter;
	double			height;
	t_vec			color;
	struct s_obj	*next;
}	t_obj;

typedef struct s_scene
{
	t_amb	amb;
	t_cam	cam;
	t_light	light;
	t_obj	*objs;
}	t_scene;

typedef struct s_cambasis
{
	t_vec	origin;
	t_vec	lower_left;
	t_vec	horizontal;
	t_vec	vertical;
	t_vec	u;
	t_vec	v;
	t_vec	w;
}	t_cambasis;

typedef struct s_data
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_scene		scene;
	char		**lines;
	int			width;
	int			height;
	t_cambasis	cb;
}	t_data;

typedef enum e_error
{
	ERR_NONE = 0,
	ERR_ALLOC_DATA,
	ERR_FEW_ARGS,
	ERR_MANY_ARGS,
	ERR_INVALID_ARG,
	ERR_OPEN_FILE,
	ERR_ALLOC_MAP,
	ERR_READ,
	ERR_PARSE,
	ERR_NO_CAM,
	ERR_NO_AMB,
	ERR_NO_LIGHT,
	ERR_DUP_ELEM,
	ERR_MLX,
	ERR_COUNT
}	t_error;

/* error */
void	error_message(t_error ecase);
void	ft_error(t_data *data, t_error ecase);

/* utils */
void	*ft_safefree(void *ptr);
bool	ft_endswith(char *str, char *end);
int		ft_iscomment(char *line);
int		ft_arrlen(char **arr);

/* clean */
void	free_lines(char **lines);
void	free_objs(t_obj *objs);
void	free_data(t_data *data);

/* init */
t_data	*init_data(void);

/* parser */
t_data	*check_input(int argc, char **argv);
int		parse_scene(t_data *data);
int		parse_line(t_data *data, char *line);
int		parse_ambient(t_data *data, char **tok);
int		parse_camera(t_data *data, char **tok);
int		parse_light(t_data *data, char **tok);
int		parse_sphere(t_data *data, char **tok);
int		parse_plane(t_data *data, char **tok);
int		parse_cylinder(t_data *data, char **tok);

/* parse values */
int		parse_vec(char *s, t_vec *out);
int		parse_color(char *s, t_vec *out);
int		parse_ratio(char *s, double *out);
int		parse_fov(char *s, double *out);
int		parse_positive(char *s, double *out);
int		parse_normal(char *s, t_vec *out);

/* render */
int		render(t_data *data);
void	setup_camera(t_data *data);
t_ray	make_ray(t_data *data, double u, double v);
t_vec	ray_at(t_ray r, double t);
t_vec	ray_color(t_data *data, t_ray r);
bool	hit_world(t_data *data, t_ray r, double tmax, t_hit *rec);
bool	hit_sphere(t_obj *o, t_ray r, double tmax, t_hit *rec);
bool	hit_plane(t_obj *o, t_ray r, double tmax, t_hit *rec);
bool	hit_cylinder(t_obj *o, t_ray r, double tmax, t_hit *rec);
t_vec	shade(t_data *data, t_hit rec);
bool	in_shadow(t_data *data, t_vec p, t_vec ldir, double ldist);
uint32_t	vec_to_pixel(t_vec c);
t_vec	clamp_vec(t_vec v);
void	set_face(t_ray r, t_hit *rec, t_vec outward);

#endif
