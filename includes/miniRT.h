/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 00:17:14 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/09/05 14:44:09 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>		//printf
# include <fcntl.h>		//open
# include <unistd.h>	//write, read, open, close
# include <stdlib.h>	//malloc, free
# include <math.h>
# include <limits.h>	//int max
# include <pthread.h>	//threads, mutex
# include "MLX42.h"
# include "libft.h"


# define WIDTH	800
# define HEIGHT	460

//Quality Configuration
# define STEPSIZE	10		// Amount of Pixel that Camera moves
# define MAX_DEPTH	5		// Amount of Bounce Rays
# define NOT		16		// Amount of Threads

//Ray Configuration
# define T_MIN 0.001
# define T_MAX __DBL_MAX__

//Color and Light Configuration
# define SKY			0		//toggle background
# define LIGHT_FACTOR	80		//sets factor for stochastic sampling
# define LIGHT_RADIUS	15		//point light radius
# define ALBEDO			1.0		//material absorption rate
# define SOFT_SHADOW	1		//toggles soft shadows
# define BOUNCES		3		//amount of bounce rays
# define SAMPLES		10000		//0 means endless progressive sampling

# define MLX 1

# define COL "Color"
# define POS "Position"
# define ORI "Orientation"
# define ORI2 "Orientation2"

typedef enum e_type
{
	CAM,
	LIGHT,
	AMBI,
	SPHERE,
	CYL,
	PLN,
	RES,
	CIRCLE,
	RECT,
	SQUA
}	t_type;

typedef struct s_color
{
	double	r;
	double	g;
	double	b;
}			t_color;

typedef struct s_obj
{
	int				type;
	double			radius;
	double			width;
	double			hei_fov;
	double			reflection;
	t_vec			origin;
	t_vec			vector;
	t_vec			vector2;
	t_vec			color;
	struct s_obj	*next;
}					t_obj;

typedef struct s_ray
{
	t_vec	origin;
	t_vec	direction;
	double	closest_t;
	t_obj	*closest_object;
	t_vec	normal;
	int		seed;
}			t_ray;

typedef struct s_camera
{
	double	focal_length;
	t_vec	origin;
	t_vec	direction;
	t_vec	horizontal;
	t_vec	vertical;
	t_vec	upper_left_corner;
}			t_cam;

typedef struct s_map
{
	int		fd;
	char	**file;
}			t_map;

typedef struct s_thread
{
	int				id;
	pthread_t		pid;
	struct s_data	*data;
	int				runs;
	t_vec			*pixels;
	t_ray			*ray;
	t_vec			ambient;
}					t_thread;

typedef struct s_data
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	t_cam			*cam;
	t_map			*map;
	t_obj			*obj;
	int				width;
	int				height;
	t_thread		threads[NOT];
}					t_data;

// error enum
typedef enum e_error
{
    ERR_NONE = 0,
    ERR_ALLOC_DATA = 1,
    ERR_INIT_MLX = 2,
    ERR_FEW_ARGS = 3,
    ERR_MANY_ARGS = 4,
    ERR_INVALID_ARG = 5,
    ERR_OPEN_FILE = 6,
    ERR_ALLOC_MAP = 7,
    ERR_COUNT_LINES = 8,
    ERR_READ_LINES = 9,
    ERR_ALLOC_OBJ = 10,
    ERR_SPLIT_LINE = 11,
    ERR_INIT_IMAGE = 12,
    ERR_ALLOC_CAM = 13,
    ERR_NO_CAM = 14,
    ERR_DETACH_THREAD = 15,
    ERR_CREATE_THREAD = 16,
    ERR_JOIN_THREAD = 17,
    ERR_CREATE_MUTEX = 18,
    ERR_COUNT
}   t_error;

// gnl
char		*get_next_line(int fd);

// parser
// parser.c
t_data *parse(int argc, char **argv);
t_map	*check_input(int argc, char **argv);

// init
//init.c
t_data *init_data(void);


// error
// error.c
void	error_message(t_error ecase);
void	ft_error(t_data *data, t_error ecase);

// utils
// utils.c
void *ft_safefree(void * ptr);
bool	ft_endswith(char *str, char *end);
void ft_swapspaces(char *str);

// clean.c
void free_map(t_map	 *map);


//rt_files.c
int ft_iscomment(char *line);

# endif
