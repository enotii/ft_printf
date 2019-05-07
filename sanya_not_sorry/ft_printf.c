/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <mbeahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 21:21:53 by mbeahan           #+#    #+#             */
/*   Updated: 2019/05/07 18:02:36 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    needed_to_print(t_printf *lst, va_list ap)
{
    if (lst->type == 'c')
        ft_print_char(lst, va_arg(ap, int));
    if (lst->type == 's')
        ft_print_string(lst, va_arg(ap, char *));
    if (lst->type == 'p')
        parse_address(lst, va_arg(ap, void *));
    if (lst->type == 'u')
    {
        if (ft_strcmp(lst->size, "hh") == 0)
            unsigned_hh(lst,va_arg(ap, unsigned long long));
        else if (lst->size[0] == 'h')
            unsigned_h(lst,va_arg(ap, unsigned long long));
        else if (ft_strcmp(lst->size, "ll") == 0)
            unsigned_ll(lst, va_arg(ap, unsigned long long));
        else if (lst->size[0] == 'l')
            unsigned_l(lst, va_arg(ap, unsigned long long));
    }
    if (lst->type == 'd' || lst->type == 'i')
    {
        if (lst->size == 0)
            default_int(lst,va_arg(ap, long long int));
        else if(ft_strcmp(lst->size, "hh") == 0)
            hh_int(lst,va_arg(ap, long long int));
        else if (lst->size[0] == 'h')
            h_int(lst,va_arg(ap, long long int));
        else if (ft_strcmp(lst->size, "ll") == 0)
            ll_int(lst, va_arg(ap, long long int));
        else if (lst->size[0] == 'l')
            l_int(lst, va_arg(ap, long long int));
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

}

int     help_ft_printf(t_printf *lst, const char *string, va_list ap)
{
    int i;
    i = 0;

    while(string[i])
    {
        zeroing_args(&lst);
        parse_flags((char *)string, lst, i);
        parse_width((char *)string, lst, i);
        parse_precision((char *)string, lst, i);
        parse_size((char*)string, lst, i);
        i = parse_type((char *)string, lst, i);
        needed_to_print(lst, ap);
        while((!(string[i] == '%' && string[i + 1] != '%')) && string[i] != '\0')
        {
            ft_putchar(string[i]);
            i++;
        }
    }
    return (0);
}

int     ft_printf(const char *format, ...)
{
    t_printf *lst;
    va_list ap;

    lst = (t_printf *)malloc(sizeof(t_printf));
    va_start(ap, format);
    help_ft_printf(lst, format, ap);
    free(lst);
    va_end(ap);
    return(0);
}

int main()
{
    char *dura = "qwerty";
    int b = 5;
    printf("%s <- This is your string, and this is your number -> %d\n", dura, b);
    ft_printf("%s <- This is your string, and this is your number -> %d\n", dura, b);
    return(0);
}
