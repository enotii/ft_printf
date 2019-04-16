/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <mbeahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 18:53:51 by mbeahan           #+#    #+#             */
/*   Updated: 2019/04/16 21:19:49 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#include "libft/libft.h"
#include <stdarg.h>
#include <stdio.h>

typedef struct  s_printf
{
    char    minus;
    char    plus;
    char    space;
    char    bar;
    char    zero;
    int     width;
    int     precision;
    char    *size;
    char    type;
}               t_printf;

//-----------------Parse function's-----------------//
void    parse_flags(char *string, t_printf *list);
void    parse_size(char *string, t_printf *list);
int     parse_type(char *string, t_printf *list);
void    parse_precision(char *string, t_printf *list);
void    parse_width(char *string, t_printf *list);
//----------------Print char and string-------------//
void    ft_print_char(t_printf *list, int c);
void    ft_print_string(t_printf *list, char *string);
//------------------Print pointer-------------------//
void    parse_address(t_printf *list, void *address);
void    get_string_addres(t_printf *list, int *array, int count);
//-------------------Print unsigned-----------------//
void    unsigned_l(t_printf *list, unsigned long long u);
void    unsigned_ll(t_printf *list, unsigned long long u);
void    unsigned_h(t_printf *list, unsigned long long u);
void    unsigned_hh(t_printf *list, unsigned long long u);
void    print_unsigned(char *string, t_printf *list);
//------------------Help function's-----------------//
void    zeroing_args(t_printf **list);
void    ft_print(char *string, int start);
void    reverse_string(char *string, t_printf *list);
//----------------------PRINTF----------------------//
int     ft_printf(const char *format, ...);

#endif
