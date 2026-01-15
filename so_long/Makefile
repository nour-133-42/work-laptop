NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

# MiniLibX paths
MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a

LDFLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

SRCS = so_long.c so_long_utils_3.c so_long_utils_4.c so_long_utils_5.c \
       validation_utils_1.c so_long_utils_2.c so_long_utils.c \
       validation_utils_2.c \
       get_next_line/get_next_line.c \
       get_next_line/get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

all: $(MLX_LIB) $(NAME)

# Build MiniLibX
$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
