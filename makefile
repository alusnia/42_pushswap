# Compiler
CC = cc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror -g

# Executable Name
NAME = push_swap

# Source Files (all .c files in the current directory)
LIBFT_FILES = $(addprefix libft/, ft_substr.c ft_putnbr_fd.c ft_isdigit.c ft_atoi.c ft_isalpha.c \
        ft_memmove.c ft_isprint.c ft_memchr.c ft_striteri.c ft_putendl_fd.c \
        ft_strmapi.c ft_strrchr.c ft_toupper.c ft_memset.c ft_itoa.c \
        ft_isalnum.c ft_strtrim.c ft_putchar_fd.c ft_putstr_fd.c ft_strjoin.c \
        ft_strlcat.c ft_strdup.c ft_memcmp.c ft_memcpy.c ft_bzero.c ft_tolower.c \
        ft_strchr.c ft_strncmp.c ft_strnstr.c ft_strlcpy.c ft_strlen.c \
        ft_calloc.c ft_isascii.c ft_split.c ft_putptr_fd.c ft_puthex_fd.c ft_putunbr_fd.c \
		ft_putflt_fd.c ft_printf.c ft_isspace.c ft_atod.c ft_putdbl_fd.c ft_atol.c)

PUSH_SWAP_FILES = main.c push_swap_utils.c push_swap_utils2.c lst_manage.c quicksort.c \
		manage_program.c export_arg.c turk_alg.c turk_alg_utils1.c turk_alg_utils2.c

FILES = $(LIBFT_FILES) $(PUSH_SWAP_FILES)

# Object Files
OBJS = $(FILES:.c=.o)

# Headers
HEADERS = push_swap.h libft/libft.h

# Default target
all: $(NAME)

# Build executable
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

# Compile object files
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	rm -f $(OBJS)

# Remove executables and object files
fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: fclean all

# Phony targets
.PHONY: all clean fclean re
