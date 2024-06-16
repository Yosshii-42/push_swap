NAME	=	push_swap
CFLAGS	=	-Wall -Wextra -Werror -g
SRCS	=	src/main.c \
			src/list.c \
			src/move_nodes.c \
			src/order.c
			# src/mathematics_part.c \
			# src/open_and_close.c \
			# src/handler.c \
			# src/data_set.c
OBJS	=	$(SRCS:.c=.o)
FRAC_INC = push_swap.h
# MINILIBX_DIR := ./minilibx_opengl
# MINILIBX := $(MINILIBX_DIR)/libmlx.a

# INCLUDES := -I$(MINILIBX_DIR)
# LDFLAGS := -L$(MINILIBX_DIR)
# LIBS	=	-lm -lmlx
LIBFT	= ./libft/libft.a

.PHONY: all
all: $(NAME)

$(NAME): $(OBJS) $(FRAC_INC)
	make -C ./libft
	# make -C minilibx_opengl
	$(CC) $(OBJS) $(LIBFT) -o $(NAME)
	# $(CC) $(OBJS) $(LIBFT) $(LDFLAGS) $(LIBS) -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# $(MINILIBX):
# 	$(MAKE) -j4 -C $(MINILIBX_DIR)

bonus: all

clean:
	make fclean -C ./libft
	# make fclean -C ./minilibx_opengl
	rm -f $(OBJS) 

fclean: clean
	rm -f $(NAME)
	# $(MAKE) -C $(MINILIBX_DIR) clean

.PHONY: re clean fclean bonus
re: fclean all
