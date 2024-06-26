NAME		= push_swap
NAME_BONUS  = checker
CFLAGS		= -Wall -Wextra -Werror -g
# CFLAGS		+= -fsanitize=address
SRCS		= src/main.c \
			  src/initialize.c \
			  src/check_and_error.c \
			  src/list.c \
			  src/node_hundling.c \
			  src/command_p_s.c \
			  src/command_r.c \
			  src/command_rr.c \
			  src/operations.c \
			  src/operation_utils.c 
SRCS_BONUS	= src/main_bonus.c \
			  src/initialize.c \
			  src/check_and_error.c \
			  src/list.c \
			  src/node_hundling.c \
			  src/func_push_swap.c \
			  src/func_rotate.c \
			  src/func_rev.c \
			  src/operations.c \
			  src/operation_utils.c 
OBJS	    = $(SRCS:.c=.o)
OBJS_BONUS  = $(SRCS_BONUS:.c=.o)
FRAC_INC    = push_swap.h
LIBFT	    = ./libft/libft.a

.PHONY: all
all: $(NAME)

$(NAME): $(OBJS) $(FRAC_INC)
	make -C ./libft
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS) $(FRAC_INC)
	# touch bonus
	make -C ./libft
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) -o $(NAME_BONUS)

clean:
	make fclean -C ./libft
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

.PHONY: re clean fclean bonus
re: fclean all
