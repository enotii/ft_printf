/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin_to_dec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caking <caking@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 16:27:50 by caking            #+#    #+#             */
/*   Updated: 2019/05/13 16:58:47 by caking           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			pos_pow(t_bignum **n, int power, t_bignum *(*f)(t_bignum *))
{
	t_bignum	*tmp;
	int			i;

	i = -1;
	while (++i < ft_abs(power))
	{
		tmp = (*f)(*n);
		big_num_destroy(n);
		*n = tmp;
	}
}

char			frac_dec_mult(t_string *n, t_string *res)
{
	int			i;
	char		rem;
	char		num_res;

	rem = 0;
	i = str_len(n) - 1;
	while (i >= 0)
	{
		num_res = (rem + (str_at(n, i) - '0') * 2) % 10 + '0';
		rem = (rem + ((str_at(n, i) - '0') * 2)) / 10;
		str_pushchar(res, num_res);
		--i;
	}
	str_rev(res);
	return (rem);
}

void			int_dec_mult(t_string *n, t_string *res, char rem)
{
	int			i;
	int			j;
	char		num_res;

	j = 0;
	i = str_len(n);
	while (--i >= 0)
	{
		num_res = (rem + (str_at(n, i) - 48) * 2) % 10 + '0';
		rem = (rem + (str_at(n, i) - 48) * 2) / 10;
		str_pushchar(res, num_res);
	}
	if (rem > 0)
		str_pushchar(res, rem + '0');
	str_rev(res);
}

t_bignum		*dec_mult(t_bignum *n)
{
	t_bignum	*res;
	char		rem;

	res = big_num_create();
	res->sign = n->sign;
	rem = frac_dec_mult(&n->frac_part, &res->frac_part);
	int_dec_mult(&n->int_part, &res->int_part, rem);
	return (res);
}


void			do_int_part(t_bignum *num)
{
	int			i;
	char		*str;
	t_bignum	*tmp;
	t_bignum	*sum;

	i = -1;
	sum = big_num_create_by_str('+', "0", "0");
	while (++i < num->int_part.size)
	{
		str = ft_strdup(&num->int_part.data[i]);
		str[1] = 0;
		tmp = big_num_create_by_str('+', str, "0");
		ft_strdel(&str);
		pos_pow(&tmp, num->int_part.size - i - 1, dec_mult);
		sum = dec_sum(sum, tmp, 3);
	}
	str_destroy(&num->int_part);
	str_push_cs(&num->int_part, &sum->int_part);
	big_num_destroy(&sum);
}

void			do_frac_part(t_bignum *num)
{
	int			i;
	char		*str;
	t_bignum	*sum;
	t_bignum	*temp;

	i = -1;
	sum = big_num_create_by_str('+', "0", "0");
	while (++i < num->frac_part.size)
	{
		str = ft_strdup(&num->frac_part.data[i]);
		str[1] = 0;
		temp = big_num_create_by_str('+', str, "0");
		ft_strdel(&str);
		pos_pow(&temp, i + 1, dec_div);
		sum = dec_sum(sum, temp, 3);
	}
	str_destroy(&num->frac_part);
	str_push_cs(&num->frac_part, &sum->frac_part);
	big_num_destroy(&sum);
}

void			bin_to_dec(t_bignum *num)
{
	do_int_part(num);
	do_frac_part(num);
}