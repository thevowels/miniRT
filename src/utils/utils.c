/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 00:31:23 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/09/05 14:43:53 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	*ft_safefree(void *ptr)
{
	if (ptr != NULL)
		free(ptr);
	return (NULL);
}
bool	ft_endswith(char *str, char *end)
{
	int	strlen;
	int	endlen;
	int	checkpoint;

	if (!str || !end)
		return (false);
	strlen = ft_strlen(str);
	endlen = ft_strlen(end);
	if (strlen < endlen || ft_strncmp(&str[strlen - endlen], end, endlen))
		return (false);
	return (true);
}
void ft_swapspaces(char *str)
{
	while(str && *str)
	{
		if(ft_isspace(*str))
			*str = ' ';
		str++;
	}
}