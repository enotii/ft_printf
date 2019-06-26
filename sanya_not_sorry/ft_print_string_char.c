/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string_char.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <mbeahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 20:54:36 by mbeahan           #+#    #+#             */
/*   Updated: 2019/06/26 20:56:29 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_print_char(t_printf *list, int c)
{
    int i;

    i = 0;
    list->symbs++;
    if (list->width && list->minus)
    {
        write(1, &c, 1);
        while (i < list->width -1)
        {
            ft_putchar(' ');
            i++;
            list->symbs++;
        }
    }
    if (list->width && !list->minus)
    {
        while (i < list->width -1)
        {
            ft_putchar(' ');
            i++;
            list->symbs++;
        }
        write(1, &c, 1);
    }
    if (!list->width)
        write(1, &c, 1);
}

void    ft_print_string(t_printf *list, char *string)
{
    int i;
    int flag;

    flag = 0;
    if (string == NULL)
    {
        string = ft_strdup("(null)");
        flag = 1;
    }
    if (list->width == 0 && list->precision == -1)
        putstr_symbs(string, list);
    if (list->width != 0 && list->precision != -1)
    {
        if (list->width == list->precision)
        {
            i = list->width - ft_strlen(string);
            if (i >= 0)
            {
                if (list->minus == 0)
                {
                    print_n_times(i, ' ', list);
                    putstr_symbs(string, list);
                }
                if (list->minus != 0)
                {
                    putstr_symbs(string, list);
                    print_n_times(i, ' ', list);
                }
            }
            if (i < 0)
            {
                i = list->precision;
                print_n_symbs(string, i, list);
            }
        }
         if ((list->width > list->precision) && list->minus == 0)
        {
            if (list->precision >= ft_strlen(string))
                i = list->width - ft_strlen(string);
            else
                i = list->width - list->precision;
            print_n_times(i, ' ', list);
            if (list->precision >= ft_strlen(string))
                putstr_symbs(string, list);
            else
                print_n_symbs(string, list->precision, list);
        }
        if ((list->width > list->precision) && list->minus != 0)
        {
            i = 0;
            if (list->precision >= ft_strlen(string))
                putstr_symbs(string, list);
            else
                print_n_symbs(string, list->precision, list);
            if (list->precision >= ft_strlen(string))
                i = list->width - ft_strlen(string);
            else
                i = list->width - list->precision;
            print_n_times(i, ' ', list);
        }
        if (list->precision > list->width && list->minus == 0)
        {
            if (list->precision >= ft_strlen(string))
                i = list->width - ft_strlen(string);
            if (list->precision < ft_strlen(string))
                i = list->precision;
            if (list->width < ft_strlen(string))
                i = 0;
            print_n_times(i, ' ', list);
            if (list->precision >= ft_strlen(string))
                putstr_symbs(string, list);
            else
                print_n_symbs(string, list->precision, list);
        }
    }
    if (list->precision != -1 && list->width == 0)
    {
        if (list->precision >= ft_strlen(string))
            putstr_symbs(string, list);
        if (list->precision < ft_strlen(string))
        {
            i = list->precision;
            print_n_symbs(string, i, list);
        }
    }
    if (list->width != 0 && list->precision == -1)
    {
        if (list->width > ft_strlen(string))
        {
            i = list->width - ft_strlen(string);
            if (list->minus != 0)
            {
                putstr_symbs(string, list);
                print_n_times(i, ' ', list);
            }
            if (list->minus == 0)
            {
                print_n_times(i, ' ', list);
                putstr_symbs(string, list);
            }
        }
        if (list->width <= ft_strlen(string))
            putstr_symbs(string, list);
    }
    if (flag == 1)
        free(string);
}