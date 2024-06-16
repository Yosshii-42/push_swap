NAME	=	push_swap
CFLAGS	=	-Wall -Wextra -Werror -g
SRCS	=	src/main.c \
			src/list.c \
			src/move_nodes.c \
			src/order_p_s.c \
			src/order_rotate.c \
			src/order_rev.c
OBJS	=	$(SRCS:.c=.o)
FRAC_INC = push_swap.h
LIBFT	= ./libft/libft.a

.PHONY: all
all: $(NAME)

$(NAME): $(OBJS) $(FRAC_INC)
	make -C ./libft
	# make -C minilibx_opengl
	$(CC) $(OBJS) $(LIBFT) -o $(NAME)

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
