/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 10:23:44 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/08/27 10:24:46 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H
#include "ray.h"

typedef struct s_cam
{
	t_vec4	orig;
	t_vec4	horiz;
	t_vec4	vert;
	t_vec4	btm_left_cnr;
}	t_cam;

# endif