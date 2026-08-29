NAME = libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC_CTYPE=	ft_isalpha.c ft_isdigit.c ft_isspace.c \
			ft_islower.c ft_isupper.c ft_tolower.c \
			ft_toupper.c ft_atoi.c ft_atof.c

SRC_PRINT = ft_putstr.c ft_putstr_fd.c ft_printf.c

SRC_MATH = ft_iseven.c ft_isodd.c

SRC_STRING = ft_startswith.c ft_split.c ft_strlen.c \
			ft_strncmp.c ft_strjoin.c ft_sarr_free.c \
			ft_strdup.c ft_split_spaces.c

SRC_OTHERS = ft_memcpy.c ft_memmove.c

SRC_LINKEDLISTS = ft_lstnew.c

SRCS += $(addprefix ./src/ctype/, $(SRC_CTYPE))

SRCS += $(addprefix ./src/print/, $(SRC_PRINT))

SRCS += $(addprefix ./src/math/, $(SRC_MATH))

SRCS += $(addprefix ./src/string/, $(SRC_STRING))

SRCS += $(addprefix ./src/others/, $(SRC_OTHERS))

SRCS += $(addprefix ./src/linked_list/, $(SRC_LINKEDLISTS))

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
