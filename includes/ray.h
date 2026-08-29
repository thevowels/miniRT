/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 09:52:08 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/08/27 10:03:21 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H
typedef float					t_vec4 __attribute__ ((vector_size (16)));


typedef struct s_ray
{
    t_vec4 orig;
    t_vec4 dir;
}   t_ray;


#endif