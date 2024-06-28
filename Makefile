NAME		= push_swap
# NAME_B		= checker
CFLAGS		= -Wall -Wextra -Werror -g
# CFLAGS		+= -fsanitize=address
SRC_M		= src/main.c
# SRC_B		= src/main_bonus.c
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
# OBJ_B		= $(SRC_B:.c=.o)
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

# bonus: $(NAME_B)

# $(NAME_B): $(OBJ_B) $(OBJS) $(FRAC_INC)
# 	make -C ./libft
# 	$(CC) $(CFLAGS) $(OBJ_B) $(OBJS) $(LIBFT) -o $(NAME_B)

clean:
	make fclean -C ./libft
	rm -f $(OBJS) $(OBJ_M)

fclean: clean
	rm -f $(NAME)

.PHONY: re clean fclean bonus
re: fclean all
