/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittable_obj.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 10:12:21 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/08/27 10:18:52 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HITTABLE_OBJ_H
# define  HITTABLE_OBJ_H
#include "hittable.h"

typedef struct s_plane
{
    t_vec4 point;
    t_vec4 vector;
}   t_plane;

t_plane *plane_init(t_vec4 point, t_vec4 vector);

typedef struct s_sphere
{
    t_vec4 center;
    float   radius;
}   t_sphere;

t_sphere    *sphere_init(t_vec4 center, float radius);
bool        sphere_hit(t_hittable hit, t_sphere *s);

typedef struct s_cylinder
{
    t_vec4  center;
    t_vec4  n;
    float   radius;
    float   height;
    float   angle;
    t_vec4  axis;
}   t_cylinder;



#endif