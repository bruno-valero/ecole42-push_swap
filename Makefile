NAME = push_swap
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDES = -I . -I $(LIBFT_DIR)/includes -I $(LIBFT_DIR)/dependency_includes
CC = cc
CFLAGS = -Wall -Werror -Wextra $(INCLUDES)
SRC_FILES = src/ops_rotate_stacks.c src/ops_swap_stacks.c src/ps_stack_actions.c \
			src/ps_stack.c src/push_swap.c src/validate_input_number.c src/main.c
SLEEP = 0.07

all: $(NAME)

$(NAME): $(SRC_FILES) $(LIBFT)
	@echo ">> compiling './$@'..." && sleep $(SLEEP)
	@$(CC) $(CFLAGS) $^ -o $@

$(LIBFT):
	@echo ">> compiling './$@'..." && sleep $(SLEEP)
	@make -s -C $(LIBFT_DIR) SLEEP="$(SLEEP)"

clean:
	@echo ">> cleanning './$(LIBFT_DIR)'..." && sleep $(SLEEP)
	@make -s -C $(LIBFT_DIR) SLEEP="$(SLEEP)"

fclean: clean
	@echo ">> deletting './$(LIBFT)'..." && sleep $(SLEEP)
	@make -s -C $(LIBFT_DIR) fclean SLEEP="$(SLEEP)"
	@echo ">> deletting './$(NAME)'..." && sleep $(SLEEP)
	@rm $(NAME)

re: fclean all

test: re
	clear
	./push_swap 10 20 30 "42 52 62" 70 80

.PHONY: all clean fclean re
