/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittable_list.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 10:10:49 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/08/27 10:20:37 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HITTABLE_LIST_H
# define HITTABLE_LIST_H
#include "hittable.h"
#include "hittable_obj.h"

typedef struct s_hittable_list
{
    t_sphere *s;
    t_plane *p;
    t_cylinder *c;
    t_hittable *hit;
    t_vec4  color;
    int i;
    struct s_hittable_list  *next;
    struct s_hittable_list  *prev;
}   t_hittable_list;



#endif