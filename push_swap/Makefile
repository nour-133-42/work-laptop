# ===================== VARIABLES =====================

CC      = cc
CFLAGS  = -Wall -Wextra -Werror

NAME        = push_swap
NAME_BONUS  = checker



# ===================== SOURCES =======================

SRCS =  linked_list.c linked_list2.c \
        main.c \
        operations_utils.c operations_utils_2.c operations_utils_3.c \
        operations_utils_4.c operations_utils_5.c \
        push.c rotate.c r_rotate.c swap.c

SRCS_BONUS = checker.c \
             get_next_line/get_next_line.c \
             get_next_line/get_next_line_utils.c \
             push_bonus.c rotate_bonus.c r_rotate_bonus.c swap_bonus.c \
             operations_utils.c operations_utils_2.c operations_utils_3.c \
             operations_utils_4.c operations_utils_5.c \
             linked_list.c linked_list2.c

# ===================== OBJECTS =======================

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)


# ===================== RULES =========================

all: $(NAME)

bonus: $(NAME_BONUS)

# ---------- push_swap ----------
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

# ---------- checker ----------
$(NAME_BONUS): $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(OBJS_BONUS) -o $(NAME_BONUS)

# ---------- object rules ----------
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# ===================== CLEAN =========================

clean:
	rm -rf $(OBJS_BONUS) $(OBJS)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all bonus clean fclean re
