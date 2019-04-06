/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alexandr <Alexandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 18:52:56 by mbeahan           #+#    #+#             */
/*   Updated: 2019/04/06 11:13:50 by Alexandr         ###   ########.fr       */
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
    (*list)->precision = -1;
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
    char *prec;
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
        if (check == 1 && string[i] == '.' && string[i + 1] > 47 && string[i + 1] < 58)
        {
            i += 1;
            tmp = i;
            len = 0;
            while (string[i] > 47 && string[i] < 58)
            {
                len++;
                i++;
            }
            break ;
        }
        i++;
    }
    if (len > 1)
    {
        prec = (char *)malloc(sizeof(char) * len);
        i = 0;
        while (i < len && string[tmp])
        {
            prec[i] = string[tmp];
            i++;
            tmp++;
        }
        i = ft_atoi(prec);
        list->precision = i;
        free(prec);
    }
    if (len == 1)
        list->precision = string[tmp] - '0';
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
        if (check == 1 && (string[i] > 47 && string[i] < 58))
        {
            tmp = i;
            while(string[i] > 47 && string[i] < 58)
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
    if (ft_atoi(width))
        list->width = ft_atoi(width);
    free(width);
}

void     ft_print(char *string, int start)
{
    while (string[start] && (!(string[start] == '%' && string[start + 1] != '%')))
    {
        ft_putchar(string[start]);
        start++;
    }
}

void    ft_print_char(t_printf *list, int c)
{
    int i;

    i = 0;
    if (list->width && list->minus)
    {
        write(1, &c, 1);
        while (i < list->width -1)
        {
            ft_putchar(' ');
            i++;
        }
    }
    if (list->width && !list->minus)
    {
        while (i < list->width -1)
        {
            ft_putchar(' ');
            i++;
        }
        write(1, &c, 1);
    }
    if (!list->width)
        write(1, &c, 1);
}

void    ft_print_string(t_printf *list, char *string)
{
    int i;
    char *output;
    
    if (list->precision < ft_strlen(string))
    {
        output = (char *)malloc(sizeof(char) * list->precision);
        i = 0;
        while (string[i] && i < list->precision)
        {
            output[i] = string[i];
            i++;
        }
    }
    if (!list->precision)
        output = ft_strdup(string);
    if ((list->width > ft_strlen(output)) && list->minus)
    {
        i = ft_strlen(output);
        ft_putstr(output);
        while (i < list->width)
        {
            ft_putchar(' ');
            i++;
        }
    }
    if (!list->minus && list->width && (list->width > ft_strlen(output)))
    {
        i = list->width - ft_strlen(output);
        while(i > 0)
        {
            ft_putchar(' ');
            i--;
        }
        ft_putstr(output);
    }
    if (!list->width || list->width < ft_strlen(output))
        ft_putstr(output);
}

void     ft_print_address(t_printf *list, void *address)
{
    unsigned long long int tmp;
    unsigned long long int new;
    int *array;
    int count;
    int i;

    i = 1;
    new = (unsigned long long int)address;
    tmp = new;
    count = 0;
    while(tmp > 16)
    {
        tmp = tmp / 16;
        count++;
    }
    array = (int *)malloc(sizeof(unsigned long long int) * (count + 1));
    ft_putstr("0x");
    count = 0;
    while(new > 16)
    {
        array[count] = new % 16;
        new = new / 16;
        count++;
    }
    array[count] = new;
    while(count != 0 && list->width < i)
    {
        if (array[count] >= 10)
        {
            array[count] == 10 ? ft_putchar('a') : 0;
            array[count] == 11 ? ft_putchar('b') : 0;
            array[count] == 12 ? ft_putchar('c') : 0;
            array[count] == 13 ? ft_putchar('d') : 0;
            array[count] == 14 ? ft_putchar('e') : 0;
            array[count] == 15 ? ft_putchar('f') : 0;
        }
        else
            ft_putnbr(array[count]);
        count--;
        i++;
    }
    ft_putnbr(array[0]);
    free(array);
}

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
        ft_print_address(sooqa, address);
        ft_print((char *)format, i);
        zeroing_args(&sooqa);
    }
    return(0);
}

int main()
{
    int b = 5;
    int *a = &b;
    printf("%10.5s\n", "Hello World");
   ft_printf("%10.5s\n", "Hello world");
   return(0);
} 
