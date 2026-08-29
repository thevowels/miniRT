/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 09:51:47 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/08/27 11:27:19 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parsing.h"
#include "m_utils.h"
#include <fcntl.h>

t_elements parse_input(char *file)
{
    t_elements elements;
    char *line;
    int fd;

    check_ft(file);
    fd = open(file, O_RDONLY);
    // line =

}