NAME		= push_swap
NAME_B		= checker
CFLAGS		= -Wall -Wextra -Werror
# CFLAGS		+= -fsanitize=address -g
SRC_M		= src/main.c
SRC_B		= src/bonus_main.c \
			  src/bonus_operation.c
SRCS		= src/check_argv.c \
			  src/check_double.c \
			  src/check_order.c \
			  src/compression.c \
			  src/make_stack.c \
			  src/put_result.c \
			  src/is_function.c \
			  src/list.c \
			  src/node_hundling.c \
			  src/command_p_s.c \
			  src/command_r.c \
			  src/command_rr.c \
			  src/sort_operation.c \
			  src/sort_operation_3.c \
			  src/sort_operation_4.c \
			  src/sort_operation_5.c \
			  src/sort_operation_6_to_20.c \
			  src/sort_operation_x.c \
			  src/check_index.c
OBJ_M		= $(SRC_M:.c=.o)
OBJ_B		= $(SRC_B:.c=.o)
OBJS	    = $(SRCS:.c=.o)
FRAC_INC    = push_swap.h
LIBFT	    = ./libft/libft.a

.PHONY: all
all: $(NAME)

$(NAME): $(OBJ_M) $(OBJS) $(FRAC_INC)
	make -C ./libft
	$(CC) $(CFLAGS) $(OBJ_M) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

bonus: $(NAME_B) $(NAME)

$(NAME_B): $(OBJ_B) $(OBJS) $(FRAC_INC)
	make -C ./libft
	$(CC) $(CFLAGS) $(OBJ_B) $(OBJS) $(LIBFT) -o $(NAME_B)

clean:
	make fclean -C ./libft
	rm -f $(OBJS) $(OBJ_M) $(OBJ_B)

fclean: clean
	rm -f $(NAME) $(NAME_B)

.PHONY: re clean fclean bonus
re: fclean all
