NAME = push_swap
LIB = libft.a
LIBFTPRINTF = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = main.c operations.c algorithm.c errors.c rever_rotate.c \
		rotate.c utils.c pushandswap.c rare_sorts.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIB) $(LIBFTPRINTF)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIB) $(LIBFTPRINTF)

$(LIB):
	make -C libft
	cp libft/libft.a .

$(LIBFTPRINTF):
	make -C ft_printf
	cp ft_printf/libftprintf.a .

clean:
	rm -f $(OBJ)
	make -C libft clean
	make -C ft_printf clean

fclean: clean
	rm -f $(NAME) $(LIB) $(LIBFTPRINTF)
	make -C libft fclean
	make -C ft_printf fclean

re: fclean all

.PHONY: all clean fclean re
