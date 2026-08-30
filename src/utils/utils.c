/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 00:31:23 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/08/31 00:38:32 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void *ft_safefree(void *ptr)
{
	if(ptr != NULL)
		free(ptr);
	return (NULL);
}

bool ft_endswith(char *str, char *end)
{
	int strlen;
	int endlen;
	int checkpoint;
	
	strlen = ft_strlen(str);
	endlen = ft_strlen(end);

	checkpoint = strlen - endlen;
	

	if(ft_strncmp())
}

bool	check_rt(char *argv)
{
	int len;
	
	if (argv == NULL)
		return (false);
	len = ft_strlen(argv);
	
}