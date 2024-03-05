NAME = so_long

SRC = so_long.c processing.c map_checker.c ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c map_parser.c processes.c press.c

OBJS = $(SRC:.c=.o)

MLX = ./minilibx
LIBFT = ./libft

MINILIBX_PATH = ./minilibx
LIBFT_PATH = ./libft

CFLAGS = -Wall -Werror -Wextra -I$(MLX) -I$(LIBFT_PATH)

all: $(NAME)

$(NAME): mlx libft
	gcc $(CFLAGS) -o $(NAME) $(SRC) -L$(MINILIBX_PATH) -lmlx -L$(LIBFT_PATH) -lft -framework OpenGL -framework AppKit

clean:
	rm -rf $(OBJS)
	rm -rf $(MINILIBXOBJ)
	rm -rf ./minilibx/libmlx.a

fclean: clean
	rm -rf $(NAME)

re: fclean all

mlx:
	make -C $(MINILIBX_PATH) all

libft:
	make -C $(LIBFT_PATH) all
