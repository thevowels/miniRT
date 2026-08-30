/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_random_vector_in_hemisphere.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 21:17:21 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/08/29 21:18:38 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vec	ft_random_vector_in_hemisphere(int seed, t_vec normal)
{
	t_vec rand_vec;

	rand_vec = ft_random_vector_in_unit_sphere(seed);
	if (ft_dot_product(rand_vec, normal) > 0.0)
		return (rand_vec);
	else
		return (ft_scalar_multi(rand_vec, -1));
}