/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <mbeahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 20:47:57 by mbeahan           #+#    #+#             */
/*   Updated: 2019/04/16 20:51:21 by mbeahan          ###   ########.fr       */
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
    if (list->width && list->precision)
    {
        if (list->width == list->precision)
        {
            i = list->width - len;
            while (i)
            {
                ft_putchar('0');
                i--;
            }
            ft_putstr(string);
        }
        if (list->width > list->precision)
        {
            if (list->minus)
            {
                i = list->precision - len;
                while(i)
                {
                    ft_putchar('0');
                    i--;
                }
                ft_putstr(string);
                i = list->width - list->precision;
                while (i)
                {
                    ft_putchar(' ');
                    i--;
                }
            }
            else
            {
                i = list->width - list->precision;
                while (i)
                {
                    ft_putchar(' ');
                    i--;
                }
                i = list->precision - len;
                while(i)
                {
                    ft_putchar('0');
                    i--;
                }
                ft_putstr(string);
            }
        }
        if (list->precision > list->width)
        {
            i = list->precision - len;
            while (i)
            {
                ft_putchar('0');
                i--;
            }
            ft_putstr(string);
        }
    }
    if (list->precision && (!(list->width)))
    {
        if (list->precision <= len)
            ft_putstr(string);
        if(list->precision > len)
        {
            i = list->precision - len;
            while (i)
            {
                ft_putchar('0');
                i--;
            }
        }
    }
    if (list->width && (!(list->precision)))
    {
        if (list->width <= len)
            ft_putstr(string);
        if(list->width > len)
        {
            if (list->minus == 0 && list->zero == 0)
            {
                i = list->width - len;
                while (i)
                {
                    ft_putchar(' ');
                    i--;
                }
                ft_putstr(string);
            }
            if (list->minus)
            {
                ft_putstr(string);
                i = list->width - len;
                while (i)
                {
                    ft_putchar(' ');
                    i--;
                }
            }
            if (list->zero)
            {
                i = list->width - len;
                while (i)
                {
                    ft_putchar('0');
                    i--;
                }
                ft_putstr(string);
            }
        }
    }
    if (list->width == 0 && list->precision == 0)
        ft_putstr(string);
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
        string = (char *)malloc(sizeof(char) * 1);
        string[i] = new_u + '0';
    }
    reverse_string(string, list);
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
        string = (char *)malloc(sizeof(char) * 1);
        string[i] = new_u + '0';
    }
    reverse_string(string, list);
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
        string = (char *)malloc(sizeof(char) * 1);
        string[i] = new_u + '0';
    }
    reverse_string(string, list);
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
        string = (char *)malloc(sizeof(char) * 1);
        string[i] = new_u + '0';
    }
    reverse_string(string, list);
    free(string);
}