/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 18:36:44 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/08/29 21:36:57 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

///////////////////////////////////////////////////////////////////////////////
//									CTYPE                                    //
///////////////////////////////////////////////////////////////////////////////

int					ft_isalpha(int c);
int					ft_isdigit(int i);
int					ft_islower(int c);
int					ft_isupper(int c);
int					ft_isspace(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_atoi(const char *str);
int					ft_safe_atoi(const char *str, int *val);
int					ft_safe_atoi_ps(const char *str, int *val);
double				ft_atof(char *str);

///////////////////////////////////////////////////////////////////////////////
//									STRING                                   //
///////////////////////////////////////////////////////////////////////////////

int					ft_startswith(char *str, char *start);
char				**ft_split(char *str, char c);
size_t				ft_strlen(const char *s);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strjoin(char const *s1, char const *s2);
char				**ft_sarr_free(char **arr);
char				*ft_strdup(char *str);
char				**ft_split_spaces(char *str);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strnstr(const char *big, const char *little,
						size_t len);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));

///////////////////////////////////////////////////////////////////////////////
//									PRINT                                    //
///////////////////////////////////////////////////////////////////////////////

void				ft_putstr(char *s);
size_t				ft_putstr_fd(char *str, int fd);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);

///////////////////////////////////////////////////////////////////////////////
//									MATH                                     //
///////////////////////////////////////////////////////////////////////////////

int					ft_iseven(int i);
int					ft_isodd(int i);
int					ft_abs(int n);

///////////////////////////////////////////////////////////////////////////////
//									OTHERS                                   //
///////////////////////////////////////////////////////////////////////////////

void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *s, int c, size_t n);
void				*ft_bzero(void *s, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_calloc(size_t count, size_t size);

///////////////////////////////////////////////////////////////////////////////
//									LINKED LIST                              //
///////////////////////////////////////////////////////////////////////////////

t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));

///////////////////////////////////////////////////////////////////////////////
//									VECTOR										//
///////////////////////////////////////////////////////////////////////////////

typedef struct s_vector
{
	double			x;
	double			y;
	double			z;
}					t_vec;


t_vec 	ft_add_vectors(t_vec v1, t_vec v2);
t_vec	ft_subtract_vectors(t_vec v1, t_vec v2);
t_vec	ft_hadamard_product(t_vec v1, t_vec v2);

t_vec	ft_scalar_multi(t_vec v1, double scalar);
t_vec	ft_scalar_div(t_vec v1, double scalar);

double	ft_dot_product(t_vec v1, t_vec v2);
t_vec	ft_cross_product(t_vec v1, t_vec v2);

t_vec	ft_unit_vector(t_vec v1);
t_vec	ft_random_vector(unsigned int seed);
t_vec	ft_random_vector_in_unit_sphere(int seed);
t_vec	ft_random_vector_in_hemisphere(int seed, t_vec normal);

t_vec	ft_new_vector(double x, double y, double z);
t_vec	ft_invert_vector(t_vec vec);
t_vec	ft_abs_vector(t_vec color);

double	ft_vector_length(t_vec v1);
// double	ft_length_squared(t_vec vector);
void	ft_vector_print(t_vec vector);
 
bool ft_isequal(t_vec a, t_vec b);

int		ft_lcg_random(unsigned int seed);
int		ft_xorshift_random(int seed);
int		ft_xslcg_random(unsigned int seed);


#endif