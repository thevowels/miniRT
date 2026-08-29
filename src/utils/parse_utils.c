/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 10:28:19 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/08/27 10:40:33 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "libft.h"
#include "m_error.h"

static void free_split(char **split)
{
    int i;
    i = 0;
    while(split[i])
    {
        free(split[i]);
        i++;
    }
    free(split);
}

int check_ft(char *file)
{
    char **split;
    int i;

    i = 0;
    if(!ft_strchr(file, '.'))
        ft_error(ERR_FILE_TYPE);
    split = ft_split(file, '.');
    if(ft_strncmp("rt", split[1], ft_strlen(split[1])))
        i++;
    free_split(split);
    if(i != 0)
        ft_error(ERR_FILE_TYPE);
    return (i);

}