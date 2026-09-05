/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_files.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 13:40:29 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/09/05 13:42:18 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int ft_iscomment(char *line)
{
	if(line == NULL)
		return (0);
	while(*line && ft_isspace(*line))
		line++;
	if(*line && *line == '#')
		return(1);
	return (0);
}