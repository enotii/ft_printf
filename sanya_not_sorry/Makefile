<<<<<<< HEAD
NAME = ft_printf
=======
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: caking <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/30 16:06:21 by mbeahan           #+#    #+#              #
#    Updated: 2019/07/03 22:51:07 by caking           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS = ft_printf.c ft_parse.c ft_print_float.c ft_print_int.c ft_print_octal.c ft_print_pointer.c \
	   ft_print_string_char.c ft_print_unsigned.c ft_print_x.c help_functions.c 

OBJS = $(SRCS:.c=.o)

TEST = main.c
HEADER = include

all: $(NAME) 
>>>>>>> bf6d9a38b9f32a060f9063247fa7d0315445df21

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
	clang -I libft/ -o ft_print_float.o -c ft_print_float.c
	clang -I libft/ -o ft_printf.o -c ft_printf.c
	clang -I libft/ -o help_functions.o -c help_functions.c
	clang -o $(NAME) ft_parse.o ft_print_pointer.o ft_print_string_char.o ft_print_unsigned.o ft_print_int.o ft_print_x.o ft_print_octal.o ft_print_float.o help_functions.o ft_printf.o -I libft/ -L libft/ -lft
clean:
	rm -rf libft/*.o
	rm -rf *.o
fclean: clean
	rm -rf $(NAME)
	rm -rf libft/libft.a
re: fclean all

debug:
	 gcc -ggdb ft_parse.c ft_print_pointer.c ft_print_string_char.c ft_print_unsigned.c ft_print_int.c ft_print_x.c ft_print_octal.c ft_print_float.c help_functions.c ft_printf.c -I libft/ -L libft/ -lft

<<<<<<< HEAD
val:
	valgrind --leak-check=full ./ft_printf test10.fillitf	
=======
re: fclean all

test:
	gcc $(TEST) $(NAME)	-I $(HEADER)
>>>>>>> bf6d9a38b9f32a060f9063247fa7d0315445df21
