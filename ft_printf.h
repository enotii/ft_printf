/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <mbeahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 18:53:51 by mbeahan           #+#    #+#             */
/*   Updated: 2019/04/06 17:11:10 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#include "libft/libft.h"
#include <stdarg.h>

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

void    zeroing_args(t_printf **list);
void    parse_flags(char *string, t_printf *list);
void    ft_parse(char *string);
int     ft_printf(const char *format, ...);
void    parse_precision(char *string, t_printf *list);
void    parse_width(char *string, t_printf *list);
void    parse_size(char *string, t_printf *list);
int     parse_type(char *string, t_printf *list);

#endif
