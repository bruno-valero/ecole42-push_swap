NAME = push_swap
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDES = -I . -I $(LIBFT_DIR)/includes -I $(LIBFT_DIR)/dependency_includes
CC = cc
CFLAGS = -Wall -Werror -Wextra -g3 $(INCLUDES)
SRC_FILES = src/ops_rotate_stacks.c src/ops_swap_stacks.c src/ps_stack_actions.c \
			src/ps_stack.c src/push_swap.c src/validate_input_number.c src/main.c \
			src/ps_stack_content.c src/push_swap_ops_both.c src/push_swap_ops_push.c \
			src/push_swap_ops_rotate.c src/push_swap_ops_swap.c src/valid_input_number.c \
			src/turk_find_closest_smaller.c src/turk_find_closest_bigger.c src/turk_sort_three.c \
			src/turk_sort.c

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
	@rm -rf $(NAME)

re: fclean all

test: re
	clear
	./push_swap 10 20 30 "42 52 62" 70 80

.PHONY: all clean fclean re
