NAME = libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC_CTYPE=	ft_isalpha.c ft_isdigit.c ft_isspace.c \
			ft_islower.c ft_isupper.c ft_tolower.c \
			ft_toupper.c ft_atoi.c ft_atof.c ft_safe_atoi_ps.c \
			ft_isalnum.c ft_isascii.c ft_isprint.c

SRC_PRINT = ft_putstr.c ft_putstr_fd.c ft_putchar_fd.c \
			ft_putendl_fd.c ft_putnbr_fd.c

SRC_MATH = ft_iseven.c ft_isodd.c ft_abs.c

SRC_STRING = ft_startswith.c ft_split.c ft_strlen.c \
			ft_strncmp.c ft_strjoin.c ft_sarr_free.c \
			ft_strdup.c ft_split_spaces.c ft_strchr.c \
			ft_strrchr.c ft_strlcpy.c ft_strlcat.c \
			ft_strnstr.c ft_substr.c ft_strtrim.c \
			ft_itoa.c ft_strmapi.c	ft_striteri.c

SRC_OTHERS = ft_memcpy.c ft_memmove.c ft_memset.c ft_bzero.c \
			 ft_memchr.c ft_memcmp.c ft_calloc.c

SRC_LINKEDLISTS = ft_lstadd_back.c  ft_lstadd_front.c  ft_lstclear.c  \
				ft_lstdelone.c  ft_lstiter.c  ft_lstlast.c  ft_lstmap.c \
				ft_lstnew.c  ft_lstsize.c

SRC_VECTOR = ft_abs_vector.c ft_cross_product.c ft_hadamard_product.c \
			ft_isequal.c ft_new_vector.c ft_random_vector_in_hemisphere.c \
			ft_scalar_div.c	ft_subtract_vectors.c ft_vector_length.c \
			ft_xorshift_random.c ft_add_vectors.c ft_dot_product.c \
			ft_invert_vector.c ft_lcg_random.c ft_random_vector.c \
			ft_random_vector_in_unit_sphere.c  ft_scalar_multi.c \
			ft_unit_vector.c ft_vector_print.c ft_xslcg_random.c


SRCS += $(addprefix ./src/ctype/, $(SRC_CTYPE))

SRCS += $(addprefix ./src/print/, $(SRC_PRINT))

SRCS += $(addprefix ./src/math/, $(SRC_MATH))

SRCS += $(addprefix ./src/string/, $(SRC_STRING))

SRCS += $(addprefix ./src/others/, $(SRC_OTHERS))

SRCS += $(addprefix ./src/linked_list/, $(SRC_LINKEDLISTS))

SRCS += $(addprefix ./src/vector/, $(SRC_VECTOR))


OBJS = $(SRCS:.c=.o)


INCLUDES = -I includes

.c.o:
	@echo "Compiling to get $@"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all: $(NAME) 

$(NAME): $(OBJS) includes/libft.h Makefile
	@echo "Archiving to get $(NAME) "
	@ar -rcs $(NAME) $(OBJS)

clean:
	@echo "Cleaning Object Files"
	@rm -f $(OBJS)

fclean: clean
	@echo "Cleaning Lib file"
	@rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean
