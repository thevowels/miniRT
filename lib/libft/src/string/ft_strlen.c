/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 19:43:31 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/10/26 04:07:16 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <errno.h>

/**
 * @brief Calculates the length of a null-terminated string
 * 
 * @param s Pointer to the null-terminated string to measure
 * @return Length of the string, or (size_t)-1 if s is NULL
 * 
 * @note Sets errno to EFAULT (14) when s is NULL
 * @warning Assumes string is properly null-terminated
 */
size_t	ft_strlen(char *s)
{
	size_t	i;

	if (!s)
	{
		errno = 14;
		return (-1);
	}
	i = 0;
	while (s[i])
		i++;
	return (i);
}
