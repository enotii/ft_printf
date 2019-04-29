/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gachibass228 <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 21:21:53 by mbeahan           #+#    #+#             */
/*   Updated: 2019/04/29 23:49:51 by gachibass22      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     ft_printf(const char *format, ...)
{
    int i;
    t_printf *sooqa;
    va_list ap;

    i = 0;
    sooqa = (t_printf *)malloc(sizeof(t_printf));
    ft_print((char *)format, i);
    zeroing_args(&sooqa);
    parse_flags((char *)format, sooqa);
    parse_width((char *)format, sooqa);
    parse_precision((char *)format, sooqa);
    parse_size((char*)format, sooqa);
    i = parse_type((char *)format, sooqa);
    if (sooqa->type == 'c')
    {
        va_start(ap,format);
        int c = va_arg(ap, int);
        ft_print_char(sooqa, c);
        ft_print((char *)format, i);
        zeroing_args(&sooqa);
    }
    if (sooqa->type == 's')
    {
        va_start(ap,format);
        char *string = va_arg(ap, char *);
        ft_print_string(sooqa, string);
        ft_print((char *)format, i);
        zeroing_args(&sooqa);
    }
    if (sooqa->type == 'p')
    {
        va_start(ap, format);
        void *address = va_arg(ap, void *);
        parse_address(sooqa, address);
        ft_print((char *)format, i);
        zeroing_args(&sooqa);
    }
    if (sooqa->type == 'u')
    {
        va_start(ap, format);
        unsigned long long u = va_arg(ap, unsigned long long);
        if (ft_strcmp(sooqa->size, "hh") == 0)
            unsigned_hh(sooqa,u);
        else if (sooqa->size[0] == 'h')
            unsigned_h(sooqa,u);
        else if (ft_strcmp(sooqa->size, "ll") == 0)
            unsigned_ll(sooqa, u);
        else if (sooqa->size[0] == 'l')
            unsigned_l(sooqa, u);
    }
    if (sooqa->type == 'd' || sooqa->type == 'i')
    {
        va_start(ap,format);
        long long int d = va_arg(ap, long long int);
        if (ft_strcmp(sooqa->size, "hh") == 0)
            hh_int(sooqa,d);
        else if (sooqa->size[0] == 'h')
            h_int(sooqa,d);
        else if (ft_strcmp(sooqa->size, "ll") == 0)
            ll_int(sooqa, d);
        else if (sooqa->size[0] == 'l')
            l_int(sooqa, d);
    }
    if (sooqa->type == 'x' || sooqa->type == 'X')
    {
        va_start(ap,format);
        unsigned long long x = va_arg(ap, unsigned long long);
        if (sooqa->size == 0)
            default_x(sooqa,x);
        else if (ft_strcmp(sooqa->size, "hh") == 0)
            hh_x(sooqa,x);
        else if (sooqa->size[0] == 'h')
            h_x(sooqa,x);
        else if (ft_strcmp(sooqa->size, "ll") == 0)
            ll_x(sooqa, x);
        else if (sooqa->size[0] == 'l')
            l_x(sooqa, x);
    }
    if (sooqa->type == 'o')
    {
        va_start(ap,format);
        unsigned long long x = va_arg(ap, unsigned long long);
        if (sooqa->size == 0)
            default_o(sooqa,x);
        else if (ft_strcmp(sooqa->size, "hh") == 0)
            hh_o(sooqa,x);
        else if (sooqa->size[0] == 'h')
            h_o(sooqa,x);
        else if (ft_strcmp(sooqa->size, "ll") == 0)
            ll_o(sooqa, x);
        else if (sooqa->size[0] == 'l')
            l_o(sooqa, x);
    }
    if (sooqa->type == 'f')
    {
        va_start(ap,format);
        if (sooqa->size == 0)
        {
            double f = va_arg(ap, double);
            defaut_f(sooqa,f);
        }
        else if (ft_strcmp(sooqa->size, "l") == 0)
        {
            double f = va_arg(ap, double);
            l_float(sooqa,f);
        }
        else if (ft_strcmp(sooqa->size, "L") == 0)
        {
            long double f = va_arg(ap, long double);
            L_float(sooqa,f);
        }
    }
    return(0);
}

int main()
{
  //  printf("%f\n", 1.223543);
   // ft_printf("%f\n", 1.223543);
float f = 8.0/3.0;
double lf = 8.0/3.0;
long double Lf = 8.0/3.0;
 ft_printf("%f\n", f);
printf("value       float: %0.60f\n", -f);
printf("value      double: %0.60lf\n", -lf);
printf("value long double: %0.60Lf\n", -Lf); //666666666666666518636930049979127943515777587890625
    return(0);
}