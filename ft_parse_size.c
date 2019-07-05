/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <mbeahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 22:55:53 by mbeahan           #+#    #+#             */
/*   Updated: 2019/07/05 17:41:47 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    parse_size(t_printf *storage)
{
    unsigned lon;
    unsigned shor;

    lon = 0;
    shor = 0;
    while (*storage->str && (*storage->str == 'l' || *storage->str == 'j' ||
     *storage->str == 'h' || *storage->str == 'L' || *storage->str == 'z'))
    {
    	if (*storage->str == 'l')
            lon++;
        else if (*storage->str == 'j' || *storage->str == 'z')
            lon += 2;
        else if (*storage->str == 'h')
			++shor;
		++storage->str;
    }
	if (lon == 1)
		storage->size = 1;
	else if (lon > 1)
		storage->size = 2;
	else if (shor == 1)
		storage->size = 3;
	else if (shor > 1)
		storage->size = 4;
}

int  ft_format(t_printf *storage)
{
    if (storage->type == 'c')
        return(print_char(storage));
    if (storage->type == 's')
        return (print_string(storage));
    if (storage->type == 'f')
    {
        va_list ap;
       // print_float(storage ,va_arg(ap, long double));
    if (storage->size == 0)
            default_float(storage,va_arg(ap, double));
        else if (storage->size == 'l' || storage->size == 'L')
            long_float(storage,va_arg(ap, long double));
    }
    if (storage->type == 'd' || storage->type == 'i')
        return (parse_int(storage));
    if (storage->type == 'u' || storage->type == 'U')
        return(parse_unsigned(storage));
    if (storage->type == 'x' || storage->type == 'X' || storage->type == 'p'
	|| storage->type == 'o' || storage->type == 'O')
		return (parse_other(storage));
    return (0);
}