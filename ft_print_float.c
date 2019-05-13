/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caking <caking@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 21:43:43 by gachibass22       #+#    #+#             */
/*   Updated: 2019/05/13 16:21:00 by caking           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_bignum		*big_num_create(void)
{
	t_bignum	*num;

	num = (t_bignum *)malloc(sizeof(t_bignum));
	num->int_part = str_create_size(5);
	num->frac_part = str_create_size(5);
	return (num);
}


t_bignum		*bin_mult(t_bignum *l)
{
	t_bignum	*res;
	char	new_frac_part;

	res = big_num_create();
	res->sign = l->sign;
	new_frac_part = str_cut(&l->frac_part, 1, str_len(&l->frac_part));
	str_push_cs(&res->frac_part, &new_frac_part);
	str_push_cs(&res->int_part, &l->int_part);
	str_pushchar(&res->int_part, str_at(&l->frac_part, 0));
	if (str_len(&res->int_part) == 0)
		str_pushchar(&res->int_part, '0');
	if (str_len(&res->frac_part) == 0)
		str_pushchar(&res->frac_part, '0');
	str_destroy(&new_frac_part);
	return (res);
}

t_bignum		*bin_div(t_bignum *l)
{
	t_bignum	*res;
	char	tmp;

	res = big_num_create();
	res->sign = l->sign;
	tmp = str_cut(&l->int_part, 0, str_len(&l->int_part) - 1);
	str_push_cs(&res->int_part, &tmp);
	str_pushchar(&res->frac_part,
				str_at(&l->int_part, str_len(&l->int_part) - 1));
	str_push_cs(&res->frac_part, &l->frac_part);
	if (str_len(&res->int_part) == 0)
		str_pushchar(&res->int_part, '0');
	if (str_len(&res->frac_part) == 0)
		str_pushchar(&res->frac_part, '0');
	return (res);
}

t_bignum		*get_the_bits(long double arg)
{
	int			i;
	int			byte;
	t_bignum	*num;

	i = 62;
	if (arg < 0)
		arg *= -1.0;
	t.d_num = (long double)arg;
	num = big_num_create();
	str_pushchar(&num->int_part, (t.t_double.mantissa >> 63 & 1) + 48);
	byte = 0;
	while (i >= 0)
	{
		byte = t.t_double.mantissa >> i & 1;
		str_pushchar(&num->frac_part, byte + 48);
		--i;
	}
	if (arg > 0)
	{
		if (t.t_double.exponent - 16383 > 0)
			pos_pow(&num, t.t_double.exponent - 16383, bin_mult);
		else
			pos_pow(&num, t.t_double.exponent - 16383, bin_div);
	}
	return (num);
}

void    default_float(t_printf *list, double arg)
{
    char		sign;
	t_bignum	*num;
	char		*str;

    list->precision = 6;
    num = get_bits(arg);

}


// void    l_float(t_printf *list, double d)
// {
//     int count;
//     char *string;
//     long int new_d;
//     long int tmp_d;
//     int i;

//     new_d = (long int)d;
//     tmp_d = new_d;
//     count = 0;
//     i = 0;
//     if (tmp_d < 0)
//         tmp_d *= -1;
//     if (tmp_d >= 10)
//     {
//         while (tmp_d >= 10)
//         {
//             tmp_d = tmp_d / 10;
//             count++;
//         }
//         if (new_d >= 0)
//             string = (char *)malloc(sizeof(char) * count + 1);
//         else
//         {
//             string = (char *)malloc(sizeof(char) * count + 2);
//             string[i] = '-';
//             i++;
//             new_d *= -1;
//         }
//         while (new_d >= 10)
//         {
//             string[i] = new_d % 10 + '0';
//             new_d = new_d / 10;
//             i++;
//         }
//         string[i] = new_d + '0';
//         string[i + 1] = '\0';
//     }
//     else
//     {
//         if (new_d >= 0)
//         {
//             string = (char *)malloc(sizeof(char) * 1);
//             string[i] = new_d + '0';
//         }
//         else
//         {
//             string = (char *)malloc(sizeof(char) * 2);
//             string[0] = '-';
//             string[1] = tmp_d + '0';
//         }
        
//     }
//     print_float(reverse_string(string, list), list);
//     free(string);
// }