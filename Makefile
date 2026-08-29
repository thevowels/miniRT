NAME = miniRT

# Compiler
CC		=	cc
CFLAGS	=	-Wextra -Wall -Werror

# MLX42
LIBMLX		:= ./lib/MLX42
LIBMLX_F	:= $(LIBMLX)/build/libmlx42.a

HEADERS		:= -I ./includes -I $(LIBMLX)/include -I $(LIBFT_PATH)/includes $(GNL_PATH)
LIBS		:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm -g

#Libft
LIBFT_PATH	:=	./lib/libft/
LIBFT_NAME	:=	libft.a
LIBFT		:=	$(LIBFT_PATH)$(LIBFT_NAME)

# gnl
GNL_PATH	:= ./lib/gnl/
GNL_NAME	:= gnl.a
GNL			:= $(GNL_PATH)$(GNL_NAME)


# Includes
INC		:=	-I $(LIBMLX)/include\
			-I ./lib/libft/\


SRCS	:= src/main.c

OBJS	:= ${SRCS:.c=.o}

all:  $(LIBMLX_F) $(LIBFT) $(GNL) $(NAME)


# Compiling MLX42
$(LIBMLX_F):
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

# Making Libft
$(LIBFT):
	@echo "Making Libft..."
	@make -sC $(LIBFT_PATH)

$(GNL):
	@echo "Compiling gnl..."
	@make -sC $(GNL_PATH)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(INC)

# Compiling 
$(NAME): $(OBJS)
	@echo "Compiling MiniRT..."
	@$(CC) $(OBJS) $(LIBS) $(LIBFT)  $(INC) -o $(NAME)

clean:
	@echo "Cleaning object files..."
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build
	@make clean -sC $(LIBFT_PATH)
	@make clean -sC $(GNL_PATH)

fclean: clean
	@echo "Cleaning miniRT"
	@rm -f $(NAME)
	@make fclean -sC $(LIBFT_PATH)
	@make fclean -sC $(GNL_PATH)

re: clean all

.PHONY: all, clean, fclean, re, libmlx