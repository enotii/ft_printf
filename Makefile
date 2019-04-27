NAME = ft_printf

all: $(NAME)
$(NAME):
	make -C libft/ 
	clang -I libft/ -o ft_parse.o -c ft_parse.c
	clang -I libft/ -o ft_print_pointer.o -c ft_print_pointer.c
	clang -I libft/ -o ft_print_string_char.o -c ft_print_string_char.c
	clang -I libft/ -o ft_print_unsigned.o -c ft_print_unsigned.c
	clang -I libft/ -o ft_print_int.o -c ft_print_int.c
	clang -I libft/ -o ft_print_x.o -c ft_print_x.c
	clang -I libft/ -o ft_print_octal.o -c ft_print_octal.c
	clang -I libft/ -o ft_printf.o -c ft_printf.c
	clang -I libft/ -o help_functions.o -c help_functions.c
	clang -I libft/ -o ft_print_float.o -c ft_print_float.c
	clang -o $(NAME) ft_parse.o ft_print_pointer.o ft_print_string_char.o ft_print_unsigned.o ft_print_int.o ft_print_x.o ft_print_octal.o help_functions.o ft_printf.o ft_print_float.o -I libft/ -L libft/ -lft
clean:
	rm -rf libft/*.o
	rm -rf *.o
fclean: clean
	rm -rf $(NAME)
	rm -rf libft/libft.a
re: fclean all

debug:
	 gcc -ggdb ft_parse.c ft_print_pointer.c ft_print_string_char.c ft_print_unsigned.c ft_print_int.c ft_print_x.c ft_print_octal.c help_functions.c ft_printf.c -I libft/ -L libft/ -lft

val:
	valgrind --leak-check=full ./ft_printf test10.fillitf	