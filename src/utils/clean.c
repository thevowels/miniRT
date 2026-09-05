/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 13:46:34 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/09/05 13:48:19 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "miniRT.h"

void free_map(t_map	 *map)
{
	int	i;
	i = 0;
	while(map && map->file && map->file[i])
	{
		ft_safefree(map->file[i]);
		i++;
	}
	ft_safefree(map->file);
	ft_safefree(map);
}