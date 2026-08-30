/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lcg_random.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 21:28:18 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/08/29 21:35:39 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Linear Congruential Generator (LCG) Random Number Generator */
int	ft_lcg_random(unsigned int seed)
{
	const unsigned int multiplier = 1664525;
	const unsigned int increment = 1013904227;

	return (int)(multiplier * seed + increment);
}
