/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <mbeahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 18:52:56 by mbeahan           #+#    #+#             */
/*   Updated: 2019/03/29 21:56:41 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

// int     ft_printf_test(const char *format, ...)
// {
//     va_list ap;
//     va_start(ap, format);

//     if(!strcmp(format, "%d"))
//     {
//         int x = va_arg (ap, int);
// 	printf ("You passed decimal object with value %d\n", x);
//     }
//     if(!strcmp(format, "%s"))
//     {
//          char *s = va_arg(ap, char *);
//     printf ("You passed decimal object with value %s\n", s);
//     }
//     va_end (ap);
//     return(0);

int     ft_parse(char *string)
{
    int i;
    t_printf *sooqa;

    i = 0;
    while(string[i]!= '%')
    {
        ft_puchar(string[i]);
        i++;
    }
    while(string[i])
    {
        if (string[i] == "%")
        {
            i++;
            if (string[i] == '+')
                sooqa->plus = '+';
            if (string[i] == '-')
                sooqa->minus = '-';
            if (string[i] == '0')
                sooqa->zero = '0';
            if (string[i] == ' ')
                sooqa->space = ' ';
            if (string[i] == '#')
                sooqa->oktotorp = '#';
        }
        i++;
    }



}
int     ft_printf(const char *format, ...)
{
    int i;
    i = 0;
    va_list ap;
    va_start(ap,format);
    return(0);
}
int main()
{
    printf("%+-----+d", 123);
    return(0);
} 