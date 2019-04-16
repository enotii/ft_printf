/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <mbeahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 20:57:24 by mbeahan           #+#    #+#             */
/*   Updated: 2019/04/16 20:59:12 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    get_string_addres(t_printf *list, int *array, int count)
{
    char *address;
    int len;
    int i;

    i = 2;
    len = count;
    address = (char *)malloc(sizeof(char) * (len + 3));
    address[0] = '0';
    address[1] = 'x';
    while (len >= 0)
    {
        if (array[len] >= 10)
         {
             array[len] == 10 ? address[i] = 'a' : 0;
             array[len] == 11 ? address[i] = 'b' : 0;
             array[len] == 12 ? address[i] = 'c' : 0;
             array[len] == 13 ? address[i] = 'd' : 0;
             array[len] == 14 ? address[i] = 'e' : 0;
             array[len] == 15 ? address[i] = 'f' : 0;
         }
         else
            address[i] = array[len] + '0';
        i++;
        len--;
    }
    ft_print_string(list, address);
    free(address);
}

void     parse_address(t_printf *list, void *address)
{
    unsigned long long int tmp;
    unsigned long long int new;
    int *array;
    int count;
    int i;

    i = 0;
    new = (unsigned long long int)address;
    tmp = new;
    count = 0;
    while(tmp > 16)
    {
        tmp = tmp / 16;
        count++;
    }
    array = (int *)malloc(sizeof(unsigned long long int) * (count + 1));
    while(new > 16)
    {
        array[i] = new % 16;
        new = new / 16;
        i++;
    }
    array[i] = new;
    get_string_addres(list, array, count);
    free(array);
}