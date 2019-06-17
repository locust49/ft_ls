W=-Wall -Wextra -Werror
SRC=./*.c
NAME=libft.a

all: $(NAME)

$(NAME):
	make -C ft_printf
	gcc -c $(W) $(SRC) -I libft.h
	ar rc $(NAME) *.o ft_printf/*.o
	ranlib $(NAME)
clean:
	make clean -C ft_printf
	rm -f *.o *.gch* .*.swp
fclean: clean
	rm -f $(NAME)
re: fclean all
