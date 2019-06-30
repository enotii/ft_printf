/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <mbeahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 20:51:54 by mbeahan           #+#    #+#             */
/*   Updated: 2019/06/30 20:48:08 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void       zeroing_args(t_printf **list)
{
    (*list)->minus = 0;
    (*list)->plus = 0;
    (*list)->space = 0;
    (*list)->bar = 0;
    (*list)->zero = 0;
    (*list)->width = 0;
    (*list)->precision = -1;
    (*list)->size = 0;
    (*list)->type = 0;
}

void     ft_print(char *string, int start)
{
    while (string[start] && (!(string[start] == '%' && string[start + 1] != '%')))
    {
        ft_putchar(string[start]);
        start++;
    }
}

char    *reverse_string(char *string)
{
    char *str;
    int len;
    int i;

    i = 0;
    len = ft_strlen(string);
    str = ft_strdup(string);
    len = len - 1;
    if (string[i] != '-')
    {
        while (len >= 0)
        {
            string[i] = str[len];
            i++;
            len--;
        }
    }
    if (string[i] == '-')
    {
        i++;
        while (len != 0)
        {
            string[i] = str[len];
            i++;
            len--;
        }
    }
    string[i] = '\0';
    free(str);
    return (string);
}

void    print_n_times(int i, char c, t_printf *lst)
{
    if (i > 0)
        lst->symbs += i;
    while (i > 0)
    {
        ft_putchar(c);
        i--;
    }
}

void    putstr_symbs(char *str, t_printf *lst)
{
    lst->symbs += ft_strlen(str);
    ft_putstr(str);
}

void    print_n_symbs(char *str, int i, t_printf *lst)
{
    lst->symbs += i;
    while (i)
    {
        ft_putchar(*str);
        str++;
        i--;
    }
}