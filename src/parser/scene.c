/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 16:17:16 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/09/17 16:17:17 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	parse_scene(t_data *data)
{
	int	i;

	i = 0;
	if (!data->lines || !data->lines[0])
		return (-1);
	while (data->lines[i])
	{
		if (parse_line(data, data->lines[i]) != 0)
			return (-1);
		i++;
	}
	if (!data->scene.amb.set)
		return (-1);
	if (!data->scene.cam.set)
		return (-1);
	if (!data->scene.light.set)
		return (-1);
	return (0);
}
