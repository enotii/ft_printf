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

static void		int_overflow(int flag, t_printf *storage, t_help_struct *lst)
{
	if (storage->space && !lst->space && !flag && !storage->plus && storage->type != 'u')
		write_into_buff(storage, 1, ' ');
	else if (lst->space > 0)
		write_into_buff(storage, lst->space, ' ');
	if (flag || (storage->plus && storage->type != 'u'))
		flag ? write_into_buff(storage, 1, '-') : write_into_buff(storage, 1, '+');
	write_into_buff(storage, lst->zero, '0');
	modified_itoa(lst, storage, 0);
}

static void		int_overflow_minus(int flag, t_printf *storage, t_help_struct *lst)
{
	storage->space && !storage->plus ? write_into_buff(storage, 1, ' ') : 0;
	if (flag || (storage->plus && storage->type != 'u'))
		flag ? write_into_buff(storage, 1, '-') : write_into_buff(storage, 1, '+');
	write_into_buff(storage, lst->zero, '0');
	modified_itoa(lst, storage, 0);
	write_into_buff(storage, lst->space, ' ');
}

static int	space_count(t_printf *storage, int len, int flag, int zero)
{
	if (!flag && !storage->plus && !zero && storage->width > len)
		return (storage->width - len);
	if ((flag || storage->plus) && !zero && storage->width > len + 1)
		return (--storage->width - len);
	if (!flag && !storage->plus && storage->width > len && storage->width > storage->precision)
		return (len > storage->precision ? storage->width - len : storage->width - storage->precision);
	if ((flag || storage->plus) && storage->width > len + 1 && storage->width > storage->precision + 1)
		return (len > storage->precision ? --storage->width - len : --storage->width - storage->precision);
	return (0);
}

void    int_format(t_printf *storage, t_help_struct *lst, int flag)
{
	lst->zero = storage->precision > lst->len ? storage->precision - lst->len : 0;
	lst->space = space_count(storage, lst->len, flag, lst->zero);
	flag ? lst->minus = 1 : 0;
	!lst->minus && storage->plus && storage->type != 'u' ? lst->plus = 1 : 0;
	storage->minus ? int_overflow_minus(flag, storage, lst) : int_overflow(flag, storage, lst);
}

int     change_values(t_printf *storage, int len, int flag, size_t number)
{
    storage->minus && storage->space  && !storage->zero  && storage->width > 0 ? --storage->width : 0;
    if (!storage->zero)
        return(!number && storage->precision_status && !storage->precision ? 0  : len);
    storage->minus && storage->width > len ? storage->minus = 1 : 0;
	storage->width > len && !storage->precision_status && !flag && !storage->plus
		&& !storage->space && !storage->minus ? storage->precision = storage->width : 0;
	storage->width > len && !storage->precision_status && !flag && !storage->plus
		&& storage->space && storage->width > 0 ? storage->precision = --storage->width : 0;
	storage->width > len && storage->precision_status == 0 && !storage->minus
		&& (flag || storage->plus) ? storage->precision = --storage->width : 0;
	return (!number && storage->precision_status && !storage->precision ? 0 : len);
}