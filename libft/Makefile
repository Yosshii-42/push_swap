NAME 	= libft.a
SRCS	= ft_isdigit.c \
		  ft_strncmp.c \
		  ft_atoi.c \
		  ft_atol.c \
		  ft_putstr_fd.c \
		  get_next_line.c
OBJS	= $(SRCS:.c=.o)
OBJS_B	= $(SRCS_B:.c=.o)
CC		= cc
FLAGS	= -Wall -Wextra -Werror 
HEADDIR	= ./includes

%.o:%.c
	$(CC) $(FLAGS) -I$(HEADDIR) -c $< -o $@

$(NAME): $(OBJS) $(OBJS_B)
	# make -C ./printf
	ar rcs $(NAME) $(OBJS) $(OBJS_B)

all: $(NAME)

clean:
	rm -f $(OBJS) $(OBJS_B)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
