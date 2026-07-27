CC = cc
CFLAGS = -Werror -Wall -Wextra
NAME = minishell

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC =	minishell.c \
		pars/pars.c \
		pars/token.c \
		pars/pars_and_lux.c \
		pars/build_arg.c \
		pars/build_redirs.c \
		pars/single_and_double.c \
		pars/expansion.c \
		pars/utils.c \
		pars/utils2.c \
		pars/token_utils.c \
		execution/execution.c \
		execution/execution_flow.c \
		execution/execution_helpers.c \
		execution/pipes.c \
		execution/pipes_utils.c \
		execution/single_cmd.c \
		execution/shell_cmd.c \
		execution/builtins_basic.c \
		execution/builtins_cd.c \
		execution/builtins_env.c \
		execution/builtins_pwd.c \
		execution/builtins_unset.c \
		execution/env_utils.c \
		execution/exec_command.c \
		execution/heredoc.c \
		execution/heredoc_utils.c \
		execution/redirection.c


OBJ = $(SRC:.c=.o)


all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME) -lreadline

$(LIBFT):
	@make -C $(LIBFT_DIR)

fclean:
	rm -f $(OBJ) $(NAME)
	@make fclean -C $(LIBFT_DIR)

clean:
	rm -f $(OBJ)
	@make -C $(LIBFT_DIR) clean

re: fclean all

run: all
	./$(NAME)

# vrun:
# 	valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes --trace-children=yes ./minishell

# supp:
# 	valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes --trace-children=yes --suppressions=readline.supp ./minishell

# valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes --suppressions=readline.supp ./minishell

rerun: re vrun

.PHONY: all clean fclean re run vrun rerun