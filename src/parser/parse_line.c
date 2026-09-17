/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 16:15:11 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/09/17 16:15:12 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	parse_ambient(t_data *data, char **tok)
{
	double	ratio;
	t_vec	color;

	if (data->scene.amb.set)
		return (-1);
	if (ft_arrlen(tok) != 3)
		return (-1);
	if (parse_ratio(tok[1], &ratio) != 0)
		return (-1);
	if (parse_color(tok[2], &color) != 0)
		return (-1);
	data->scene.amb.ratio = ratio;
	data->scene.amb.color = color;
	data->scene.amb.set = true;
	return (0);
}

int	parse_camera(t_data *data, char **tok)
{
	t_vec	pos;
	t_vec	dir;
	double	fov;

	if (data->scene.cam.set)
		return (-1);
	if (ft_arrlen(tok) != 4)
		return (-1);
	if (parse_vec(tok[1], &pos) != 0)
		return (-1);
	if (parse_normal(tok[2], &dir) != 0)
		return (-1);
	if (parse_fov(tok[3], &fov) != 0)
		return (-1);
	data->scene.cam.origin = pos;
	data->scene.cam.dir = dir;
	data->scene.cam.fov = fov;
	data->scene.cam.set = true;
	return (0);
}

int	parse_light(t_data *data, char **tok)
{
	t_vec	pos;
	double	ratio;
	t_vec	color;

	if (data->scene.light.set)
		return (-1);
	if (ft_arrlen(tok) != 3 && ft_arrlen(tok) != 4)
		return (-1);
	if (parse_vec(tok[1], &pos) != 0)
		return (-1);
	if (parse_ratio(tok[2], &ratio) != 0)
		return (-1);
	color = ft_new_vector(1, 1, 1);
	if (ft_arrlen(tok) == 4)
		if (parse_color(tok[3], &color) != 0)
			return (-1);
	data->scene.light.pos = pos;
	data->scene.light.ratio = ratio;
	data->scene.light.color = color;
	data->scene.light.set = true;
	return (0);
}

static int	dispatch(t_data *data, char **tok)
{
	if (ft_strncmp(tok[0], "A", 2) == 0)
		return (parse_ambient(data, tok));
	if (ft_strncmp(tok[0], "C", 2) == 0)
		return (parse_camera(data, tok));
	if (ft_strncmp(tok[0], "L", 2) == 0)
		return (parse_light(data, tok));
	if (ft_strncmp(tok[0], "sp", 3) == 0)
		return (parse_sphere(data, tok));
	if (ft_strncmp(tok[0], "pl", 3) == 0)
		return (parse_plane(data, tok));
	if (ft_strncmp(tok[0], "cy", 3) == 0)
		return (parse_cylinder(data, tok));
	return (-1);
}

int	parse_line(t_data *data, char *line)
{
	char	**tok;
	int		ret;

	tok = ft_split_spaces(line);
	if (!tok)
		return (-1);
	if (!tok[0])
		return (ft_sarr_free(tok), 0);
	ret = dispatch(data, tok);
	ft_sarr_free(tok);
	return (ret);
}
