NAME	=	push_swap
CFLAGS	=	-Wall -Wextra -Werror -g
# CFLAGS  += -fsanitize=address
SRCS	=	src/main.c \
			src/initial_utilities.c \
			src/list.c \
			src/move_nodes.c \
			src/order_p_s.c \
			src/order_rotate.c \
			src/order_rev.c \
			src/sort.c
			
			# src/index.c
OBJS	=	$(SRCS:.c=.o)
FRAC_INC = push_swap.h
LIBFT	= ./libft/libft.a

.PHONY: all
all: $(NAME)

$(NAME): $(OBJS) $(FRAC_INC)
	make -C ./libft
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

bonus: all

clean:
	make fclean -C ./libft
	rm -f $(OBJS) 

fclean: clean
	rm -f $(NAME)

.PHONY: re clean fclean bonus
re: fclean all
