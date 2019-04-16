/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string_char.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <mbeahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 20:54:36 by mbeahan           #+#    #+#             */
/*   Updated: 2019/04/16 20:56:44 by mbeahan          ###   ########.fr       */
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
    char *output;
    
    if (list->precision >= 0 && list->precision < ft_strlen(string))
    {
        output = (char *)malloc(sizeof(char) * list->precision);
        i = 0;
        while (string[i] && i < list->precision)
        {
            output[i] = string[i];
            i++;
        }
    }
    if (list->precision < 0)
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