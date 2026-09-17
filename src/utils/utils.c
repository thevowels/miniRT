/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 16:13:20 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/09/17 16:19:36 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	*ft_safefree(void *ptr)
{
	if (ptr)
		free(ptr);
	return (NULL);
}

bool	ft_endswith(char *str, char *end)
{
	size_t	a;
	size_t	b;

	if (!str || !end)
		return (false);
	a = ft_strlen(str);
	b = ft_strlen(end);
	if (a < b)
		return (false);
	if (ft_strncmp(&str[a - b], end, b) != 0)
		return (false);
	return (true);
}

int	ft_iscomment(char *line)
{
	if (!line)
		return (1);
	while (*line && ft_isspace(*line))
		line++;
	if (*line == '\0' || *line == '\n' || *line == '#')
		return (1);
	return (0);
}

int	ft_arrlen(char **arr)
{
	int	i;

	i = 0;
	while (arr && arr[i])
		i++;
	return (i);
}
