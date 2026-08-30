/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 17:54:56 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/08/29 17:57:27 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if(*lst == NULL)
	{
		*lst = new;
		return;
	}
	while((*lst)->next)
	{
		*lst = (*lst)->next;
	}	
	(*lst)->next = new;
}