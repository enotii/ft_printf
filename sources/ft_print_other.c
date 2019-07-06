/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_other.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <mbeahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 16:17:36 by mbeahan           #+#    #+#             */
/*   Updated: 2019/07/05 17:55:00 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		write_other_into_buff(t_printf *s, t_help_struct *lst, int flag)
{
	!s->minus ? write_into_buff(s, lst->space, ' ') : 0;
	if (s->sharp)
	{
		write_into_buff(s, 1, '0');
		if (s->type != 'o' && s->type != 'O')
			!flag ? write_into_buff(s, 1, 'x') : write_into_buff(s, 1, 'X');
	}
	write_into_buff(s, lst->zero, '0');
	modified_itoa(lst, s, flag);
	s->minus ? write_into_buff(s, lst->space, ' ') : 0;
}

static int		space_count_x(t_printf *s, t_help_struct *lst)
{
	unsigned char flag;

	flag = s->type == 'o' || s->type == 'O' ? 1 : 2;
	if (!s->sharp && !lst->zero && s->width > lst->len)
		return (s->width - lst->len);
	if (s->sharp && !lst->zero && s->width > lst->len + flag)
		return (s->width - lst->len - flag);
	if (!s->sharp && s->width > lst->len && s->width > s->precision)
		return (lst->len > s->precision ? \
		s->width - lst->len : s->width - s->precision);
		if (s->sharp && s->width > lst->len + flag && \
	s->width > s->precision + flag)
		return (lst->len > s->precision ? \
		s->width - lst->len - flag : s->width - s->precision - flag);
		return (0);
}

static int		initialize_other(t_printf *s, t_help_struct *lst)
{
	unsigned char flag;

	flag = s->type == 'O' || s->type == 'o' ? 1 : 2;
	s->type == 'p' ? s->sharp = 1 : 0;
	(s->type == 'O' || s->type == 'o') && !s->precision_status && \
	!lst->n ? s->sharp = 0 : 0;
	if (!s->zero)
		return (lst->n == 0 && s->precision_status && \
		!s->precision ? 0 : lst->len);
		s->minus && s->width > lst->len && s->zero ? s->minus = 1 : 0;
	s->width > lst->len && !s->precision_status && \
		!s->sharp && !s->minus ? s->precision = s->width : 0;
	s->width > lst->len && !s->precision_status && s->sharp && \
		!s->minus ? s->precision = s->width - flag : 0;
	return (!lst->n && s->precision_status && \
	!s->precision ? 0 : lst->len);
}

int				print_other(t_printf *s, unsigned long long int n, int flag)
{
	t_help_struct	lst;

	ft_bzero(&lst, sizeof(lst));
	!n && s->type != 'o' && s->type != 'O' ? s->sharp = 0 : 0;
	lst.base = s->type == 'O' || s->type == 'o' ? 8 : 16;
	lst.n = n;
	lst.len = symbs_count(n, lst.base);
	lst.len = initialize_other(s, &lst);
	s->precision > lst.len ? lst.zero = s->precision - lst.len : 0;
	(s->type == 'o' || s->type == 'O') && s->precision_status && \
	lst.zero > 0 && s->sharp ? --s->sharp : 0;
	lst.space = space_count_x(s, &lst);
	write_other_into_buff(s, &lst, flag);
	return (1);
}
