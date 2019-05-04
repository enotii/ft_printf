/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caking <caking@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 13:31:45 by mbeahan           #+#    #+#             */
/*   Updated: 2019/05/05 00:23:33 by caking           ###   ########.fr       */
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
    if (list->space && list->plus)
        list->space = 0;
    if (list->width && list->precision)
    {
        if (list->width == list->precision)
        {
            if (list->space != 0 && string[0] != '-')
                ft_putchar(' ');
            if (list->plus || string[0] == '-')
            {
                if (string[0] == '-')
                    ft_putchar('-');
                else
                    ft_putchar('+');
            }
            i = list->width - len;
            while (i)
            {
                ft_putchar('0');
                i--;
            }
            if (string[0] == '-')
                ft_putstr(string + 1);
            else
                ft_putstr(string);
        }
        if ((list->width > list->precision) && list->precision != -1)
        {
            if (list->space)
                ft_putchar(' ');
            if (list->minus)
            {
                if (list->plus || string[0] == '-')
                {
                    if (string[0] == '-')
                        ft_putchar('-');
                    else
                        ft_putchar('+');
                }
                i = list->precision - len;
                while(i)
                {
                    ft_putchar('0');
                    i--;
                }
                if (string[0] != '-')
                    ft_putstr(string);
                else
                    ft_putstr(string + 1);
                if (string[0] == '-' || list->plus != 0 || list->space != 0)
                    i = list->width - list->precision - 1;
                else
                    i = list->width - list->precision;
                while (i)
                {
                    ft_putchar(' ');
                    i--;
                }
            }
            else
            {
                if (string[0] == '-' || list->plus != 0 || list->space != 0)
                    i = list->width - list->precision - 1;
                else
                    i = list->width - list->precision;
                while (i)
                {
                    ft_putchar(' ');
                    i--;
                }
                i = list->precision - len;
                if (list->plus || string[0] == '-')
                {
                    if (string[0] == '-')
                        ft_putchar('-');
                    else
                        ft_putchar('+');
                }
                while(i)
                {
                    ft_putchar('0');
                    i--;
                }
                if (string[0] != '-')
                    ft_putstr(string);
                else
                    ft_putstr(string + 1);
            }
        }
        if (list->precision > list->width)
        {
            if (list->plus || string[0] == '-')
            {
                if (string[0] == '-')
                    ft_putchar('-');
                else
                    ft_putchar('+');
            }
            if (list->space != 0 && string[0] != '-')
                ft_putchar(' ');
            i = list->precision - len;
            while (i)
            {
                ft_putchar('0');
                i--;
            }
            if (string[0] != '-')
                ft_putstr(string);
            else
                ft_putstr(string + 1);
        }
    }
    if (list->precision != -1 && list->width == 0)
    {
        if (list->plus || string[0] == '-')
        {
            if (string[0] == '-')
                ft_putchar('-');
            else
                ft_putchar('+');
        }
        if (list->space != 0 && string[0] != '-')
                ft_putchar(' ');
        if(list->precision > len)
        {
            i = list->precision - len;
            while (i)
            {
                ft_putchar('0');
                i--;
            }
        }
        if (string[0] != '-')
            ft_putstr(string);
        else
            ft_putstr(string + 1);
    }
    if (list->width != 0 && list->precision == -1)
    {
        if (list->width <= len)
        {
            if (list->plus || string[0] == '-')
            {
                if (string[0] == '-')
                    ft_putstr(string);
                else
                {
                    ft_putchar('+');
                    ft_putstr(string + 1);
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
                while (i)
                {
                    ft_putchar(' ');
                    i--;
                }
                if (list->plus || string[0] == '-')
                {
                    if (string[0] == '-')
                        ft_putchar('-');
                    else
                        ft_putchar('+');
                }
                if (string[0] == '-')
                    ft_putstr(string + 1);
                else
                    ft_putstr(string);
            }
            if (list->minus)
            {
                if (list->plus || string[0] == '-')
                {
                    if (string[0] == '-')
                        ft_putchar('-');
                    else
                        ft_putchar('+');
                }
                if (string[0] == '-')
                    ft_putstr(string + 1);
                else
                    ft_putstr(string);
                if (string[0] == '-' || list->plus != 0 || list->space != 0)
                    i = list->width - len - 1;
                else
                    i = list->width - len;
                while (i)
                {
                    ft_putchar(' ');
                    i--;
                }
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
                        ft_putchar('-');
                    else
                        ft_putchar('+');
                }
                while (i)
                {
                    ft_putchar('0');
                    i--;
                }
                if (string[0] == '-')
                    ft_putstr(string + 1);
                else
                    ft_putstr(string);
            }
        }
    }
    if (list->width == 0 && list->precision == -1)
    {
         if (list->plus || string[0] == '-')
        {
            if (string[0] == '-')
                ft_putchar('-');
            else
                ft_putchar('+');
        }
        if (string[0] == '-')
            ft_putstr(string + 1);
        else
            ft_putstr(string);
    }
}

void    default_int(t_printf *list,int d)
{
    char *string;
    int count;
    long int new_d;
    long int tmp_d;
    int i;

    new_d = d;
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
            string = (char *)malloc(sizeof(char) * 1);
            string[i] = new_d + '0';
        }
        else
        {
            string = (char *)malloc(sizeof(char) * 2);
            string[0] = '-';
            string[1] = tmp_d + '0';
        }
        
    }
    print_int(reverse_string(string, list), list);
    free(string);
}

void    hh_int(t_printf *list, long long int d)
{
    int count;
    char *string;
    signed char new_d;
    signed char tmp_d;
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
            string = (char *)malloc(sizeof(char) * 1);
            string[i] = new_d + '0';
        }
        else
        {
            string = (char *)malloc(sizeof(char) * 2);
            string[0] = '-';
            string[1] = tmp_d + '0';
        }
        
    }
    print_int(reverse_string(string, list), list);
    free(string);
}

void    h_int(t_printf *list, long long int d)
{
    int count;
    char *string;
    short int new_d;
    short int tmp_d;
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
            string = (char *)malloc(sizeof(char) * 1);
            string[i] = new_d + '0';
        }
        else
        {
            string = (char *)malloc(sizeof(char) * 2);
            string[0] = '-';
            string[1] = tmp_d + '0';
        }
        
    }
    print_int(reverse_string(string, list), list);
    free(string);
}

void    ll_int(t_printf *list, long long int d)
{
    int count;
    char *string;
    long long int new_d;
    long long int tmp_d;
    int i;

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
            string = (char *)malloc(sizeof(char) * 1);
            string[i] = new_d + '0';
        }
        else
        {
            string = (char *)malloc(sizeof(char) * 2);
            string[0] = '-';
            string[1] = tmp_d + '0';
        }
        
    }
    print_int(reverse_string(string, list), list);
    free(string);
}

void    l_int(t_printf *list, long long int d)
{
    int count;
    char *string;
    long int new_d;
    long int tmp_d;
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
            string = (char *)malloc(sizeof(char) * 1);
            string[i] = new_d + '0';
        }
        else
        {
            string = (char *)malloc(sizeof(char) * 2);
            string[0] = '-';
            string[1] = tmp_d + '0';
        }
        
    }
    print_int(reverse_string(string, list), list);
    free(string);
}