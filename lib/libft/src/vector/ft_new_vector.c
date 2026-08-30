/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_vector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 21:21:18 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/08/29 21:21:54 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vec	ft_new_vector(double x, double y, double z)
{
	t_vec tmp;

	tmp.x = x;
	tmp.y = y;
	tmp.z = z;
	return (tmp);
}