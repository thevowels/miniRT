/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 16:16:30 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/09/17 16:16:34 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static int	append_line(t_data *data, char *line)
{
	char	**grow;
	int		n;
	int		i;

	n = ft_arrlen(data->lines);
	grow = ft_calloc(n + 2, sizeof(char *));
	if (!grow)
		return (-1);
	i = 0;
	while (i < n)
	{
		grow[i] = data->lines[i];
		i++;
	}
	grow[n] = line;
	free(data->lines);
	data->lines = grow;
	return (0);
}

static int	store_line(t_data *data, char *line)
{
	char	*dup;

	if (ft_iscomment(line))
		return (0);
	dup = ft_strdup(line);
	if (!dup)
		return (-1);
	if (append_line(data, dup) != 0)
		return (free(dup), -1);
	return (0);
}

static int	read_lines(int fd, t_data *data)
{
	char	*line;
	int		ret;

	ret = 0;
	line = get_next_line(fd);
	while (line)
	{
		ret = store_line(data, line);
		free(line);
		if (ret != 0)
			break ;
		line = get_next_line(fd);
	}
	return (ret);
}

static t_data	*load_file(t_data *data, char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (error_message(ERR_OPEN_FILE), NULL);
	if (read_lines(fd, data) != 0)
		return (close(fd), error_message(ERR_READ), NULL);
	close(fd);
	return (data);
}

t_data	*check_input(int argc, char **argv)
{
	t_data	*data;

	data = init_data();
	if (!data)
		return (error_message(ERR_ALLOC_DATA), NULL);
	if (argc < 2)
		return (free(data), error_message(ERR_FEW_ARGS), NULL);
	if (argc > 2)
		return (free(data), error_message(ERR_MANY_ARGS), NULL);
	if (!ft_endswith(argv[1], ".rt"))
		return (free(data), error_message(ERR_INVALID_ARG), NULL);
	if (!load_file(data, argv[1]))
		return (free(data), NULL);
	return (data);
}
