/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 23:55:30 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/10/26 12:00:20 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static void	ft_memmove(char *dest, char *src, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	*tmp_dest;
	size_t	*tmp_src;

	i = 0;
	j = (n / sizeof(size_t));
	tmp_dest = (size_t *)dest;
	tmp_src = (size_t *)src;
	while (i < j)
	{
		tmp_dest[i] = tmp_src[i];
		i++;
	}
	i = j * sizeof(size_t);
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
}

char	*ft_strjoin(t_data *data, char const *s2)
{
	char	*res;

	data->m_len *= 2;
	res = malloc(sizeof(char) * (data->m_len));
	if (!res || !data->str || !s2)
		return (NULL);
	ft_memmove(res, data->str, data->s_len);
	ft_memmove(res + data->s_len, (char *)s2, ft_strlen(s2));
	res[data->s_len + ft_strlen(s2)] = 0;
	return (res);
}

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	char	check;

	str = (char *)s;
	check = (char)c;
	while (*str && check != *str)
	{
		str++;
	}
	if (check == *str)
		return (str);
	return (NULL);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

t_data	*init_data(void)
{
	t_data	*data;
	char	*str;

	str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!str)
		return (NULL);
	*str = 0;
	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->str = str;
	data->s_len = 0;
	data->s_ncount = 0;
	data->m_len = BUFFER_SIZE + 1;
	return (data);
}
