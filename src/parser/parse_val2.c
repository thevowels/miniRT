/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_val2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 16:15:50 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/09/17 16:15:50 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	parse_vec(char *s, t_vec *out)
{
	char	**p;
	char	*e;
	t_vec	v;

	p = ft_split(s, ',');
	if (!p || ft_arrlen(p) != 3)
		return (ft_sarr_free(p), -1);
	v.x = strtod(p[0], &e);
	if (e == p[0] || *e != '\0')
		return (ft_sarr_free(p), -1);
	v.y = strtod(p[1], &e);
	if (e == p[1] || *e != '\0')
		return (ft_sarr_free(p), -1);
	v.z = strtod(p[2], &e);
	if (e == p[2] || *e != '\0')
		return (ft_sarr_free(p), -1);
	ft_sarr_free(p);
	*out = v;
	return (0);
}

static int	comp_color(char *s, double *out)
{
	char	*e;
	long	v;

	v = strtol(s, &e, 10);
	if (e == s || *e != '\0' || v < 0 || v > 255)
		return (-1);
	*out = v / 255.0;
	return (0);
}

int	parse_color(char *s, t_vec *out)
{
	char	**p;
	t_vec	v;

	p = ft_split(s, ',');
	if (!p || ft_arrlen(p) != 3)
		return (ft_sarr_free(p), -1);
	if (comp_color(p[0], &v.x) != 0)
		return (ft_sarr_free(p), -1);
	if (comp_color(p[1], &v.y) != 0)
		return (ft_sarr_free(p), -1);
	if (comp_color(p[2], &v.z) != 0)
		return (ft_sarr_free(p), -1);
	ft_sarr_free(p);
	*out = v;
	return (0);
}

int	parse_normal(char *s, t_vec *out)
{
	t_vec	v;
	double	len;

	if (parse_vec(s, &v) != 0)
		return (-1);
	if (v.x < -1 || v.x > 1)
		return (-1);
	if (v.y < -1 || v.y > 1)
		return (-1);
	if (v.z < -1 || v.z > 1)
		return (-1);
	len = ft_vector_length(v);
	if (len < 1e-6 || fabs(len - 1.0) > 0.02)
		return (-1);
	*out = ft_scalar_div(v, len);
	return (0);
}
