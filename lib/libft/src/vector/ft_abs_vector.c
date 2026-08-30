/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs_vector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 21:23:32 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/08/29 21:25:28 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "math.h"

t_vec	ft_abs_vector(t_vec color)
{
	color.x = fabs(color.x);
	color.y = fabs(color.y);
	color.z = fabs(color.z);
	return (color);
}