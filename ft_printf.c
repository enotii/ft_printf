/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caking <caking@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 20:30:19 by caking            #+#    #+#             */
/*   Updated: 2019/04/17 23:14:36 by caking           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	t_printf	*sooqa;
    va_list     ap;
    int         i;

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
	if (sooqa->type == 'd')
    {
        va_start(ap, format);
        long long int chislo = va_arg(ap, int);
        // if (ft_strcmp(sooqa->size, "hh") == 0)
        // unsigned_hh(sooqa,chislo);
        ft_print_int(sooqa, chislo);
        ft_print((char *)format, i);
        zeroing_args(&sooqa);
    }
    return(0);
}

int main()
{
    int a = 123;
    //int *b = &a;
    printf("%d\n", a);
    ft_printf("fdsf%+d", a);
    return(0);
}