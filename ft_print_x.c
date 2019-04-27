/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <mbeahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 15:06:56 by mbeahan           #+#    #+#             */
/*   Updated: 2019/04/27 19:44:24 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    print_x(t_printf *lst, char *string)
{
    int i;
    int count_width;
    char symb;

    symb = ' ';
    if (lst-> zero != 0 && lst->minus != 0)
        lst->zero = 0;
    if (lst->precision != -1 && lst->width == 0)
    {
        if ((lst->bar != 0 && ft_strlen(string + 2) >= lst->precision) || (lst->bar == 0 && ft_strlen(string) >= lst->precision))
            ft_putstr(string);
        if ((ft_strlen(string + 2) < lst->precision) && lst->bar != 0)
        {
            i = lst->precision - ft_strlen(string + 2);
            ft_putstr("0x");
            while (i)
            {
                ft_putchar('0');
                i--;
            }
            ft_putstr(string + 2);
        }
        if ((ft_strlen(string) < lst->precision) && lst->bar == 0)
        {
            i = lst->precision - ft_strlen(string);
            while (i)
            {
                ft_putchar('0');
                i--;
            }
            ft_putstr(string);
        }
    }
    if (lst->precision == -1 && lst->width != 0)
    {
        i = lst->width - ft_strlen(string);
        if (ft_strlen(string) >= lst->width)
            ft_putstr(string);
        if ((ft_strlen(string) < lst->width) && (lst->minus == 0 && lst->zero == 0))
        {
            while (i)
            {
                ft_putchar(' ');
                i--;
            }
            ft_putstr(string);
        }
        if ((ft_strlen(string) < lst->width) && lst->minus != 0)
        {
            ft_putstr(string);
            while (i)
            {
                ft_putchar(' ');
                i--;
            }
        }
        if ((ft_strlen(string) < lst->width) && lst->zero != 0)
        {
            if (lst->bar != 0)
                ft_putstr("0x");
            while (i)
            {
                ft_putchar('0');
                i--;
            }
            if (lst->bar == 0)
                ft_putstr(string);
            if (lst->bar != 0)
                ft_putstr(string + 2);
        }
    }
    if (lst->precision != -1 && lst->width != 0)
    {
        if (((lst->bar != 0 && ft_strlen(string + 2) == lst->precision) || (lst->bar == 0 && ft_strlen(string) == lst->precision)) && ft_strlen(string) >= lst->width)
            ft_putstr(string);
        if (((lst->bar != 0 && ft_strlen(string + 2) == lst->precision) || (lst->bar == 0 && ft_strlen(string) == lst->precision)) && ft_strlen(string) < lst->width)
        {
            if (lst->minus == 0)
            {
                i = lst->width - ft_strlen(string);
                while (i)
                {
                    ft_putchar(' ');
                    i--;
                }
                ft_putstr(string);
            }
            if (lst->minus != 0)
            {
                i = lst->width - ft_strlen(string);
                ft_putstr(string);
                while (i)
                {
                    ft_putchar(' ');
                    i--;
                }
            }
        }
        if (((lst->bar != 0 && ft_strlen(string + 2) < lst->precision) || (lst->bar == 0 && ft_strlen(string) < lst->precision)) && ft_strlen(string) >= lst->width)
        {
            if(lst->bar != 0)
            {
                ft_putstr("0x");
                i = lst->precision - ft_strlen(string + 2);
            }
            while (i)
            {
                ft_putchar('0');
                i--;
            }
            if(lst->bar != 0)
                ft_putstr(string + 2);
            else
                ft_putstr(string);
        }
        if (((lst->bar != 0 && ft_strlen(string + 2) < lst->precision) || (lst->bar == 0 && ft_strlen(string) < lst->precision)) && (ft_strlen(string) < lst->width))
        {
            if (lst->bar)
            {
                count_width = lst->width - lst->precision - 2;
                if (count_width < 0)
                    count_width = 0;
            }
            else
                count_width = lst->width - lst->precision;
            if (lst->minus == 0)
            {
                while(count_width)
                {
                    if (lst->zero != 0)
                        symb = '0';
                    ft_putchar(symb);
                    count_width--;
                }
                if (lst->bar != 0)
                {
                    i = lst->precision - ft_strlen(string + 2);
                    ft_putstr("0x");
                }
                else
                    i = lst->precision - ft_strlen(string);
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
           if (lst->minus != 0)
           {
                if (lst->bar != 0)
                {
                    i = lst->precision - ft_strlen(string + 2);
                    ft_putstr("0x");
                }
                else
                    i = lst->precision - ft_strlen(string);
                while(i)
                {
                    ft_putchar('0');
                    i--;
                }
                if (lst->bar != 0)
                    ft_putstr(string + 2);
                else
                    ft_putstr(string);
                while(count_width)
                {
                    ft_putchar(' ');
                    count_width--;
                }
           }
        }
        if ((lst->bar != 0 && lst->precision <= ft_strlen(string + 2)) || (lst->bar == 0 && lst->precision <=  ft_strlen(string)))
           { 
                if (lst->width > ft_strlen(string))
                {
                    i = lst->width - ft_strlen(string);
                    if (lst->minus == 0)
                    {
                        while (i)
                        {
                            ft_putchar(symb);
                            i--;
                        }
                        ft_putstr(string);
                    }
                    else
                    {
                        ft_putstr(string);
                        while (i)
                        {
                            ft_putchar(symb);
                            i--;
                        }
                    }
                }
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