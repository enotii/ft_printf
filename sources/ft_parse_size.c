/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <mbeahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 22:55:53 by mbeahan           #+#    #+#             */
/*   Updated: 2019/07/06 03:18:32 by caking           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_size(t_printf *s)
{
	unsigned	shor;
	unsigned	lon;

	lon = 0;
	shor = 0;
	while (*s->str && (*s->str == 'l' || *s->str == 'j' || \
	*s->str == 'h' || *s->str == 'L' || *s->str == 'z'))
	{
		if (*s->str == 'l')
			lon++;
		else if (*s->str == 'j' || *s->str == 'z')
			lon += 2;
		else if (*s->str == 'h')
			++shor;
		++s->str;
	}
	if (lon == 1)
		s->size = 1;
	else if (lon > 1)
		s->size = 2;
	else if (shor == 1)
		s->size = 3;
	else if (shor > 1)
		s->size = 4;
}

int		ft_format(t_printf *s)
{
	if (s->type == 'c')
		return (print_char(s));
	if (s->type == 's')
		return (print_string(s));
	if (s->type == 'd' || s->type == 'i')
		return (parse_int(s));
	if (s->type == 'u' || s->type == 'U')
		return (parse_unsigned(s));
	if (s->type == 'x' || s->type == 'X' || s->type == 'p' \
	|| s->type == 'o' || s->type == 'O')
		return (parse_other(s));
	return (0);
}
