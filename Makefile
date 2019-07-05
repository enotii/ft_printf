NAME = ft_printf

all: $(NAME)
$(NAME):
	make -C libft/ 
	clang -I libft/ -o ft_print_float.o ft_print_float.c
	clang -I libft/ -o ft_parse_nbr.o ft_parse_nbr.c
	clang -I libft/ -o ft_parse_size.o ft_parse_size.c
	clang -I libft/ -o ft_parse_size.o ft_parse_string.c
	clang -I libft/ -o ft_print_char_string.o ft_print_char_string.c
	clang -I libft/ -o ft_print_other.o ft_print_other.c
	clang -I libft/ -o ft_printf.o ft_printf.c
	clang -I libft/ -o ft_printnbr_logic.o ft_printnbr_logic.c
	clang -I libft/ -o help_functions.o help_functions.c
	clang -I libft/ -o main.o -c main.c
	clang -o $(NAME) main.o ft_print_float.o ft_parse_nbr.o ft_parse_size.o ft_parse_string.o ft_print_char_string.o ft_print_other.o ft_printf.o ft_printnbr_logic.o help_functions.o -I libft/ -L libft/ -lft
clean:
	rm -rf libft/*.o
	rm -rf *.o
fclean: clean
	rm -rf $(NAME)
	rm -rf libft/libft.a
re: fclean all

debug:
	 gcc -ggdb main.c ft_print_float.c ft_bzero.c ft_parse_nbr.c ft_parse_size.c ft_parse_string.c ft_print_char_string.c ft_print_other.c ft_printf.c ft_printnbr.c ft_printnbr_logic.c ft_strlen.c help_functions.c -I libft/ -L libft/ -lft

val:
	valgrind --leak-check=full ./ft_printf test10.fillitf	
