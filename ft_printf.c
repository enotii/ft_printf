/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <mbeahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 18:52:56 by mbeahan           #+#    #+#             */
/*   Updated: 2019/03/30 20:56:35 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void zeroing_args(t_printf **list)
{
    (*list)->minus = 0;
    (*list)->plus = 0;
    (*list)->space = 0;
    (*list)->bar = 0;
    (*list)->zero = 0;
    (*list)->width = 0;
    (*list)->precision = 0;
    (*list)->size = 0;
    (*list)->type = 0;
}

void     parse_flags(char *string, t_printf *list)
{
    int i;
    int check;

    check = 0;
    i = 0;
    while (string[i] && check < 2)
    {
        if (string[i] == '%' && string[i + 1] != '%')
        {
            i++;
            check++;
        }
        if (check > 0)
        {
            if (string[i] == '+')
                list->plus = '+';
            if (string[i] == '-')
                list->minus = '-';
            if (string[i] == '0')
                list->zero = '0';
            if (string[i] == ' ')
                list->space = ' ';
            if (string[i] == '#')
                list->bar = '#';
            if (string[i] != '+' && string[i] != '-' && string[i] != '0' && string[i] != ' ' && string[i] != '#')
                break ;
        }
        i++;
    }
}

int    parse_width(char *string, t_printf *list)
{
    int     i;
    int     len;
    char    *width;
    int     check;
    int     tmp;

    i = 0;
    check = 0;
    len = 0;
    tmp = 0;
    while (string[i] && check < 2)
    {
        if (string[i] == '%' && string[i + 1] != '%')
        {
            i++;
            check++;
        }
        if (string[i] == '+' || string[i] == '-' || string[i] == '0' || string[i] == ' ' || string[i] == '#')
            i++;
        if (string[i] > 47 && string[i] < 58)
        {
            tmp = i;
            while(string[i] > 47 && string[i] < 58)
            {
                 i++;
                len++;
            }
             break ;
        }
        if ((string[i] != '+' && string[i] != '-' && string[i] != '0' && string[i] != ' ' && string[i] != '#') && (!(string[i] > 47 && string[i] < 58)))
             break ;
    }
    width = (char *)malloc(sizeof(char) * len);
    i = 0;
    while (i < len)
    {
        width[i] = string[tmp];
        i++;
        tmp++;
    }
    return (ft_atoi(width));
}

void    ft_parse(char *string)
{
    int i;
    t_printf *sooqa;

    i = 0;
    sooqa = (t_printf *)malloc(sizeof(t_printf));
    zeroing_args(&sooqa);
    while(string[i] != '%')
    {
        ft_putchar(string[i]);
        i++;
    }
    parse_flags(string, sooqa);
    sooqa->width = parse_width(string, sooqa);
}
int     ft_printf(const char *format, ...)
{
    int i;
    i = 0;
    va_list ap;
    va_start(ap,format);
    ft_parse((char *)format);
    return(0);
}
int main()
{
    ft_printf("%+-------+++", 123);
    //printf("%+-----+d", 123);
    return(0);
} 