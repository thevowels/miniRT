/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 00:20:20 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/08/31 00:33:43 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "miniRT.h"

t_map	*check_input(int argc, char **argv)
{
	t_map *map;
	map = ft_calloc(1, sizeof(t_map));
	if(map == NULL)
		return (error_message(ERR_ALLOC_MAP), NULL);
	if(argc < 2)
		return (ft_safefree(map), error_message(ERR_FEW_ARGS), NULL);
	if(argc > 2)
		return (ft_safefree(map), error_message(ERR_MANY_ARGS), NULL);
}


t_data *parse(int argc, char **argv)
{
t_data *data;
data = init_data();
data->map = parse_map(argc, argv);
}