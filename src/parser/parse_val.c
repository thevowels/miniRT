/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_val.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 16:15:42 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/09/17 16:15:43 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static int	is_numchar(char c, int i, int dot)
{
	if (c >= '0' && c <= '9')
		return (1);
	if ((c == '+' || c == '-') && i == 0)
		return (1);
	if (c == '.' && dot == 0 && i > 0)
		return (1);
	return (0);
}

static int	valid_number(char *s)
{
	int	i;
	int	dot;
	int	dig;

	i = 0;
	dot = 0;
	dig = 0;
	if (!s || !s[0])
		return (0);
	while (s[i])
	{
		if (s[i] == '.')
			dot++;
		if (!is_numchar(s[i], i, dot - (s[i] == '.')))
			return (0);
		if (s[i] >= '0' && s[i] <= '9')
			dig++;
		i++;
	}
	if (!dig || dot > 1)
		return (0);
	if (s[i - 1] == '.' || s[i - 1] == '+' || s[i - 1] == '-')
		return (0);
	return (1);
}

int	parse_positive(char *s, double *out)
{
	double	v;
	char	*p;

	if (!valid_number(s))
		return (-1);
	v = strtod(s, &p);
	if (p == s || *p != '\0' || v <= 0)
		return (-1);
	*out = v;
	return (0);
}

int	parse_ratio(char *s, double *out)
{
	double	v;
	char	*p;

	if (!valid_number(s))
		return (-1);
	v = strtod(s, &p);
	if (p == s || *p != '\0' || v < 0 || v > 1)
		return (-1);
	*out = v;
	return (0);
}

int	parse_fov(char *s, double *out)
{
	double	v;
	char	*p;

	if (!valid_number(s))
		return (-1);
	v = strtod(s, &p);
	if (p == s || *p != '\0' || v < 0 || v > 180)
		return (-1);
	*out = v;
	return (0);
}
