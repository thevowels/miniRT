/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scalar_multi.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 18:57:45 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/08/29 18:59:43 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vec	ft_scalar_multi(t_vec v1, double scalar)
{
	t_vec tmp;

	tmp.x = v1.x * scalar;
	tmp.y = v1.y * scalar;
	tmp.z = v1.z * scalar;
	return (tmp);
}