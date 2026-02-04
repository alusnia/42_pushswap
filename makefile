# Compiler
CC = cc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror -g

# Executable Name
NAME = push_swap

LIBFT_DIR = ./libft

LIBFT = $(LIBFT_DIR)/libft.a

FILES = main.c push_swap_utils.c push_swap_utils2.c lst_manage.c quicksort.c \
		manage_program.c export_arg.c turk_alg.c turk_alg_utils1.c turk_alg_utils2.c

# Object Files
OBJS = $(FILES:.c=.o)

# Headers
HEADERS = push_swap.h $(LIBFT_DIR)/libft.h

# Default target
all: $(NAME)

# Build executable
$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

# Compile object files
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Build libft
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Clean object files
clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

# Remove executables and object files
fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

# Rebuild everything
re: fclean all

# Phony targets
.PHONY: all clean fclean re
