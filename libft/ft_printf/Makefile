FLGS=	-Wall -Wextra -Werror
SRCS=	adjust.c bin_oct.c color.c date.c dispatcher.c dollar.c \
		double.c format.c get_float.c get_long_double.c getters.c \
		getters_float.c length.c long_double.c nans_spnplus_minus.c \
		nonprintable.c operations_float.c options.c print_address.c \
		print_chars_strings.c print_floats.c print_form.c \
		print_hex.c print_ints.c putnbr.c putnbroct.c \
		setters.c unicode.c unicode_format.c \
		printf.c
OBJS=	*.o

all:
		gcc -c $(FLGS) $(SRCS) -I printf.h
clean:
	rm -f *.gch $(OBJS) .*.swp
re: clean all
