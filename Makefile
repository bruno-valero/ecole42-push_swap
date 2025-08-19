NAME = push_swap
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDES = -I includes -I $(LIBFT_DIR) -I $(LIBFT_DIR)/src/lists/stack/includes
CC = cc
CFLAGS = -Wall -Werror -Wextra $(INCLUDES)
SRC_FILES = src/teste.c src/ops_swap_stacks.c

all: $(NAME)

$(NAME): $(SRC_FILES) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	make -C $(LIBFT_DIR)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm $(NAME)

re: fclean all

.PHONY: all clean fclean re
