NAME		= push_swap
CFLAGS		= -Wall -Wextra -Werror -g
# CFLAGS		+= -fsanitize=address
SRC_M		= src/main.c
SRCS		= src/initialize_1.c \
			  src/initialize_2.c \
			  src/list.c \
			  src/node_hundling.c \
			  src/command_p_s.c \
			  src/command_r.c \
			  src/command_rr.c \
			  src/operation.c \
			  src/operation_utils.c 
OBJ_M		= $(SRC_M:.c=.o)
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

clean:
	make fclean -C ./libft
	rm -f $(OBJS) $(OBJ_M)

fclean: clean
	rm -f $(NAME)

.PHONY: re clean fclean
re: fclean all
