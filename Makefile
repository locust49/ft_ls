SRCS =	display.c display_tools.c display_list.c display_list_tools.c \
		list_args.c list_args_tools.c long_list.c long_listing_blocks.c \
		long_listing_printing.c	mergesort.c operands.c operands_tools.c \
		print_content.c print_content_tools.c quicksort.c sort_args.c \
		sort_args_time.c sort_input.c sort_input_tools.c sort_input_time.c \
		tools.c width.c width_tools.c \
		main.c
OBJS = 	display.o display_tools.o display_list.o display_list_tools.o \
		list_args.o list_args_tools.o long_list.o long_listing_blocks.o \
		long_listing_printing.o mergesort.o operands.o operands_tools.o \
		print_content.o print_content_tools.o quicksort.o sort_args.o \
		sort_args_time.o sort_input.o sort_input_tools.o sort_input_time.o \
		tools.o width.o width_tools.o \
		main.o
HDRS = ft_ls.h libft/libft.h
FLGS = -Wall -Werror -Wextra
EXEC = ft_ls
NAME = ft_ls

all: $(NAME)

$(NAME):
	make -C libft
	gcc $(FLGS) -c $(SRCS) -I $(HDRS)
	gcc -o $(EXEC) $(OBJS) libft/libft.a

clean:
	make clean -C libft/
	rm -f $(OBJS)
fclean: clean
	make fclean -C libft/
	rm -f $(EXEC)
re: fclean all
