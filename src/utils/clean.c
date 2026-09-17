/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 16:19:45 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/09/17 16:47:45 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	free_lines(char **lines)
{
	int	i;

	i = 0;
	if (!lines)
		return ;
	while (lines[i])
	{
		free(lines[i]);
		i++;
	}
	free(lines);
}

void	free_objs(t_obj *objs)
{
	t_obj	*tmp;

	while (objs)
	{
		tmp = objs->next;
		free(objs);
		objs = tmp;
	}
}

void	free_data(t_data *data)
{
	if (!data)
		return ;
	free_lines(data->lines);
	free_objs(data->scene.objs);
	free(data);
}
