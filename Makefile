NAME = push_swap
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDES = -I . -I $(LIBFT_DIR)/includes -I $(LIBFT_DIR)/dependency_includes
CC = cc
CFLAGS = -Wall -Werror -Wextra $(INCLUDES)
SRC_FILES = src/teste.c src/ops_swap_stacks.c
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

.PHONY: all clean fclean re
