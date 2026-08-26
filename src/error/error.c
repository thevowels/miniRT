/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 17:52:15 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/08/26 18:02:09 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <stdlib.h>
#include "includes/error.h"
#include <stdio.h>
void ft_error(t_err err)
{
    static const char *err_msgs[ERR_COUNT] = {
        "Incorrect file type\n",
        "Empty file\n",
        " is not an existing element.\n",
        "Out of range.\n",
        "Incomplete line\n",
        "The rt file does not include a camera.\n",
        "MALLOC ERROR\n",
        "No input\n"
    };
    // Edit later
    printf("Error\n");
    if(err >= 0 && err < ERR_COUNT)
        printf((char *)err_msgs[err]);
    exit(EXIT_FAILURE);
}

void ft_error_str(t_err_str err, const char *str)
{
    static const char *errs_messages[ERR_STR_COUNT] = {
        "%s can only be declared once in the scene.\n",
        "Vec3 conversion impossible near line: '%s'\n",
        "Float conversion impossible near line: '%s'\n",
        "Float is out of range near line: '%s'\n",
        "Vec3 is out of range near line: '%s'\n",
        "%s is not an existing element.\n"
    };
    printf("Error\n", 2);
    if(err >= 0 && err < ERR_STR_COUNT)
        printf(errs_messages,str);
    exit(EXIT_FAILURE);
}