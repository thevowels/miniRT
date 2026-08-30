/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scalar_div.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 19:00:49 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/08/29 19:11:12 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// if you pass 0 , thats your problem
t_vec	ft_scalar_div(t_vec v1, double scalar)
{
	t_vec tmp;

	tmp.x = v1.x / scalar;
	tmp.y = v1.y / scalar;
	tmp.z = v1.z / scalar;

	return (tmp);
}