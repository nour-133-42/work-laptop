NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
INCLUDES = -I.
LDFLAGS = -lmlx -lXext -lX11 -lm
SRCS = so_long.c so_long_utils_3.c so_long_utils_4.c validation_utils_1.c so_long_utils_2.c so_long_utils.c validation_utils_2.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
OBJS = $(SRCS:.c=.o)
all: $(NAME)
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) $(LDFLAGS) -o $(NAME)
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
clean:
	rm -f $(OBJS)
	make  clean
fclean: clean
	rm -f $(NAME)
	make  fclean
re: fclean all
.PHONY: all clean fclean re