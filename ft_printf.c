/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caking <caking@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 21:21:53 by mbeahan           #+#    #+#             */
/*   Updated: 2019/05/16 16:49:33 by caking           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    needed_to_print(t_printf *lst, va_list ap,char *s)
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
            default_int(lst,va_arg(ap, int));
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
        if (lst->type == 'f')
    {
        if (!(lst->size))
            default_float(lst,va_arg(ap, double), &s);
        // else if (ft_strcmp(lst->size, "l") == 0)
        //     l_float(lst,va_arg(ap, double));
        // else if (ft_strcmp(lst->size, "L") == 0)
        //     L_float(lst,va_arg(ap, long double));
    }
}

int     help_ft_printf(t_printf *lst, const char *string, va_list ap)
{
    int i;
    i = 0;
    int stop;

    while((!(string[i] == '%' && string[i + 1] != '%')) && string[i] != '\0')
    {
        ft_putchar(string[i]);
        i++;
    }
    while(string[i])
    {
        stop = parse_type((char *)string, lst, i);
        zeroing_args(&lst);
        parse_flags((char *)string, lst, i, stop);
        parse_width((char *)string, lst, i, stop);
        parse_precision((char *)string, lst, i, stop);
        parse_size((char*)string, lst, i, stop);
        i = parse_type((char *)string, lst, i);
        needed_to_print(lst, ap, (char *)string);
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
  //  printf("%f\n", 1.223543);
   // ft_printf("%f\n", 1.223543);
double f = 8.0/3.0;
char *str = "this is ft_printf";
double f1 = 234243.123;
double lf = 8.0/3.0;
long double Lf = 8.0/3.0;
ft_printf("%s\t%+f\n", str,f);
printf("value       float: %+f\n", f);
printf("value      double: %0.60lf\n", -lf);
printf("value long double: %0.60Lf\n", -Lf); //666666666666666518636930049979127943515777587890625
    return(0);
}