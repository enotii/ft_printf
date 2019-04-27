/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gachibass228 <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 18:53:51 by mbeahan           #+#    #+#             */
/*   Updated: 2019/04/27 16:17:02 by gachibass22      ###   ########.fr       */
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
//---------------------Print INT---------------------//
void    hh_int(t_printf *list, long long int d);
void    h_int(t_printf *list, long long int d);
void    ll_int(t_printf *list, long long int d);
void    l_int(t_printf *list, long long int d);
void    print_int(char *string, t_printf *list);
//---------------------Print Float--------------------//
void	print_float(t_printf *list, long double f);
//--------------------Print X ----------------------//
void     get_x_string(t_printf *list, int *array, int count);
void     default_x(t_printf *list, unsigned long long x);
void     hh_x(t_printf *list, unsigned long long x);
void     h_x(t_printf *list, unsigned long long x);
void     ll_x(t_printf *list, unsigned long long x);
void     l_x(t_printf *list, unsigned long long x);
//--------------------Print Octal-------------------//
void    get_o_string(t_printf *list, int *array, int count);
void    default_o(t_printf *list, unsigned long long x);
void    hh_o(t_printf *list, unsigned long long x);
void    h_o(t_printf *list, unsigned long long x);
void    ll_o(t_printf *list, unsigned long long x);
void    l_o(t_printf *list, unsigned long long x);
//------------------Help function's-----------------//
void    zeroing_args(t_printf **list);
void    ft_print(char *string, int start);
char    *reverse_string(char *string, t_printf *list);
//----------------------PRINTF----------------------//
int     ft_printf(const char *format, ...);

#endif
