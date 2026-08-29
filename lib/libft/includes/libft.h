/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 18:36:44 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/01/20 07:14:02 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

///////////////////////////////////////////////////////////////////////////////
//									CTYPE                                    //
///////////////////////////////////////////////////////////////////////////////

int					ft_isalpha(int c);
int					ft_isdigit(int i);
int					ft_islower(int c);
int					ft_isupper(int c);
int					ft_isspace(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_atoi(const char *str);
int					ft_safe_atoi(const char *str, int *val);
double				ft_atof(char *str);
///////////////////////////////////////////////////////////////////////////////
//									STRING                                   //
///////////////////////////////////////////////////////////////////////////////

int					ft_startswith(char *str, char *start);
char				**ft_split(char *str, char c);
size_t				ft_strlen(char *s);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strjoin(char const *s1, char const *s2);
char				**ft_sarr_free(char **arr);
char				*ft_strdup(char *str);
char				**ft_split_spaces(char *str);

///////////////////////////////////////////////////////////////////////////////
//									PRINT                                    //
///////////////////////////////////////////////////////////////////////////////

void				ft_putstr(char *s);
size_t				ft_putstr_fd(char *str, int fd);
int					ft_printf(const char *str, ...);

///////////////////////////////////////////////////////////////////////////////
//									MATH                                     //
///////////////////////////////////////////////////////////////////////////////

int					ft_iseven(int i);
int					ft_isodd(int i);

///////////////////////////////////////////////////////////////////////////////
//									OTHERS                                   //
///////////////////////////////////////////////////////////////////////////////

void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);

///////////////////////////////////////////////////////////////////////////////
//									LINKED LIST                              //
///////////////////////////////////////////////////////////////////////////////
t_list				*ft_lstnew(void *content);

#endif