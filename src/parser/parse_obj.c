/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 16:14:38 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/09/17 16:15:24 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static t_obj	*new_obj(int type)
{
	t_obj	*o;

	o = ft_calloc(1, sizeof(t_obj));
	if (!o)
		return (NULL);
	o->type = type;
	o->next = NULL;
	return (o);
}

static void	push_obj(t_data *data, t_obj *o)
{
	t_obj	*cur;

	if (!data->scene.objs)
		data->scene.objs = o;
	else
	{
		cur = data->scene.objs;
		while (cur->next)
			cur = cur->next;
		cur->next = o;
	}
}

int	parse_sphere(t_data *data, char **tok)
{
	t_obj	*o;
	t_vec	c;
	t_vec	col;
	double	d;

	if (ft_arrlen(tok) != 4)
		return (-1);
	if (parse_vec(tok[1], &c) != 0)
		return (-1);
	if (parse_positive(tok[2], &d) != 0)
		return (-1);
	o = new_obj(SPHERE);
	if (!o)
		return (-1);
	o->center = c;
	o->diameter = d;
	if (parse_color(tok[3], &col) != 0)
		return (free(o), -1);
	o->color = col;
	push_obj(data, o);
	return (0);
}

int	parse_plane(t_data *data, char **tok)
{
	t_obj	*o;
	t_vec	p;
	t_vec	n;
	t_vec	col;

	if (ft_arrlen(tok) != 4)
		return (-1);
	if (parse_vec(tok[1], &p) != 0)
		return (-1);
	if (parse_normal(tok[2], &n) != 0)
		return (-1);
	if (parse_color(tok[3], &col) != 0)
		return (-1);
	o = new_obj(PLANE);
	if (!o)
		return (-1);
	o->center = p;
	o->axis = n;
	o->color = col;
	push_obj(data, o);
	return (0);
}

int	parse_cylinder(t_data *data, char **tok)
{
	t_obj	*o;
	t_vec	col;

	if (ft_arrlen(tok) != 6)
		return (-1);
	o = new_obj(CYLINDER);
	if (!o)
		return (-1);
	if (parse_vec(tok[1], &o->center) != 0)
		return (free(o), -1);
	if (parse_normal(tok[2], &o->axis) != 0)
		return (free(o), -1);
	if (parse_positive(tok[3], &o->diameter) != 0)
		return (free(o), -1);
	if (parse_positive(tok[4], &o->height) != 0)
		return (free(o), -1);
	if (parse_color(tok[5], &col) != 0)
		return (free(o), -1);
	o->color = col;
	push_obj(data, o);
	return (0);
}
