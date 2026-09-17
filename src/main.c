/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 16:12:51 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/09/17 16:12:59 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	data = check_input(argc, argv);
	if (!data)
		return (1);
	if (parse_scene(data) != 0)
		ft_error(data, ERR_PARSE);
	if (render(data) != 0)
		ft_error(data, ERR_MLX);
	free_data(data);
	return (0);
}
