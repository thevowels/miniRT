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
			-I ./includes


SRCS	:= src/main.c

SRCS_CAMERA = camera.c
SRCS_OBJECTS = plane.c
SRCS_RENDER	= render.c
SRCS_VECTOR = vec_ops.c vec_arithmetic.c

SRCS += $(addprefix ./src/camera/, $(SRCS_CAMERA))

SRCS += $(addprefix ./src/objects/, $(SRCS_OBJECTS))

SRCS += $(addprefix ./src/render/, $(SRCS_RENDER))

SRCS += $(addprefix ./src/vector/, $(SRCS_VECTOR))


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