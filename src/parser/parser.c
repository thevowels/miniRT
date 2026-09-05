/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 00:20:20 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/09/05 14:49:21 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "libft.h"

static void count_lines(t_map *map)
{
	int		i;
	char	*line;

	i = 0;
	line = NULL;

	while(1)
	{
		line = get_next_line(map->fd);
		if(line == NULL)
			break;
		if(!ft_iscomment(line))
			i++;
		ft_safefree(line);
	}
	map->file = ft_calloc(i + 1, sizeof(char *));
	if(map->file != NULL)
		map->file[i] = NULL;
	else
		map->file = NULL;
	close(map->fd);
}

static void parse_map(t_map *map)
{
	int		i;
	char	*line;

	i = 0;
	line = NULL;
	if(!map || !(map->file))
		return;
	while(true)
	{
		line = get_next_line(map->fd);
		if(!line)
			break;
		if(ft_iscomment(line))
			ft_safefree(line);
		else
		{
			map->file[i] = line;
			i++;
		}
	}
	close(map->fd);

}

// static void validate_lines(t_map *map)
// {
// 	int		i;
// 	char	*line;

// 	i = 0;
// 	while(map && map->file && map->file[i])
// 	{
// 		ft_swapspaces(map->file[i]);
// 		line = map->file[i];
// 		while(line )
// 	}
// }

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
	if(!ft_strcmp(argv[1], "") || !ft_endswith(argv[1],".rt"))
		return (ft_safefree(map), error_message(ERR_INVALID_ARG), NULL);
	map->fd = open(argv[1], O_RDONLY);
	if(map->fd < 0)
		return(ft_safefree(map), error_message(ERR_OPEN_FILE), NULL);
	count_lines(map);
	if(map->file == NULL)
		return (ft_safefree(map), error_message(ERR_COUNT_LINES), NULL);
	map->fd =  open(argv[1], O_RDONLY);
	if(map->fd < 0)
		return (free_map(map), error_message(ERR_OPEN_FILE),NULL);
	parse_map(map);
	if(map->file == NULL)
		return (free_map(map), error_message(ERR_READ_LINES), NULL);
}


t_data *parse(int argc, char **argv)
{
t_data *data;
data = init_data();
data->map = parse_map(argc, argv);
}