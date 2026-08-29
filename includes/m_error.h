/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_error.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 17:53:02 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/08/27 10:36:13 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef M_ERROR_H
#define M_ERROR_H

typedef enum e_err
{
    ERR_FILE_TYPE,
    ERR_FILE_EMPTY,
    ERR_UNKNOWN_ELEM,
    ERR_OUT_OF_RANGE,
    ERR_INCOMPLETE_LINE,
    ERR_NO_CAMERA,
    ERR_MALLOC,
    ERR_NO_INPUT,
    ERR_COUNT
} t_err;

typedef enum e_err_str
{
    ERR_STR_DUP_ELEM,
    ERR_STR_VEC3_CONV,
    ERR_STR_FLOAT_CONV,
    ERR_STR_FLOAT_RANGE,
    ERR_STR_VEC3_RANGE,
    ERR_STR_NOT_ELEM,
    ERR_STR_COUNT
} t_err_str;

void ft_error(t_err err);
void ft_error_str(t_err_str err, const char *str);

#endif