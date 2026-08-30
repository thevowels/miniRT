/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hadamard_product.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 18:15:16 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/08/29 18:59:33 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vec	ft_hadamard_product(t_vec v1, t_vec v2)
{
	t_vec tmp;

	tmp.x = v1.x * v2.x;
	tmp.y = v1.y * v2.y;
	tmp.z = v1.z * v2.z;
	return tmp;
}