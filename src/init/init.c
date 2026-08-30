/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 00:21:10 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/08/31 00:28:27 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_data	*init_data(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (data == NULL)
		ft_error(NULL, ERR_ALLOC_DATA);
	data->map = NULL;
	data->obj = NULL;
	data->mlx = NULL;
	data->img = NULL;
	data->cam = NULL;
	return (data);
}
