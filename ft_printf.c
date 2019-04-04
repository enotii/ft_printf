/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gachibass228 <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 18:52:56 by mbeahan           #+#    #+#             */
/*   Updated: 2019/04/04 20:05:34 by gachibass22      ###   ########.fr       */
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

void    parse_size(char *string, t_printf *list)
{
    int check;
    int i;

    i = 0;
    check = 0;
    while (string[i] && check < 2)
    {
        if (string[i] == '%' && string[i + 1] != '%')
        {
            check++;
            i++;
        }
         if (check == 1 && (string[i] == 'h' && string[i + 1] == 'h'))
        {
            list->size = (char *)malloc(sizeof(char) * 2);
            list->size[0] = 'h';
            list->size[1] = 'h';
            break;
        }
         if (check == 1 && (string[i] == 'h' && string[i + 1] != 'h'))
        {
            list->size = (char *)malloc(sizeof(char) * 2);
            list->size[0] = 'h';
            list->size[1] = '\0';
            break;
        }
        if (check == 1 && (string[i] == 'l' && string[i + 1] == 'l'))
        {
            list->size = (char *)malloc(sizeof(char) * 2);
            list->size[0] = 'l';
            list->size[1] = 'l';
            break;
        }
         if (check == 1 && (string[i] == 'l' && string[i + 1] != 'l'))
        {
            list->size = (char *)malloc(sizeof(char) * 2);
            list->size[0] = 'l';
            list->size[1] = '\0';
            break;
        }
         if (check == 1 && (string[i] == 'L' && string[i + 1] == 'f'))
        {
            list->size = (char *)malloc(sizeof(char) * 2);
            list->size[0] = 'L';
            list->size[1] = '\0';
            break;
        }
         i++;
    }
}

int    parse_type(char *string, t_printf *list)
{
    int check;
    int i;

    i = 0;
    check = 0;
    while (string[i] && check < 2)
    {
        if (string[i] == '%' && string[i + 1] != '%')
        {
            check++;
            i++;
        }
         if (check == 1 && (string[i] == 'd'))
        {
            list->type = 'd';
            i++;
            return(i);
        }
        if (check == 1 && (string[i] == 'c'))
        {
            list->type = 'c';
            i++;
            return(i);
        }
        if (check == 1 && (string[i] == 's'))
        {
            list->type = 's';
            i++;
            return(i);
        }
        if (check == 1 && (string[i] == 'p'))
        {
            list->type = 'p';
            i++;
            return(i);
        }
        if (check == 1 && (string[i] == 'f'))
        {
            list->type = 'f';
            i++;
            return(i);
        }
        if (check == 1 && (string[i] == 'i'))
        {
            list->type = 'i';
            i++;
            return(i);
        }
        if (check == 1 && (string[i] == 'o'))
        {
            list->type = 'o';
            i++;
            return(i);
        }
        if (check == 1 && (string[i] == 'u'))
        {
            list->type = 'u';
            i++;
            return(i);
        }
        if (check == 1 && (string[i] == 'x'))
        {
            list->type = 'x';
            i++;
            return(i);
        }
        if (check == 1 && (string[i] == 'X'))
        {
            list->type = 'X';
            i++;
            return(i);
        }
        i++;
    }
    return(0);
}

void    parse_precision(char *string, t_printf *list)
{
    int i;
    int check;
    char *precision;
    int len;
    int tmp;

    i = 0;
    check = 0;
    while (string[i] && check < 2)
    {
        if (string[i] == '%' && string[i + 1] != '%')
        {
            check++;
            i++;
        }
        if (check == 1 && (string[i] == '.' && (string[i + 1] > 47 && string[i + 1] < 58)))
        {
            i++;
            tmp = i;
            len = 0;
            while(string[i] > 47 && string[i] < 58)
            {
                len++;
                i++;
            }
            break ;
        }
        i++;
    }
    if (len >= 0)
    {
        i = 0;
        precision = (char *)malloc(sizeof(char) * len);
        while (i < len)
        {
            precision[i] = string[tmp];
            i++;
            tmp++;
        }
        list->precision = ft_atoi(precision);
        free(precision);
    }
}

void    parse_width(char *string, t_printf *list)
{
    int     i;
    int     len;
    char    *width;
    int     check;
    int     tmp;

    i = 0;
    check = 0;
    len = 0;
    while (string[i] && check < 2)
    {
        if (string[i] == '%' && string[i + 1] != '%')
        {
            i++;
            check++;
        }
        if (check == 1 && (string[i] == '+' || string[i] == '-' || string[i] == '0' || string[i] == ' ' || string[i] == '#'))
            i++;
        if (check == 1 && (string[i] > 48 && string[i] < 58))
        {
            tmp = i;
            while(string[i] > 48 && string[i] < 58)
            {
                i++;
                len++;
            }
             break ;
        }
        if (check == 1 && ((string[i] != '+' && string[i] != '-' && string[i] != '0' && string[i] != ' ' && string[i] != '#') && (!(string[i] > 47 && string[i] < 58))))
             break ;
        i++;
    }
    width = (char *)malloc(sizeof(char) * len);
    i = 0;
    while (i < len)
    {
        width[i] = string[tmp];
        i++;
        tmp++;
    }
    list->width = ft_atoi(width);
    free(width);
}

int    ft_print_and_return(char *string, int start)
{
    while (string[start] && (!(string[start] == '%' && string[start] != '%')))
    {
        ft_putchar(string[start]);
        start++;
    }
    if (string[start + 1])
        return(start + 1);
    return (0);
}

void    ft_parse(char *string)
{
    int count;
    t_printf *sooqa;
    int i;

    i = 0;
    count = 0;
    sooqa = (t_printf *)malloc(sizeof(t_printf));
    ft_print_and_return(string, i);
    zeroing_args(&sooqa);
    parse_flags(string, sooqa);
    parse_width(string, sooqa);
    parse_precision(string, sooqa);
    parse_size(string,sooqa);
    count = parse_type(string,sooqa);
    //count = ft_print_and_return(string, count);
    while(string[count] != '\0')
    {
        ft_putchar(string[count]);
        count++;
    }
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
   ft_printf("ffdf %03.2ddfd%fdfsdf");
   // printf("fdfd%+-dfdsfdf", 20);
    //ft_printf("Your result is %10s=%0*.*f", 123);
    //printf("%10s=%0*.*f);
    return(0);
} 
