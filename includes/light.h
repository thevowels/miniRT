/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 09:52:55 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/08/27 10:21:33 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
#define LIGHT_H
#include "minirt.h"
#include "hittable.h"

typedef float   t_vec4 __attribute__ ((vector_size (16)));

typedef struct  s_ambient
{
    float strength;
    t_vec4 color;
}   t_ambient;

typedef struct s_lighting
{
    t_vec4  diff;
    t_vec4  specs;
    bool    if_s;
    t_vec4  shadow;
}   t_lighting;

typedef struct s_point_light
{
    t_vec4  position;
    t_vec4  diff_color;
    float   diff_power;
    t_vec4  spec_color;
    float   spec_power;
}   t_point_light;

t_point_light   point_light_init(t_vec4 poisition, t_vec4 color, float power);

t_lighting      get_point_light(t_point_light light, t_hittable hittable);

#endif