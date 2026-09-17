/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 16:14:02 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/09/17 16:14:04 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static const char	*msg_part(t_error e)
{
	if (e == ERR_ALLOC_DATA)
		return ("Error: allocation failed");
	if (e == ERR_FEW_ARGS)
		return ("Error: too few arguments");
	if (e == ERR_MANY_ARGS)
		return ("Error: too many arguments");
	if (e == ERR_INVALID_ARG)
		return ("Error: argument must be a .rt file");
	if (e == ERR_OPEN_FILE)
		return ("Error: cannot open file");
	if (e == ERR_ALLOC_MAP)
		return ("Error: cannot allocate map");
	return (NULL);
}

static const char	*msg_part2(t_error e)
{
	if (e == ERR_READ)
		return ("Error: cannot read file");
	if (e == ERR_PARSE)
		return ("Error: invalid scene");
	if (e == ERR_NO_CAM)
		return ("Error: no camera in scene");
	if (e == ERR_NO_AMB)
		return ("Error: no ambient in scene");
	if (e == ERR_NO_LIGHT)
		return ("Error: no light in scene");
	if (e == ERR_DUP_ELEM)
		return ("Error: duplicated element");
	if (e == ERR_MLX)
		return ("Error: mlx failed");
	return ("Error: unknown error");
}

void	error_message(t_error ecase)
{
	const char	*m;

	m = msg_part(ecase);
	if (!m)
		m = msg_part2(ecase);
	ft_putendl_fd((char *)m, 2);
}

void	ft_error(t_data *data, t_error ecase)
{
	if (data)
	{
		if (data->mlx)
			mlx_terminate(data->mlx);
		free_data(data);
	}
	error_message(ecase);
	exit(1);
}
