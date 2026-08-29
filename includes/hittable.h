/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittable.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 09:57:13 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/08/27 10:06:14 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HITTABLE_H
# define HITTABLE_H
#include "ray.h"

typedef struct s_ray t_ray;

typedef struct s_hit_record
{
    t_vec4  p;
    t_vec4  n;
    float   t;
    bool    font_face;
}   t_hit_record;

typedef struct  s_hittable
{
    t_ray   *r;
    float   t_min;
    float   t_max;
    t_hit_record    *rec;
}   t_hittable;

t_hittable  hittable_init(t_ray *r, float t_min, float t_max, t_hit_record *rec);

void        set_surface_normal(t_hit_record *rec, const t_ray r, const t_vec4 outward_normal);

t_hit_record    *hit_rec_init_empty(void);


# endif