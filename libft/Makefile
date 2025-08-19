NAME = libft.a
# ------------------------ Dependencies -------------------------------
STACK_PATH = src/lists/stack
STACK = $(STACK_PATH)/libstack.a
# ----------
LIBSTR_PATH = src/libstr
LIBSTR = $(LIBSTR_PATH)/libstr.a
# ********************************************************************
INCLUDES = -I $(STACK_PATH)/includes -I $(LIBSTR_PATH)/includes
CC = cc
CFLAGS = -Wall -Werror -Wextra $(INCLUDES)
FUNCTIONS = ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_calloc.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_lstnew_bonus.c \
			ft_lstadd_front_bonus.c \
			ft_lstadd_back_bonus.c \
			ft_lstsize_bonus.c \
			ft_lstlast_bonus.c \
			ft_lstdelone_bonus.c \
			ft_lstclear_bonus.c \
			ft_lstiter_bonus.c \
			ft_lstmap_bonus.c
OBJ = obj
OBJ_FILES := $(FUNCTIONS:%.c=$(OBJ)/%.o)
DEPENDENCY_OBJS = dependency_objs
DEPENDENCY_LIBS = $(STACK) $(LIBSTR)

all: $(DEPENDENCY_LIBS) $(OBJ) $(DEPENDENCY_OBJS) $(NAME)

$(STACK):
	@make -C $(STACK_PATH)

$(LIBSTR):
	@make -C $(LIBSTR_PATH)

$(NAME): $(OBJ_FILES)
	@ar x $(STACK) --output $(DEPENDENCY_OBJS)
	@ar x $(LIBSTR) --output $(DEPENDENCY_OBJS)
	@ar rcs $@ $^ $(DEPENDENCY_OBJS)/*.o

$(OBJ):
	@mkdir $(OBJ)

$(DEPENDENCY_OBJS):
	@mkdir $(DEPENDENCY_OBJS)

$(OBJ)/%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make -C $(STACK_PATH) clean
	@make -C $(LIBSTR_PATH) clean
	@rm -rf $(OBJ) $(DEPENDENCY_OBJS)

fclean: clean
	@make -C $(STACK_PATH) fclean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
