/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string_char.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <mbeahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 20:54:36 by mbeahan           #+#    #+#             */
<<<<<<< Updated upstream
/*   Updated: 2019/04/27 14:18:09 by mbeahan          ###   ########.fr       */
=======
/*   Updated: 2019/05/07 16:43:16 by mbeahan          ###   ########.fr       */
>>>>>>> Stashed changes
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
<<<<<<< Updated upstream
    
=======
    int flag;

    flag = 0;
    if (string == NULL)
    {
        string = ft_strdup("(null)");
        flag = 1;
    }
>>>>>>> Stashed changes
    if (list->width == 0 && list->precision == -1)
        ft_putstr(string);
    if (list->width != 0 && list->precision != -1)
    {
        if (list->width == list->precision)
        {
            i = list->width - ft_strlen(string);
            if (i >= 0)
            {
                if (list->minus == 0)
                {
                    while (i)
                    {
                        ft_putchar(' ');
                        i--;
                    }
                    ft_putstr(string);
                }
                if (list->minus != 0)
                {
                    ft_putstr(string);
                    while (i)
                    {
                        ft_putchar(' ');
                        i--;
                    }
                }
            }
            if (i < 0)
            {
                i = list->precision;
                while (i)
                {
                    ft_putchar(*string);
                    string++;
                    i--;
                }
            }
        }
         if ((list->width > list->precision) && list->minus == 0)
        {
<<<<<<< Updated upstream
            i = list->width - list->precision;
=======
            if (list->precision >= ft_strlen(string))
                i = list->width - ft_strlen(string);
            else
                i = list->width - list->precision;
>>>>>>> Stashed changes
            while (i)
            {
                ft_putchar(' ');
                i--;
            }
<<<<<<< Updated upstream
            ft_putstr(string);
        }
        if ((list->width > list->precision) && list->minus != 0)
        {
            ft_putstr(string);
            i = list->width - list->precision;
=======
            if (list->precision >= ft_strlen(string))
            {
                while (i < ft_strlen(string))
                {
                    ft_putchar(string[i]);
                    i++;
                }
            }
            else
            {
                while (i < list->precision)
                {
                    ft_putchar(string[i]);
                    i++;
                }
            }
        }
        if ((list->width > list->precision) && list->minus != 0)
        {
            i = 0;
            if (list->precision >= ft_strlen(string))
                ft_putstr(string);
            else
            {
                while (i < list->precision)
                {
                    ft_putchar(string[i]);
                    i++;
                }
            }
            if (list->precision >= ft_strlen(string))
                i = list->width - ft_strlen(string);
            else
                i = list->width - list->precision;
>>>>>>> Stashed changes
            while (i)
            {
                ft_putchar(' ');
                i--;
            }
        }
<<<<<<< Updated upstream
        if (list->precision > list->width)
        {
            if (list->precision > ft_strlen(string))
                ft_putstr(string);
            if (list->precision < ft_strlen(string))
            {
                i = list->precision;
                while (i)
                {
                    ft_putchar(*string);
                    string += 1;
                    i--;
=======
        if (list->precision > list->width && list->minus == 0)
        {
            if (list->precision >= ft_strlen(string))
                i = list->width - ft_strlen(string);
            if (list->precision < ft_strlen(string))
                i = list->precision;
            if (list->width < ft_strlen(string))
                i = 0;
            while (i)
            {
                ft_putchar(' ');
                i--;
            }
            if (list->precision >= ft_strlen(string))
                ft_putstr(string);
            else
            {
                while(i < list->precision)
                {
                    ft_putchar(string[i]);
                    i++;
>>>>>>> Stashed changes
                }
            }
        }
    }
    if (list->precision != -1 && list->width == 0)
    {
        if (list->precision >= ft_strlen(string))
            ft_putstr(string);
        if (list->precision < ft_strlen(string))
        {
            i = list->precision;
            while (i)
            {
                ft_putchar(*string);
                string++;
                i--;
            }
        }
    }
    if (list->width != 0 && list->precision == -1)
    {
        if (list->width > ft_strlen(string))
        {
            i = list->width - ft_strlen(string);
            if (list->minus != 0)
            {
                ft_putstr(string);
                while(i)
                {
                    ft_putchar(' ');
                    i--;
                }
            }
            if (list->minus == 0)
            {
                while(i)
                {
                    ft_putchar(' ');
                    i--;
                }
                ft_putstr(string);
            }
        }
        if (list->width <= ft_strlen(string))
            ft_putstr(string);
    }
<<<<<<< Updated upstream
=======
    if (flag == 1)
        free(string);
>>>>>>> Stashed changes
}