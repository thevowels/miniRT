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

static char	*read_all(char *path)
{
	int		fd;
	char	buf[4096];
	char	*all;
	char	*tmp;
	ssize_t	n;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	all = ft_strdup("");
	if (!all)
		return (close(fd), NULL);
	n = read(fd, buf, sizeof(buf));
	while (n > 0)
	{
		buf[n] = '\0';
		tmp = all;
		all = ft_strjoin(tmp, buf);
		free(tmp);
		if (!all)
			return (close(fd), NULL);
		n = read(fd, buf, sizeof(buf));
	}
	close(fd);
	if (n < 0)
		return (free(all), NULL);
	return (all);
}

static int	count_valid(char **split)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (split[i])
	{
		if (!ft_iscomment(split[i]))
			count++;
		i++;
	}
	return (count);
}

static int	fill_lines(t_data *data, char **split)
{
	int	i;
	int	j;

	data->lines = ft_calloc(count_valid(split) + 1, sizeof(char *));
	if (!data->lines)
		return (-1);
	i = 0;
	j = 0;
	while (split[i])
	{
		if (!ft_iscomment(split[i]))
			data->lines[j++] = ft_strdup(split[i]);
		if (j > 0 && !data->lines[j - 1])
			return (-1);
		i++;
	}
	return (0);
}

static t_data	*load_file(t_data *data, char *path)
{
	char	*all;
	char	**split;

	all = read_all(path);
	if (!all)
		return (error_message(ERR_OPEN_FILE), NULL);
	split = ft_split(all, '\n');
	free(all);
	if (!split)
		return (error_message(ERR_READ), NULL);
	if (fill_lines(data, split) != 0)
		return (ft_sarr_free(split), error_message(ERR_READ), NULL);
	ft_sarr_free(split);
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
