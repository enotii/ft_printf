/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caking <caking@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 20:47:57 by mbeahan           #+#    #+#             */
/*   Updated: 2019/06/27 19:58:28 by caking           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void print_unsigned(char *string, t_printf *list)
{
    int i;
    int len;

    len = ft_strlen(string);
    if (list->minus && list->zero)
        list->zero = 0;
    if (list->width != 0 && list->precision != -1)
    {
        if (list->width == list->precision)
        {
            if (list->width < ft_strlen(string))
                i = 0;
            else
                i = list->width - ft_strlen(string);
            print_n_times(i, '0', list);
            putstr_symbs(string, list);
        }
        if (list->width > list->precision)
        {
            if (list->minus)
            {
                i = list->precision - len;
                print_n_times(i, '0', list);
                putstr_symbs(string, list);
                i = list->width - list->precision;
                print_n_times(i, ' ', list);
            }
            else
            {
                if (list->precision >= ft_strlen(string))
                    i = list->width - list->precision;
                else
                    i = list->width - ft_strlen(string);
                print_n_times(i, ' ', list);
                if (list->precision >= ft_strlen(string))
                    i = list->precision - ft_strlen(string);
                else
                    i = 0;
                print_n_times(i, '0', list);
                putstr_symbs(string, list);
            }
        }
        if (list->precision > list->width)
        {
            if (list->precision >= len)
                i = list->precision - len;
            if (list->precision < len)
                i = 0;
            print_n_times(i, '0', list);
            putstr_symbs(string, list);
        }
    }
    if (list->precision != -1 && list->width == 0)
    {
        if (list->precision <= len)
            putstr_symbs(string, list);
        if(list->precision > len)
        {
            i = list->precision - len;
            print_n_times(i, '0', list);
        }
    }
    if (list->width != 0 && list->precision == -1)
    {
        if (list->width <= len)
            putstr_symbs(string, list);
        if(list->width > len)
        {
            if (list->minus == 0 && list->zero == 0)
            {
                i = list->width - len;
                print_n_times(i, ' ', list);
                putstr_symbs(string, list);
            }
            if (list->minus)
            {
                putstr_symbs(string, list);
                i = list->width - len;
                print_n_times(i, ' ', list);
            }
            if (list->zero)
            {
                i = list->width - len;
                print_n_times(i, '0', list);
                putstr_symbs(string, list);
            }
        }
    }
    if (list->width == 0 && list->precision == 0)
        putstr_symbs(string, list);
}

void    unsigned_hh(t_printf *list, unsigned long long u)
{
    int count;
    char *string;
    unsigned char new_u;
    unsigned char tmp_u;
    int i;

    new_u = (unsigned char)u;
    tmp_u = new_u;
    count = 0;
    i = 0;
    if (tmp_u >= 10)
    {
        while (tmp_u >= 10)
        {
            tmp_u = tmp_u / 10;
            count++;
        }
        string = (char *)malloc(sizeof(char) * count + 1);
        while (new_u >= 10)
        {
            string[i] = new_u % 10 + '0';
            new_u = new_u / 10;
            i++;
        }
        string[i] = new_u + '0';
        string[count + 1] = '\0';
    }
    else
    {
        string = (char *)malloc(sizeof(char) * 2);
        string[i] = new_u + '0';
        string[i + 1] = '\0';
    }
    print_unsigned(reverse_string(string), list);
    free(string);
}

void    unsigned_h(t_printf *list, unsigned long long u)
{
    int count;
    char *string;
    unsigned short new_u;
    unsigned short tmp_u;
    int i;

    new_u = (unsigned short)u;
    tmp_u = new_u;
    count = 0;
    i = 0;
    if (tmp_u >= 10)
    {
        while (tmp_u >= 10)
        {
            tmp_u = tmp_u / 10;
            count++;
        }
        string = (char *)malloc(sizeof(char) * count + 1);
        while (new_u >= 10)
        {
            string[i] = new_u % 10 + '0';
            new_u = new_u / 10;
            i++;
        }
        string[i] = new_u + '0';
        string[count + 1] = '\0';
    }
    else
    {
        string = (char *)malloc(sizeof(char) * 2);
        string[i] = new_u + '0';
        string[i + 1] = '\0';
    }
    print_unsigned(reverse_string(string), list);
    free(string);
}

void    unsigned_ll(t_printf *list, unsigned long long u)
{
    int count;
    char *string;
    unsigned long long new_u;
    unsigned long long tmp_u;
    int i;

    new_u = u;
    tmp_u = new_u;
    count = 0;
    i = 0;
    if (tmp_u >= 10)
    {
        while (tmp_u >= 10)
        {
            tmp_u = tmp_u / 10;
            count++;
        }
        string = (char *)malloc(sizeof(char) * count + 1);
        while (new_u >= 10)
        {
            string[i] = new_u % 10 + '0';
            new_u = new_u / 10;
            i++;
        }
        string[i] = new_u + '0';
        string[count + 1] = '\0';
    }
    else
    {
        string = (char *)malloc(sizeof(char) * 2);
        string[i] = new_u + '0';
        string[i + 1] = '\0';
    }
    print_unsigned(reverse_string(string), list);
    free(string);
}

void    unsigned_l(t_printf *list, unsigned long long u)
{
    int count;
    char *string;
    unsigned long new_u;
    unsigned long tmp_u;
    int i;

    new_u = (unsigned long)u;
    tmp_u = new_u;
    count = 0;
    i = 0;
    if (tmp_u >= 10)
    {
        while (tmp_u >= 10)
        {
            tmp_u = tmp_u / 10;
            count++;
        }
        string = (char *)malloc(sizeof(char) * count + 1);
        while (new_u >= 10)
        {
            string[i] = new_u % 10 + '0';
            new_u = new_u / 10;
            i++;
        }
        string[i] = new_u + '0';
        string[count + 1] = '\0';
    }
    else
    {
        string = (char *)malloc(sizeof(char) * 2);
        string[i] = new_u + '0';
        string[i + 1] = '\0';
    }
    print_unsigned(reverse_string(string), list);
    free(string);
}