PROGRAMNAME = so_long

CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRC = so_long.c processing.c map_checker.c ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c map_parser.c

OBJS = $(SRC:.c=.o)

LIBFT = ./libft/libft.a

LFLAGS = $(LIBFT)

all: $(PROGRAMNAME)

$(PROGRAMNAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LFLAGS) -o $(PROGRAMNAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(PROGRAMNAME)

re: fclean all