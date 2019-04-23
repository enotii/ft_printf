/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_octal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <mbeahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 18:01:26 by mbeahan           #+#    #+#             */
/*   Updated: 2019/04/23 18:16:59 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
    ft_putstr(address);
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

