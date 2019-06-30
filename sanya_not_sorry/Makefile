# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbeahan <mbeahan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/30 16:06:21 by mbeahan           #+#    #+#              #
#    Updated: 2019/06/30 16:06:23 by mbeahan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS = ft_printf.c ft_parse.c ft_print_float.c ft_print_int.c ft_print_octal.c ft_print_pointer.c \
	   ft_print_string_char.c ft_print_unsigned.c ft_print_x.c help_functions.c 

OBJS = $(SRCS:.c=.o)

all: $(NAME) 

$(NAME):
	@gcc -c -Wall -Werror -Wextra libft/*.c -I libft/libft.h
	@gcc -c $(SRCS)
	@ar rc $(NAME) *.o
 
clean:
	@rm -rf *.o libft/*.o libft/libft.a

fclean: clean
	@rm -rf $(NAME)

re: fclean all