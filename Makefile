NAME = ft_printf

all: $(NAME)
$(NAME):
	make -C libft/ 
	clang -I libft/ -o ft_printf.o -c ft_printf.c
	clang -o $(NAME) ft_printf.o -I libft/ -L libft/ -lft
clean:
	rm -rf libft/*.o
	rm -rf *.o
fclean: clean
	rm -rf $(NAME)
	rm -rf libft/libft.a
re: fclean all

debug:
	 gcc -ggdb ft_printf.c -I libft/ -L libft/ -lft

val:
	valgrind --leak-check=full ./ft_printf test10.fillitf	