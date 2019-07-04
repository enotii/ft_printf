/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <mbeahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 13:31:45 by mbeahan           #+#    #+#             */
/*   Updated: 2019/07/03 23:02:40 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void print_int(char *string, t_printf *list)
{
    int i;
    int len;

    len = ft_strlen(string);
    if (string[0] == '-')
        len -= 1;
    if (list->minus && list->zero)
        list->zero = 0;
    if (list->space  && (list->plus || list->minus || string[0] == '-'))
        list->space = 0;
    if (list->precision == 0 && len == 1 && string[0] == '0')
        string[0] = '\0';
    if (list->width != 0 && list->precision != -1)
    {
        if (list->width == list->precision)
        {
            if (list->space != 0 && string[0] != '-')
                print_n_times(1, ' ', list);
            if (list->plus || string[0] == '-')
            {
                if (string[0] == '-')
                    print_n_times(1, '-', list);
                else
                    print_n_times(1, '+', list);
            }
            i = list->width - len;
            print_n_times(i, '0', list);
            if (string[0] == '-')
                putstr_symbs(string + 1, list);
            else
                putstr_symbs(string, list);
        }
        if ((list->width > list->precision) && list->precision != -1)
        {
            if (list->space && string[0] != '-')
                print_n_times(1, ' ', list);
            if (list->minus)
            {
                if (list->plus || string[0] == '-')
                {
                    if (string[0] == '-')
                        print_n_times(1, '-', list);
                    else
                        print_n_times(1, '+', list);
                }
                i = list->precision - len;
                print_n_times(i, '0', list);
                if (string[0] != '-')
                    putstr_symbs(string, list);
                else
                    putstr_symbs(string + 1, list);
                if (string[0] == '-' || list->plus != 0 || list->space != 0)
                    i = list->width - list->precision - 1;
                else
                    i = list->width - list->precision;
                print_n_times(i, ' ', list);
            }
            else
            {
                if (string[0] == '-' || list->plus != 0 || list->space != 0)
                    i = list->width - list->precision - 1;
                else
                    i = list->width - list->precision;
                print_n_times(i, ' ', list);
                i = list->precision - len;
                if (list->plus || string[0] == '-')
                {
                    if (string[0] == '-')
                        print_n_times(1, '-', list);
                    else
                        print_n_times(1, '+', list);
                }
                print_n_times(i, '0', list);
                if (string[0] != '-')
                    putstr_symbs(string, list);
                else
                    putstr_symbs(string + 1, list);
            }
        }
        if (list->precision > list->width)
        {
            if (list->plus || string[0] == '-')
            {
                if (string[0] == '-')
                    print_n_times(1, '-', list);
                else
                    print_n_times(1, '+', list);
            }
            if (list->space != 0 && string[0] != '-')
                print_n_times(1, ' ', list);
            i = list->precision - len;
            print_n_times(i, '0', list);
            if (string[0] != '-')
                putstr_symbs(string, list);
            else
                putstr_symbs(string + 1, list);
        }
    }
    if (list->precision != -1 && list->width == 0)
    {
        if (list->plus || string[0] == '-')
        {
            if (string[0] == '-')
                print_n_times(1, '-', list);
            else
                print_n_times(1, '+', list);
        }
        if (list->space != 0 && string[0] != '-')
                print_n_times(1, ' ', list);
        if(list->precision > len)
        {
            i = list->precision - len;
            print_n_times(i, '0', list);
        }
        if (string[0] != '-')
            putstr_symbs(string, list);
        else
            putstr_symbs(string + 1, list);
    }
    if (list->width != 0 && list->precision == -1)
    {
        if (list->width <= len)
        {
            if (list->plus || string[0] == '-')
            {
                if (string[0] == '-')
                    putstr_symbs(string, list);
                else
                {
                    print_n_times(1, '+', list);
                    putstr_symbs(string + 1, list);
                }   
            }
        }
        if(list->width > len)
        {
            if (list->minus == 0 && list->zero == 0)
            {
                if (string[0] == '-' || list->plus != 0 || list->space != 0)
                    i = list->width - len - 1;
                else
                    i = list->width - len;
                print_n_times(i, ' ', list);
                if (list->plus || string[0] == '-')
                {
                    if (string[0] == '-')
                        print_n_times(1, '-', list);
                    else
                        print_n_times(1, '+', list);
                }
                if (string[0] == '-')
                    putstr_symbs(string + 1, list);
                else
                    putstr_symbs(string, list);
            }
            if (list->minus)
            {
                if (list->plus || string[0] == '-')
                {
                    if (string[0] == '-')
                        print_n_times(1, '-', list);
                    else
                        print_n_times(1, '+', list);
                }
                if (string[0] == '-')
                    putstr_symbs(string + 1, list);
                else
                    putstr_symbs(string, list);
                if (string[0] == '-' || list->plus != 0 || list->space != 0)
                    i = list->width - len - 1;
                else
                    i = list->width - len;
                print_n_times(i, ' ', list);
            }
            if (list->zero)
            {
                if (string[0] == '-' || list->plus != 0 || list->space != 0)
                    i = list->width - len - 1;
                else
                    i = list->width - len;
                if (list->plus || string[0] == '-')
                {
                    if (string[0] == '-')
                        print_n_times(1, '-', list);
                    else
                        print_n_times(1, '+', list);
                }
                print_n_times(i, '0', list);
                if (string[0] == '-')
                    putstr_symbs(string + 1, list);
                else
                    putstr_symbs(string, list);
            }
        }
    }
    if (list->width == 0 && list->precision == -1)
    {
        if (list->space)
            print_n_times(1, ' ', list);
        if (list->plus || string[0] == '-')
        {
            if (string[0] == '-')
                print_n_times(1, '-', list);
            else
                print_n_times(1, '+', list);
        }
        if (string[0] == '-')
            putstr_symbs(string + 1, list);
        else
            putstr_symbs(string, list);
    }
}

void    j_int(t_printf *list, long long int d)
{
    int count;
    char *string;
    uintmax_t new_d;
    uintmax_t tmp_d;
    int i;

    new_d = (uintmax_t)d;
    tmp_d = new_d;
    count = 0;
    i = 0;
    if (tmp_d >= 10)
    {
        while (tmp_d >= 10)
        {
            tmp_d = tmp_d / 10;
            count++;
        }
        if (d >= 0)
            string = (char *)malloc(sizeof(char) * count + 1);
        else
        {
            string = (char *)malloc(sizeof(char) * count + 2);
            string[i] = '-';
            i++;
            new_d *= -1;
        }
        while (new_d >= 10)
        {
            string[i] = new_d % 10 + '0';
            new_d = new_d / 10;
            i++;
        }
        string[i] = new_d + '0';
        string[i + 1] = '\0';
    }
    else
    {
        if (d >= 0)
        {
            string = (char *)malloc(sizeof(char) * 2);
            string[0] = new_d + '0';
            string[1] = '\0';
        }
        else
        {
            string = (char *)malloc(sizeof(char) * 3);
            string[0] = '-';
            string[1] = tmp_d + '0';
            string[2] = '\0';
        }
        
    }
    print_int(reverse_string(string), list);
    free(string);
}

void    default_int(t_printf *list, long long int d)
{
    int count;
    char *string;
    long long int new_d;
    long long int tmp_d;
    int i;

    new_d = (int)d;
    if (list->size && list->size[0] == 'z')
        new_d = (long long int)d;
    tmp_d = new_d;
    count = 0;
    i = 0;
    if (tmp_d < 0)
        tmp_d *= -1;
    if (tmp_d >= 10)
    {
        while (tmp_d >= 10)
        {
            tmp_d = tmp_d / 10;
            count++;
        }
        if (new_d >= 0)
            string = (char *)malloc(sizeof(char) * count + 1);
        else
        {
            string = (char *)malloc(sizeof(char) * count + 2);
            string[i] = '-';
            i++;
            new_d *= -1;
        }
        while (new_d >= 10)
        {
            string[i] = new_d % 10 + '0';
            new_d = new_d / 10;
            i++;
        }
        string[i] = new_d + '0';
        string[i + 1] = '\0';
    }
    else
    {
        if (new_d >= 0)
        {
            string = (char *)malloc(sizeof(char) * 2);
            string[0] = new_d + '0';
            string[1] = '\0';
        }
        else
        {
            string = (char *)malloc(sizeof(char) * 3);
            string[0] = '-';
            string[1] = tmp_d + '0';
            string[2] = '\0';
        }
        
    }
    print_int(reverse_string(string), list);
    free(string);
}

void    hh_int(t_printf *list, long long int d)
{
    int count;
    char *string;
    long long int new_d;
    long long int tmp_d;
    int i;

    new_d = (signed char)d;
    tmp_d = new_d;
    count = 0;
    i = 0;
    if (tmp_d < 0)
        tmp_d *= -1;
    if (tmp_d >= 10)
    {
        while (tmp_d >= 10)
        {
            tmp_d = tmp_d / 10;
            count++;
        }
        if (new_d >= 0)
            string = (char *)malloc(sizeof(char) * count + 1);
        else
        {
            string = (char *)malloc(sizeof(char) * count + 2);
            string[i] = '-';
            i++;
            new_d *= -1;
        }
        while (new_d >= 10)
        {
            string[i] = new_d % 10 + '0';
            new_d = new_d / 10;
            i++;
        }
        string[i] = new_d + '0';
        string[i + 1] = '\0';
    }
    else
    {
        if (new_d >= 0)
        {
            string = (char *)malloc(sizeof(char) * 2);
            string[0] = new_d + '0';
            string[1] = '\0';

        }
        else
        {
            string = (char *)malloc(sizeof(char) * 3);
            string[0] = '-';
            string[1] = tmp_d + '0';
            string[2] = '\0';
        }
        
    }
    print_int(reverse_string(string), list);
    free(string);
}

void    h_int(t_printf *list, long long int d)
{
    int count;
    char *string;
    long long int new_d;
    long long int tmp_d;
    int i;

    new_d = (short int)d;
    tmp_d = new_d;
    count = 0;
    i = 0;
    if (tmp_d < 0)
        tmp_d *= -1;
    if (tmp_d >= 10)
    {
        while (tmp_d >= 10)
        {
            tmp_d = tmp_d / 10;
            count++;
        }
        if (new_d >= 0)
            string = (char *)malloc(sizeof(char) * count + 1);
        else
        {
            string = (char *)malloc(sizeof(char) * count + 2);
            string[i] = '-';
            i++;
            new_d *= -1;
        }
        while (new_d >= 10)
        {
            string[i] = new_d % 10 + '0';
            new_d = new_d / 10;
            i++;
        }
        string[i] = new_d + '0';
        string[i + 1] = '\0';
    }
    else
    {
        if (new_d >= 0)
        {
            string = (char *)malloc(sizeof(char) * 2);
            string[0] = new_d + '0';
            string[1] = '\0';
        }
        else
        {
            string = (char *)malloc(sizeof(char) * 3);
            string[0] = '-';
            string[1] = tmp_d + '0';
            string[2] = '\0';
        }
        
    }
    print_int(reverse_string(string), list);
    free(string);
}

void    ll_int(t_printf *list, long long int d)
{
    int count;
    char *string;
    unsigned long long int new_d;
    unsigned long long int tmp_d;
    int i;

    new_d = (unsigned long long int)d;
    tmp_d = new_d;
    count = 0;
    i = 0;
    if (tmp_d >= 10)
    {
        while (tmp_d >= 10)
        {
            tmp_d = tmp_d / 10;
            count++;
        }
        if (d > 0)
            string = (char *)malloc(sizeof(char) * count + 1);
        else
        {
            string = (char *)malloc(sizeof(char) * count + 2);
            string[i] = '-';
            i++;
            new_d *= -1;
        }
        while (new_d >= 10)
        {
            string[i] = new_d % 10 + '0';
            new_d = new_d / 10;
            i++;
        }
        string[i] = new_d + '0';
        string[i + 1] = '\0';
    }
    else
    {
        if (d > 0)
        {
            string = (char *)malloc(sizeof(char) * 2);
            string[0] = new_d + '0';
            string[1] = '\0';
        }
        else
        {
            string = (char *)malloc(sizeof(char) * 3);
            string[0] = '-';
            string[1] = tmp_d + '0';
            string[2] = '\0';
        }
        
    }
    print_int(reverse_string(string), list);
    free(string);
}

void    l_int(t_printf *list, long long int d)
{
    int count;
    char *string;
    long long int new_d;
    long long int tmp_d;
    int i;

    new_d = (long int)d;
    tmp_d = new_d;
    count = 0;
    i = 0;
    if (tmp_d < 0)
        tmp_d *= -1;
    if (tmp_d >= 10)
    {
        while (tmp_d >= 10)
        {
            tmp_d = tmp_d / 10;
            count++;
        }
        if (new_d >= 0)
            string = (char *)malloc(sizeof(char) * count + 1);
        else
        {
            string = (char *)malloc(sizeof(char) * count + 2);
            string[i] = '-';
            i++;
            new_d *= -1;
        }
        while (new_d >= 10)
        {
            string[i] = new_d % 10 + '0';
            new_d = new_d / 10;
            i++;
        }
        string[i] = new_d + '0';
        string[i + 1] = '\0';
    }
    else
    {
        if (new_d >= 0)
        {
            string = (char *)malloc(sizeof(char) * 2);
            string[0] = new_d + '0';
            string[1] = '\0';
        }
        else
        {
            string = (char *)malloc(sizeof(char) * 2);
            string[0] = '-';
            string[1] = tmp_d + '0';
            string[2] = '\0';
        }
        
    }
    print_int(reverse_string(string), list);
    free(string);
}