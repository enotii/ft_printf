/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <mbeahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 15:06:56 by mbeahan           #+#    #+#             */
/*   Updated: 2019/05/07 16:37:45 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    print_x(t_printf *lst, char *string)
{
    int len;
    int i;
    char symb;
    char up_or_low[3];


    symb = ' ';
    up_or_low[0] = '0';
    up_or_low[1] = lst->type;
    up_or_low[2] = '\0';
    if (lst->bar != 0)
        len = ft_strlen(string + 2);
    if (lst->bar == 0)
        len = ft_strlen(string);
    if (lst->minus && lst->zero)
        lst->zero = 0;
    if (lst->precision == -1 && lst->width == 0)
        ft_putstr(string);
    if (lst->zero != 0)
        symb = '0';
    if (lst->width != 0 && lst->precision != -1)
    {
        if (lst->width < lst->precision)
        {
            if (lst->precision >= len)
                i = lst->precision - len;
            else
                i = 0;
            if (lst->bar != 0)
                ft_putstr(up_or_low);
            while (i)
            {
                ft_putchar('0');
                i--;
            }
            if (lst->bar != 0)
                ft_putstr(string + 2);
            else
                ft_putstr(string);
        }
        if (lst->width > lst->precision && lst->minus == 0)
        {
            if (lst->precision >= len)
            {
                i = lst->width - (ft_strlen(string) + lst->precision - len);
                if ((lst->precision - len + ft_strlen(string)) > lst->width)
                    i = 0;
            }
            if (lst->precision < len)
                i = lst->width - ft_strlen(string);
            if (i < 0)
                i = 0;
            while (i)
            {
                ft_putchar(' ');
                i--;
            }
            if (lst->precision >= len)
                i = lst->precision - len;
            else
                i = 0;
            if (lst->bar != 0)
                ft_putstr(up_or_low);
            while(i)
            {
                ft_putchar('0');
                i--;
            }
            if (lst->bar != 0)
                ft_putstr(string + 2);
            else
                ft_putstr(string);
        }
         if (lst->width > lst->precision && lst->minus != 0)
        {
            if (lst->precision >= len)
                i = lst->precision - len;
            else
                i = 0;
            if (lst->bar != 0)
                ft_putstr(up_or_low);
            while(i)
            {
                ft_putchar('0');
                i--;
            }
            if (lst->bar != 0)
                ft_putstr(string + 2);
            else
                ft_putstr(string);
            if (lst->precision >= len)
            {
                i = lst->width - (ft_strlen(string) + lst->precision - len);
                if ((lst->precision - len + ft_strlen(string)) > lst->width)
                    i = 0;
            }
            if (lst->precision < len)
                i = lst->width - ft_strlen(string);
            if (i < 0)
                i = 0;
            while (i)
            {
                ft_putchar(' ');
                i--;
            }
        }
        if (lst->width == lst->precision)
        {
            if (lst->precision < len)
                ft_putstr(string);
            if (lst->precision >= len)
            {
                if (lst->bar != 0)
                    ft_putstr(up_or_low);
                i = lst->precision - len;
                while (i)
                {
                    ft_putchar('0');
                    i--;
                }
                if (lst->bar != 0)
                    ft_putstr(string + 2);
                else
                    ft_putstr(string);
            }
        }
    }
    if (lst->precision == -1 && lst->width != 0)
        {
            if (lst->width < ft_strlen(string))
                ft_putstr(string);
            if (lst->width >= ft_strlen(string) && lst->minus == 0)
            {
                if (lst->zero)
                {
                    symb = '0';
                    if (lst->bar != 0)
                        ft_putstr(up_or_low);
                }
                i = lst->width - ft_strlen(string);
                while (i)
                {
                    ft_putchar(symb);
                    i--;
                }
                if (lst->zero != 0 && lst->bar != 0)
                    ft_putstr(string + 2);
                else
                    ft_putstr(string);
            }
            if (lst->width >= ft_strlen(string) && lst->minus != 0)
            {
                if (lst->zero != 0 && lst->bar != 0)
                    ft_putstr(string + 2);
                else
                    ft_putstr(string);
                i = lst->width - ft_strlen(string);
                while (i)
                {
                    ft_putchar(' ');
                    i--;
                }
            }
        }
    if (lst->precision != -1 && lst->width == 0)
    {
        if (lst->precision < len)
            ft_putstr(string);
        if (lst->precision >= len)
        {
            if (lst->bar != 0)
                ft_putstr(up_or_low);
            i = lst->precision - len;
            while (i)
            {
                ft_putchar('0');
                i--;
            }
            if (lst->bar != 0)
                ft_putstr(string + 2);
            else
                ft_putstr(string);
        }
    }
}

void    get_x_string(t_printf *list, int *array, int count)
{
    char *address;
    int len;
    int i;

    len = count;
    if (list->bar != 0)
    {
        address = (char *)malloc(sizeof(char) * (len + 4));
        address[0] = '0';
        address[1] = list->type;
        i = 2;
    }
    else
    {
        address = (char *)malloc(sizeof(char) * (len + 1));
        i = 0;
    }
    while (len >= 0)
    {
        if (array[len] >= 10 && list->type == 'x')
         {
             array[len] == 10 ? address[i] = 'a' : 0;
             array[len] == 11 ? address[i] = 'b' : 0;
             array[len] == 12 ? address[i] = 'c' : 0;
             array[len] == 13 ? address[i] = 'd' : 0;
             array[len] == 14 ? address[i] = 'e' : 0;
             array[len] == 15 ? address[i] = 'f' : 0;
         }
         if (array[len] >= 10 && list->type == 'X')
         {
             array[len] == 10 ? address[i] = 'A' : 0;
             array[len] == 11 ? address[i] = 'B' : 0;
             array[len] == 12 ? address[i] = 'C' : 0;
             array[len] == 13 ? address[i] = 'D' : 0;
             array[len] == 14 ? address[i] = 'E' : 0;
             array[len] == 15 ? address[i] = 'F' : 0;
         }
         if (array[len] < 10)
            address[i] = array[len] + '0';
        i++;
        len--;
    }
    address[i] = '\0';
    print_x(list, address);
    free(address);
}

void     default_x(t_printf *list, unsigned long long x)
{
    unsigned int tmp;
    unsigned int new;
    int *array;
    int count;
    int i;

    i = 0;
    new = (unsigned int)x;
    tmp = new;
    count = 0;
    while(tmp > 16)
    {
        tmp = tmp / 16;
        count++;
    }
    array = (int *)malloc(sizeof(unsigned long long) * (count + 1));
    while(new > 16)
    {
        array[i] = new % 16;
        new = new / 16;
        i++;
    }
    array[i] = new;
    get_x_string(list, array, count);
    free(array);
}

void     hh_x(t_printf *list, unsigned long long x)
{
    unsigned char tmp;
    unsigned char new;
    int *array;
    int count;
    int i;

    i = 0;
    new = (unsigned char)x;
    tmp = new;
    count = 0;
    while(tmp > 16)
    {
        tmp = tmp / 16;
        count++;
    }
    array = (int *)malloc(sizeof(unsigned long long) * (count + 1));
    while(new > 16)
    {
        array[i] = new % 16;
        new = new / 16;
        i++;
    }
    array[i] = new;
    get_x_string(list, array, count);
    free(array);
}

void     h_x(t_printf *list, unsigned long long x)
{
    unsigned short tmp;
    unsigned short new;
    int *array;
    int count;
    int i;

    i = 0;
    new = (unsigned short)x;
    tmp = new;
    count = 0;
    while(tmp > 16)
    {
        tmp = tmp / 16;
        count++;
    }
    array = (int *)malloc(sizeof(unsigned long long) * (count + 1));
    while(new > 16)
    {
        array[i] = new % 16;
        new = new / 16;
        i++;
    }
    array[i] = new;
    get_x_string(list, array, count);
    free(array);
}

void     ll_x(t_printf *list, unsigned long long x)
{
    unsigned long long tmp;
    unsigned long long new;
    int *array;
    int count;
    int i;

    i = 0;
    new = (unsigned long long)x;
    tmp = new;
    count = 0;
    while(tmp > 16)
    {
        tmp = tmp / 16;
        count++;
    }
    array = (int *)malloc(sizeof(unsigned long long) * (count + 1));
    while(new > 16)
    {
        array[i] = new % 16;
        new = new / 16;
        i++;
    }
    array[i] = new;
    get_x_string(list, array, count);
    free(array);
}

void     l_x(t_printf *list, unsigned long long x)
{
    unsigned long tmp;
    unsigned long new;
    int *array;
    int count;
    int i;

    i = 0;
    new = (unsigned long)x;
    tmp = new;
    count = 0;
    while(tmp > 16)
    {
        tmp = tmp / 16;
        count++;
    }
    array = (int *)malloc(sizeof(unsigned long long) * (count + 1));
    while(new > 16)
    {
        array[i] = new % 16;
        new = new / 16;
        i++;
    }
    array[i] = new;
    get_x_string(list, array, count);
    free(array);
}