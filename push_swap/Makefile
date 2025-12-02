# Source files
SRCS = linked_list.c linked_list2.c \
main.c \
operations_utils.c operations_utils_2.c operations_utils_3.c operations_utils_4.c \
push.c rotate.c r_rotate.c swap.c \

# Object files
OBJS = $(SRCS:.c=.o)

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Output library name
NAME = libftpushswap.a

# Default target
all: $(NAME)

# Build the library
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

# Compile each .c into .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up object files
clean:
	rm -f $(OBJS)

# Clean up everything
fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re
