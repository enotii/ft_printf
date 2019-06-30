/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <mbeahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 21:00:20 by mbeahan           #+#    #+#             */
/*   Updated: 2019/06/30 21:39:44 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void     parse_flags(char *string, t_printf *list, int i, int stop)
{
    int check;

    check = 0;
    while (string[i] && check < 2 && i != stop)
    {
        if (string[i] == '%' && string[i + 1] != '%')
        {
            i++;
            check++;
        }
        if (check > 0)
        {
            if (string[i] == '+')
                list->plus = '+';
            if (string[i] == '-')
                list->minus = '-';
            if (string[i] == '0')
                list->zero = '0';
            if (string[i] == ' ')
                list->space = ' ';
            if (string[i] == '#')
                list->bar = '#';
            if (string[i] != '+' && string[i] != '-' && string[i] != '0' && string[i] != ' ' && string[i] != '#')
                break ;
        }
        i++;
    }
}

int     parse_size(char *string, t_printf *list, int i, int stop)
{
    int check;

    check = 0;
    while (string[i] && check < 2 && i != stop)
    {
        if (string[i] == '%' && string[i + 1] != '%')
        {
            check++;
            i++;
        }
         if (check == 1 && (string[i] == 'h' && string[i + 1] == 'h'))
        {
            list->size = (char *)malloc(sizeof(char) * 2);
            list->size[0] = 'h';
            list->size[1] = 'h';
            return (1);
        }
         if (check == 1 && (string[i] == 'h' && string[i + 1] != 'h'))
        {
            list->size = (char *)malloc(sizeof(char) * 2);
            list->size[0] = 'h';
            list->size[1] = '\0';
            return (1);
        }
        if (check == 1 && (string[i] == 'l' && string[i + 1] == 'l'))
        {
            list->size = (char *)malloc(sizeof(char) * 2);
            list->size[0] = 'l';
            list->size[1] = 'l';
            return (1);
        }
         if (check == 1 && (string[i] == 'l' && string[i + 1] != 'l'))
        {
            list->size = (char *)malloc(sizeof(char) * 2);
            list->size[0] = 'l';
            list->size[1] = '\0';
            return (1);
        }
         if (check == 1 && (string[i] == 'L' && string[i + 1] == 'f'))
        {
            list->size = (char *)malloc(sizeof(char) * 2);
            list->size[0] = 'L';
            list->size[1] = '\0';
            return (1);
        }
         if (check == 1 && string[i] == 'j' && (string[i + 1] == 'u' || string[i + 1] == 'd' || string[i + 1] == 'x'))
        {
            list->size = (char *)malloc(sizeof(char) * 2);
            list->size[0] = 'j';
            list->size[1] = '\0';
            return (1);
        }
         i++;
    }
    return (0);
}

int    parse_type(char *string, t_printf *list, int i)
{
    int check;

    check = 0;
    while (string[i] && check < 2)
    {
        if (string[i] == '%' && string[i + 1] != '%')
        {
            check++;
            i++;
        }
         if (check == 1 && (string[i] == 'd'))
        {
            list->type = 'd';
            i++;
            return(i);
        }
        if (check == 1 && (string[i] == 'c'))
        {
            list->type = 'c';
            i++;
            return(i);
        }
        if (check == 1 && (string[i] == 's'))
        {
            list->type = 's';
            i++;
            return(i);
        }
        if (check == 1 && (string[i] == 'p'))
        {
            list->type = 'p';
            i++;
            return(i);
        }
        if (check == 1 && (string[i] == 'f'))
        {
            list->type = 'f';
            i++;
            return(i);
        }
        if (check == 1 && (string[i] == 'i'))
        {
            list->type = 'i';
            i++;
            return(i);
        }
        if (check == 1 && (string[i] == 'o'))
        {
            list->type = 'o';
            i++;
            return(i);
        }
        if (check == 1 && (string[i] == 'u'))
        {
            list->type = 'u';
            i++;
            return(i);
        }
        if (check == 1 && (string[i] == 'x'))
        {
            list->type = 'x';
            i++;
            return(i);
        }
        if (check == 1 && (string[i] == 'X'))
        {
            list->type = 'X';
            i++;
            return(i);
        }
        i++;
    }
    return(0);
}

void    parse_precision(char *string, t_printf *list, int i, int stop)
{
    int check;
    char *prec;
    int len;
    int tmp;

    prec = NULL;
    check = 0;
    len = -1;
    while (string[i] && check < 2 && i != stop)
    {
        if (string[i] == '%' && string[i + 1] != '%')
        {
            check++;
            i++;
        }
        if (string[i] == '.' && !(string[i + 1] > 47 && string[i + 1] < 58))
            list->precision = 0;
        if (check == 1 && string[i] == '.' && string[i + 1] > 47 && string[i + 1] < 58)
        {
            i += 1;
            tmp = i;
            len = 0;
            while (string[i] > 47 && string[i] < 58)
            {
                len++;
                i++;
            }
            break ;
        }
        i++;
    }
    if (len > 1)
    {
        prec = (char *)malloc(sizeof(char) * len + 1);
        i = 0;
        while (i < len && string[tmp])
        {
            prec[i] = string[tmp];
            i++;
            tmp++;
        }
        prec[i] = '\0';
        i = ft_atoi(prec);
        list->precision = i;
        free(prec);
    }
    if (len == 1)
        list->precision = string[tmp] - '0';
}

void    parse_width(char *string, t_printf *list, int i, int stop)
{
    int     len;
    char    *width;
    int     check;
    int     tmp;

    check = 0;
    len = 0;
    while (string[i] && check < 2 && i != stop)
    {
        if (string[i] == '%' && string[i + 1] != '%')
        {
            i++;
            check++;
        }
        if (check == 1 && (string[i] == '+' || string[i] == '-' || string[i] == '0' || string[i] == ' ' || string[i] == '#'))
            i++;
        if (check == 1 && (string[i] > 47 && string[i] < 58) && string[i - 1] != '.')
        {
            tmp = i;
            while(string[i] > 47 && string[i] < 58)
            {
                i++;
                len++;
            }
             break ;
        }
        if (check == 1 && ((string[i] != '+' && string[i] != '-' && string[i] != '0' && string[i] != ' ' && string[i] != '#') && (!(string[i] > 47 && string[i] < 58))))
             break ;
        i++;
    }
    if (len > 0)
    {
        width = (char *)malloc(sizeof(char) * len);
        i = 0;
        while (i < len)
        {
            width[i] = string[tmp];
            i++;
            tmp++;
        }
        if (ft_atoi(width))
            list->width = ft_atoi(width);
        free(width);
    }
}