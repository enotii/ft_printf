/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_octal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caking <caking@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 18:01:26 by mbeahan           #+#    #+#             */
/*   Updated: 2019/06/27 19:58:21 by caking           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    print_octal(t_printf *lst, char *string)
{
    int len;
    int i;
    char symb;

    symb = ' ';
    if (lst->bar != 0)
        len = ft_strlen(string + 1);
    if (lst->bar == 0)
        len = ft_strlen(string);
    if (lst->minus && lst->zero)
        lst->zero = 0;
    if (lst->precision == -1 && lst->width == 0)
        putstr_symbs(string, lst);
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
                print_n_times(1, '0', lst);
            print_n_times(i, '0', lst);
            if (lst->bar != 0)
                putstr_symbs(string + 1, lst);
            else
                putstr_symbs(string, lst);
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
            print_n_times(i, ' ', lst);
            if (lst->precision >= len)
                i = lst->precision - len;
            else
                i = 0;
            if (lst->bar != 0)
                print_n_times(1, '0', lst);
            print_n_times(i, '0', lst);
            if (lst->bar != 0)
                putstr_symbs(string + 1, lst);
            else
                putstr_symbs(string, lst);
        }
         if (lst->width > lst->precision && lst->minus != 0)
        {
            if (lst->precision >= len)
                i = lst->precision - len;
            else
                i = 0;
            if (lst->bar != 0)
                print_n_times(1, '0', lst);
            print_n_times(i, '0', lst);
            if (lst->bar != 0)
                putstr_symbs(string + 1, lst);
            else
                putstr_symbs(string, lst);
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
            print_n_times(i, ' ', lst);
        }
        if (lst->width == lst->precision)
        {
            if (lst->precision < len)
                putstr_symbs(string, lst);
            if (lst->precision >= len)
            {
                if (lst->bar != 0)
                    print_n_times(1, '0', lst);
                i = lst->precision - len;
                print_n_times(i, '0', lst);
                if (lst->bar != 0)
                    putstr_symbs(string + 1, lst);
                else
                    putstr_symbs(string, lst);
            }
        }
    }
    if (lst->precision == -1 && lst->width != 0)
        {
            if (lst->width < ft_strlen(string))
                putstr_symbs(string, lst);
            if (lst->width >= ft_strlen(string) && lst->minus == 0)
            {
                if (lst->zero)
                {
                    symb = '0';
                    if (lst->bar != 0)
                        print_n_times(1, '0', lst);
                }
                i = lst->width - ft_strlen(string);
                print_n_times(i, symb, lst);
                if (lst->zero != 0 && lst->bar != 0)
                    putstr_symbs(string + 1, lst);
                else
                    putstr_symbs(string, lst);
            }
            if (lst->width >= ft_strlen(string) && lst->minus != 0)
            {
                if (lst->zero != 0 && lst->bar != 0)
                    putstr_symbs(string + 1, lst);
                else
                    putstr_symbs(string, lst);
                i = lst->width - ft_strlen(string);
                print_n_times(i, ' ', lst);
            }
        }
    if (lst->precision != -1 && lst->width == 0)
    {
        if (lst->precision < len)
            putstr_symbs(string, lst);
        if (lst->precision >= len)
        {
            if (lst->bar != 0)
                print_n_times(1, '0', lst);
            i = lst->precision - len;
            print_n_times(i, '0', lst);
            if (lst->bar != 0)
                putstr_symbs(string + 1, lst);
            else
                putstr_symbs(string, lst);
        }
    }
}

void    get_o_string(t_printf *list, int *array, int count)
{
    char *address;
    int len;
    int i;

    len = count;
    if (list->bar != 0)
    {
        address = (char *)malloc(sizeof(char) * (len + 2));
        address[0] = '0';
        i = 1;
    }
    else
    {
        address = (char *)malloc(sizeof(char) * (len + 1));
        i = 0;
    }
    while (len >= 0)
    {
        address[i] = array[len] + '0';
        i++;
        len--;
    }
    address[i] = '\0';
    print_octal(list, address);
    free(address);
}

void     default_o(t_printf *list, unsigned long long x)
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
    while(tmp > 8)
    {
        tmp = tmp / 8;
        count++;
    }
    array = (int *)malloc(sizeof(unsigned long long) * (count + 1));
    while(new > 8)
    {
        array[i] = new % 8;
        new = new / 8;
        i++;
    }
    array[i] = new;
    get_o_string(list, array, count);
    free(array);
}

void     hh_o(t_printf *list, unsigned long long x)
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
    while(tmp > 8)
    {
        tmp = tmp / 8;
        count++;
    }
    array = (int *)malloc(sizeof(unsigned long long) * (count + 1));
    while(new > 8)
    {
        array[i] = new % 8;
        new = new / 8;
        i++;
    }
    array[i] = new;
    get_o_string(list, array, count);
    free(array);
}

void     h_o(t_printf *list, unsigned long long x)
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
    while(tmp > 8)
    {
        tmp = tmp / 8;
        count++;
    }
    array = (int *)malloc(sizeof(unsigned long long) * (count + 1));
    while(new > 8)
    {
        array[i] = new % 8;
        new = new / 8;
        i++;
    }
    array[i] = new;
    get_o_string(list, array, count);
    free(array);
}

void     ll_o(t_printf *list, unsigned long long x)
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
    while(tmp > 8)
    {
        tmp = tmp / 8;
        count++;
    }
    array = (int *)malloc(sizeof(unsigned long long) * (count + 1));
    while(new > 8)
    {
        array[i] = new % 8;
        new = new / 8;
        i++;
    }
    array[i] = new;
    get_x_string(list, array, count);
    free(array);
}

void     l_o(t_printf *list, unsigned long long x)
{
    unsigned long tmp;
    unsigned long new;
    int *array;
    int count;
    int i;

    i = 0;
    new = (unsigned int)x;
    tmp = new;
    count = 0;
    while(tmp > 8)
    {
        tmp = tmp / 8;
        count++;
    }
    array = (int *)malloc(sizeof(unsigned long long) * (count + 1));
    while(new > 8)
    {
        array[i] = new % 8;
        new = new / 8;
        i++;
    }
    array[i] = new;
    get_x_string(list, array, count);
    free(array);
}

