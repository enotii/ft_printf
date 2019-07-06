/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <mbeahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 15:24:05 by mbeahan           #+#    #+#             */
/*   Updated: 2019/07/05 17:04:05 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parse_int(t_printf *s)
{
	if (!s->size)
		return (ft_printnbr(s, va_arg(s->arg, int)));
	else if (s->size == 2)
		return (ft_printnbr(s, va_arg(s->arg, long long int)));
	else if (s->size == 1)
		return (ft_printnbr(s, va_arg(s->arg, long int)));
	else if (s->size == 4)
		return (ft_printnbr(s, (char)va_arg(s->arg, unsigned int)));
	else if (s->size == 3)
		return (ft_printnbr(s, (short)va_arg(s->arg, int)));
	return (0);
}

int	parse_unsigned(t_printf *s)
{
	if (s->type == 'U')
		return (ft_printnbr_unsigned(s, va_arg(s->arg, unsigned long int)));
	else if (!s->size)
		return (ft_printnbr_unsigned(s, va_arg(s->arg, unsigned int)));
	else if (s->size == 2)
		return (ft_printnbr_unsigned(s, va_arg(s->arg, \
		unsigned long long int)));
	else if (s->size == 1)
		return (ft_printnbr_unsigned(s, va_arg(s->arg, unsigned long int)));
	else if (s->size == 4)
		return (ft_printnbr_unsigned(s, (unsigned char)va_arg(s->arg, int)));
	else if (s->size == 3)
		return (ft_printnbr_unsigned(s, (unsigned short)va_arg(s->arg, int)));
	return (0);
}

int	parse_other(t_printf *s)
{
	int	flag;

	flag = s->type != 'p' && s->type != 'x' && s->type != 'o';
	if (s->type == 'O')
		return (print_other(s, va_arg(s->arg, long long int), flag));
	else if (s->type == 'p')
		return (print_other(s, va_arg(s->arg, unsigned long long int), flag));
	else if (!s->size)
		return (print_other(s, va_arg(s->arg, unsigned int), flag));
	else if (s->size == 2)
		return (print_other(s, va_arg(s->arg, long long int), flag));
	else if (s->size == 1)
		return (print_other(s, va_arg(s->arg, long int), flag));
	else if (s->size == 3)
		return (print_other(s, (unsigned short)va_arg(s->arg, int), flag));
	else if (s->size == 4)
		return (print_other(s, (unsigned char)va_arg(s->arg, int), flag));
	return (0);
}
