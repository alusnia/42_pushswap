CC			= cc

CFLAGS		= -Wall -Wextra -Werror -g -I$(LIB_DIR)/incs -I$(INCS_DIR)

NAME		= push_swap

LIB_DIR		= ./lib

LIB			= $(LIB_DIR)/libftplus.a

INCS_DIR	= ./incs

INCS 		= $(INCS_DIR)/push_swap.h

OBJS_DIR	= ./objs

OBJS		= $(addprefix $(OBJS_DIR)/,$(SRCS:.c=.o))

SRCS_DIR	= ./srcs

SRCS		= main.c push_swap_utils.c push_swap_utils2.c lst_manage.c quicksort.c \
			manage_program.c export_arg.c turk_alg.c turk_alg_utils1.c turk_alg_utils2.c

all: $(NAME)

$(NAME): $(LIB) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $(NAME)

$(LIB):
	$(MAKE) -C $(LIB_DIR)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(INCS) | $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

clean:
	rm -rf $(OBJS_DIR)
	$(MAKE) -C $(LIB_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIB_DIR) fclean

re: fclean all

del_lib:
	@echo $(SEP)
	@echo "Deleting library libftplus..."
	@echo $(SEP)
	$(MAKE) -C $(LIB_DIR) del_lib

.PHONY: all clean fclean re del_lib
