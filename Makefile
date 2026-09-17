NAME = miniRT

CC = cc
CFLAGS = -Wextra -Wall -Werror

LIBMLX := ./lib/MLX42
LIBMLX_F := $(LIBMLX)/build/libmlx42.a

LIBFT_PATH := ./lib/libft/
LIBFT := $(LIBFT_PATH)libft.a

GNL_PATH := ./lib/gnl/
GNL := $(GNL_PATH)gnl.a

INC := -I ./includes -I $(LIBMLX)/include -I ./lib/libft/includes
LIBS := $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

SRCS := src/main.c \
	src/init/init.c \
	src/error/error.c \
	src/utils/utils.c \
	src/utils/clean.c \
	src/parser/parser.c \
	src/parser/scene.c \
	src/parser/parse_line.c \
	src/parser/parse_obj.c \
	src/parser/parse_val.c \
	src/parser/parse_val2.c \
	src/render/render.c \
	src/render/camera.c \
	src/render/ray.c \
	src/render/hit_sphere.c \
	src/render/hit_plane.c \
	src/render/hit_cyl.c \
	src/render/shade.c

OBJS := $(SRCS:.c=.o)

all: $(LIBMLX_F) $(LIBFT) $(GNL) $(NAME)

$(LIBMLX_F):
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(LIBFT):
	@echo "Making Libft..."
	@make -sC $(LIBFT_PATH)

$(GNL):
	@echo "Making GNL..."
	@make -sC $(GNL_PATH)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(INC)

$(NAME): $(OBJS) $(GNL)
	@echo "Compiling MiniRT..."
	@$(CC) $(OBJS) $(GNL) $(LIBFT) $(LIBS) -o $(NAME)

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

re: fclean all

.PHONY: all clean fclean re
