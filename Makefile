NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(MINILIBX)

SRC = so_long.c processing.c map_checker.c map_parser.c press.c processes.c \
      ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c
OBJS = $(SRC:.c=.o)

LIBFT = ./libft
LIBFT_LIB = $(LIBFT)/libft.a
MINILIBX = ./minilibx
MINILIBX_LIB = $(MINILIBX)/libmlx.a
LFLAGS = -L$(LIBFT) -lft -L$(MINILIBX) -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_LIB) $(MINILIBX_LIB)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LFLAGS)

$(LIBFT_LIB):
	make -C $(LIBFT)

$(MINILIBX_LIB):
	make -C $(MINILIBX)

clean:
	rm -f $(OBJS)
	make -C $(LIBFT) clean
	make -C $(MINILIBX) clean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
