/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 01:03:38 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/09/17 17:05:55 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 256
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_data
{
	char	*str;
	size_t	s_ncount;
	size_t	s_len;
	size_t	m_len;
}			t_gnl_data;

size_t		gnl_strlen(const char *str);
char		*gnl_strchr(const char *s, int c);
char		*gnl_strjoin(t_gnl_data *data, char const *s2);
t_gnl_data	*gnl_init_data(void);
char		*get_next_line(int fd);

#endif
