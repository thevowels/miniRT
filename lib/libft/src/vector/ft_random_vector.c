/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_random_vector.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 20:12:46 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/08/29 21:37:29 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vec	ft_random_vector(unsigned int seed)
{
	t_vec result;
	int random;

	random = ft_xorshift_random(seed);
	result.x = random % 1000;
	random = ft_lcg_random(seed + 1);
	result.y = random % 1000;
	random = ft_xslcg_random(seed + 2);
	result.z = random % 1000;
	result.x /= 1000;
	result.y /= 1000;
	result.z /= 1000;
	return (result);
}
