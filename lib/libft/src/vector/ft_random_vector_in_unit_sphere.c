/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_random_vector_in_unit_sphere.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 20:13:16 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/08/29 21:19:59 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vec	ft_random_vector_in_unit_sphere(int seed)
{
	t_vec	rand_vec;

	while (1)
	{
		rand_vec = ft_random_vector((unsigned int)seed);
		seed = ft_xorshift_random(seed);
		if (ft_dot_product(rand_vec,rand_vec) < 1)
			return (ft_unit_vector(rand_vec));
	}
}