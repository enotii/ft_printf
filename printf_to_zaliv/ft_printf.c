/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <mbeahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 21:21:53 by mbeahan           #+#    #+#             */
/*   Updated: 2019/07/04 17:35:41 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    needed_to_print(t_printf *lst, va_list ap, char *s)
{
    if (lst->type == 'c')
        ft_print_char(lst, va_arg(ap, int));
    if (lst->type == 's')
        ft_print_string(lst, va_arg(ap, char *));
    if (lst->type == 'p')
        parse_address(lst, va_arg(ap, void *));
    if (lst->type == 'u')
    {
        if (lst->size == 0)
            default_unsigned(lst, va_arg(ap,unsigned long long));
        else if (ft_strcmp(lst->size, "hh") == 0)
            unsigned_hh(lst,va_arg(ap, unsigned long long));
        else if (lst->size[0] == 'h')
            unsigned_h(lst,va_arg(ap, unsigned long long));
        else if (ft_strcmp(lst->size, "ll") == 0)
            unsigned_ll(lst, va_arg(ap, unsigned long long));
        else if (lst->size[0] == 'l')
            unsigned_l(lst, va_arg(ap, unsigned long long));
        else if (lst->size[0] == 'j')
            unsigned_j(lst, va_arg(ap, unsigned long long));
    }
    if (lst->type == 'U')
        big_u(lst, va_arg(ap, unsigned long long));
    if (lst->type == 'd' || lst->type == 'i')
    {
        if (lst->size == 0 || lst->size[0] == 'z')
            default_int(lst,va_arg(ap, long long int));
        else if(ft_strcmp(lst->size, "hh") == 0)
            hh_int(lst,va_arg(ap, long long int));
        else if (lst->size[0] == 'h')
            h_int(lst,va_arg(ap, long long int));
        else if (ft_strcmp(lst->size, "ll") == 0)
            ll_int(lst, va_arg(ap, long long int));
        else if (lst->size[0] == 'l')
            l_int(lst, va_arg(ap, long long int));
        else if (lst->size[0] == 'j')
            j_int(lst, va_arg(ap,long long int));
    }
    if (lst->type == 'x' || lst->type == 'X')
    {
        if (lst->size == 0)
            default_x(lst,va_arg(ap, unsigned long long));
        else if (ft_strcmp(lst->size, "hh") == 0)
            hh_x(lst,va_arg(ap, unsigned long long));
        else if (lst->size[0] == 'h')
            h_x(lst,va_arg(ap, unsigned long long));
        else if (ft_strcmp(lst->size, "ll") == 0)
            ll_x(lst, va_arg(ap, unsigned long long));
        else if (lst->size[0] == 'l')
            l_x(lst, va_arg(ap, unsigned long long));
        else if (lst->size[0] == 'j')
            j_x(lst, va_arg(ap, unsigned long long ));
    }
    if (lst->type == 'o')
    {
        if (lst->size == 0)
            default_o(lst,va_arg(ap, unsigned long long));
        else if (ft_strcmp(lst->size, "hh") == 0)
            hh_o(lst,va_arg(ap, unsigned long long));
        else if (lst->size[0] == 'h')
            h_o(lst,va_arg(ap, unsigned long long));
        else if (ft_strcmp(lst->size, "ll") == 0)
            ll_o(lst, va_arg(ap, unsigned long long));
        else if (lst->size[0] == 'l')
            l_o(lst, va_arg(ap, unsigned long long));
    }
    if (lst->type == 'f')
    {
        if (lst->size == 0)
            default_float(lst,va_arg(ap, double), &s);
        else if (lst->size[0] == 'l' || lst->size[0] == 'L')
            long_float(lst,va_arg(ap, long double), &s);
    }
}

int     help_ft_printf(t_printf *lst, const char *string, va_list ap)
{
    int i;
    int stop;
    int freed;
    int percent;

    i = 0;
    while((!(string[i] == '%' && string[i + 1] != '%')) && string[i] != '\0')
    {
        if (string[i] == '%')
        {
            percent = 0;
            while(string[i] == '%')
            {
                percent++;
                i++;
            }
            if (percent % 2 == 0)
            {
                percent /= 2;
                print_n_times(percent, '%', lst);
            }
            else
            {
                percent = (percent - 1)/2; 
                print_n_times(percent, '%', lst);
                i--;
                break ;
            }
        }
         if (string[i])
         {
        ft_putchar(string[i]);
        i++;
            lst->symbs++;
         }
    }
    while(string[i])
    {
        stop = parse_type((char *)string, lst, i);
        zeroing_args(&lst);
        parse_flags((char *)string, lst, i, stop);
        parse_width((char *)string, lst, i, stop);
        parse_precision((char *)string, lst, i, stop);
        freed = parse_size((char*)string, lst, i, stop);
        if (stop != 0)
            i = parse_type((char *)string, lst, i);
        needed_to_print(lst, ap, (char *)string);
        if (string[i] == '%' && string[i + 1] != '%' && stop == 0)
        {
            percent = 0;
            parse_width((char *)string, lst, i, ft_strlen((char *)string));
            parse_flags((char *)string, lst, i, ft_strlen((char *)string));
            while (string[i])
            {
                if (string[i] == '%')
                    percent++;
                i++;
            }
            if (percent % 2 == 0)
                percent /= 2;
                
            else
                percent = (percent - 1)/2;
            if (lst->minus != '-')
            {
                print_n_times(lst->width - percent, ' ', lst);
                print_n_times(percent, '%', lst);
            }
            else
            {
                print_n_times(percent, '%', lst);
                print_n_times(lst->width - percent, ' ', lst);
            }
        }
        while((!(string[i] == '%' && string[i + 1] != '%')) && string[i] != '\0')
        {
            if (string[i] == '%')
        {
            percent = 0;
            while(string[i] == '%')
            {
                percent++;
                i++;
            }
            if (percent % 2 == 0)
            {
                percent /= 2;
                print_n_times(percent, '%', lst);
            }
            else
            {
                percent = (percent - 1)/2; 
                print_n_times(percent, '%', lst);
                i--;
                break ;
            }
        }
                if (string[i])
                {
                 ft_putchar(string[i]);
                    i++;
                 lst->symbs++;
                }
        }
    stop == 0 && string[i] == '%' ? i++ : 0;
    }
    if (freed == 1)
        free(lst->size);
    return (0);
}

int     ft_printf(const char *format, ...)
{
    t_printf    *lst;
    va_list     ap;
    int         typed;

    lst = (t_printf *)malloc(sizeof(t_printf));
    lst->symbs = 0;
    va_start(ap, format);
    help_ft_printf(lst, format, ap);
    typed = lst->symbs;
    free(lst);
    va_end(ap);
    return(typed);
}