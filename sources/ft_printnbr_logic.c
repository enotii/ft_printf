/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr_logic.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <mbeahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 15:36:24 by mbeahan           #+#    #+#             */
/*   Updated: 2019/07/05 16:07:12 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		int_overflow(int f, t_printf *s, t_help_struct *lst)
{
	if (s->space && !lst->space && !f && !s->plus && s->type != 'u')
		write_into_buff(s, 1, ' ');
	else if (lst->space > 0)
		write_into_buff(s, lst->space, ' ');
	if (f || (s->plus && s->type != 'u'))
		f ? write_into_buff(s, 1, '-') : write_into_buff(s, 1, '+');
	write_into_buff(s, lst->zero, '0');
	modified_itoa(lst, s, 0);
}

static void		int_overflow_minus(int f, t_printf *s, t_help_struct *lst)
{
	s->space && !s->plus ? write_into_buff(s, 1, ' ') : 0;
	if (f || (s->plus && s->type != 'u'))
		f ? write_into_buff(s, 1, '-') : write_into_buff(s, 1, '+');
	write_into_buff(s, lst->zero, '0');
	modified_itoa(lst, s, 0);
	write_into_buff(s, lst->space, ' ');
}

static int		space_count(t_printf *s, int l, int f, int zero)
{
	if (!f && !s->plus && !zero && s->width > l)
		return (s->width - l);
	if ((f || s->plus) && !zero && s->width > l + 1)
		return (--s->width - l);
	if (!f && !s->plus && s->width > l && s->width > s->precision)
		return (l > s->precision ? s->width - l : s->width - s->precision);
	if ((f || s->plus) && s->width > l + 1 && s->width > s->precision + 1)
		return (l > s->precision ? --s->width - l : --s->width - s->precision);
	return (0);
}

void			int_format(t_printf *s, t_help_struct *lst, int f)
{
	lst->zero = s->precision > lst->len ? s->precision - lst->len : 0;
	lst->space = space_count(s, lst->len, f, lst->zero);
	f ? lst->minus = 1 : 0;
	!lst->minus && s->plus && s->type != 'u' ? lst->plus = 1 : 0;
	s->minus ? int_overflow_minus(f, s, lst) : int_overflow(f, s, lst);
}

int				change_values(t_printf *s, int l, int f, size_t number)
{
	s->minus && s->space && !s->zero && s->width > 0 ? --s->width : 0;
	if (!s->zero)
		return (!number && s->precision_status && !s->precision ? 0 : l);
	s->minus && s->width > l ? s->minus = 1 : 0;
	s->width > l && !s->precision_status && !f && !s->plus
		&& !s->space && !s->minus ? s->precision = s->width : 0;
	s->width > l && !s->precision_status && !f && !s->plus
		&& s->space && s->width > 0 ? s->precision = --s->width : 0;
	s->width > l && s->precision_status == 0 && !s->minus
		&& (f || s->plus) ? s->precision = --s->width : 0;
	return (!number && s->precision_status && !s->precision ? 0 : l);
}
