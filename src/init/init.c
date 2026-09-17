/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 16:14:30 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/09/17 16:14:31 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	init_scene(t_data *data)
{
	data->scene.amb.set = false;
	data->scene.cam.set = false;
	data->scene.light.set = false;
	data->scene.objs = NULL;
}

t_data	*init_data(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->mlx = NULL;
	data->img = NULL;
	data->lines = NULL;
	data->width = WIDTH;
	data->height = HEIGHT;
	init_scene(data);
	return (data);
}
