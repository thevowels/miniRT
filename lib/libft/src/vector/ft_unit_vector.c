/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unit_vector.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 19:19:25 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/08/29 19:50:26 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vec	ft_unit_vector(t_vec v1)
{
	double l = ft_vector_length(v1);

	if (l != 0.0)
		return (ft_scalar_div(v1, l));
	return (v1);
}