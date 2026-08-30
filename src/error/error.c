/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 00:22:53 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/08/31 00:30:04 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	error_message(t_error ecase)
{
	static const char	*messages[ERR_COUNT] = {
	[ERR_NONE] = "Unknown error occurred.",
	[ERR_ALLOC_DATA] = "Error on allocating Datamemory!",
	[ERR_INIT_MLX] = "Error on initialising MLX!",
	[ERR_FEW_ARGS] = "Error, too few Arguments!",
	[ERR_MANY_ARGS] = "Error, too much Arguments!",
	[ERR_INVALID_ARG] = "Error, invalid Argument!",
	[ERR_OPEN_FILE] = "Error, can not open file.",
	[ERR_ALLOC_MAP] = "Error on allocating Map!",
	[ERR_COUNT_LINES] = "Error on counting Lines!",
	[ERR_READ_LINES] = "Error on reading Lines!",
	[ERR_ALLOC_OBJ] = "Error on allocating Object!",
	[ERR_SPLIT_LINE] = "Error on splitting Line!",
	[ERR_INIT_IMAGE] = "Error on initialising MLX Image!",
	[ERR_ALLOC_CAM] = "Error on allocating Camera!",
	[ERR_NO_CAM] = "Error, there is no Cam in the Scene!",
	[ERR_DETACH_THREAD] = "Error on detaching Threads!",
	[ERR_CREATE_THREAD] = "Error on creating Threads!",
	[ERR_JOIN_THREAD] = "Error on joining Threads!",
	[ERR_CREATE_MUTEX] = "Error on creating Mutex!"};

	if (ecase > ERR_NONE && ecase < ERR_COUNT && messages[ecase])
		ft_putendl_fd((char *)messages[ecase], 2);
	else
		ft_putendl_fd("Error: Unknown error code!", 2);
}

void	ft_error(t_data *data, t_error ecase)
{
	if (data != NULL)
	{
		if (ecase == ERR_INIT_MLX && data->mlx)
			mlx_terminate(data->mlx);
		ft_free(data);
	}
	error_message(ecase);
	exit(EXIT_FAILURE);
}
