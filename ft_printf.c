/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gachibass228 <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 18:52:56 by mbeahan           #+#    #+#             */
/*   Updated: 2019/04/05 20:25:19 by gachibass22      ###   ########.fr       */
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
    write(1, &c, 1);
}

void    ft_print_string(t_printf *list, char *string)
{
    int i;

    i = 0;
    if (list->precision)
    {
        while (i < list->precision)
        {
            ft_putchar(string[i]);
            i++;
        }
    }
    else
        ft_putstr(string);
}

void     ft_print_address(t_printf *list, void *address)
{
    char *a;
	char *ret;
    int new;

	new = (int)address;
	ret = ft_strdup("0x");
	ft_strcat(ret, ft_itoa_base((unsigned long int)address, 16));
    ft_putstr(ret);
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
    //int a = 98/16;
  //  printf("%d\n",a);
   ft_printf("Your p is : %p", 1234);
   return(0);
} 
