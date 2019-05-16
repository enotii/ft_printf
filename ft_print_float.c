/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caking <caking@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 21:43:43 by gachibass22       #+#    #+#             */
/*   Updated: 2019/05/16 16:50:11 by caking           ###   ########.fr       */
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

t_bignum	*dec_div(t_bignum *n)
{
	t_bignum	*res;
	int			i;

	i = -1;
	res = big_num_create();
	res->sign = n->sign;
	if (n->int_part.data[0] == '1')
	{
		big_num_destroy(&res);
		res = big_num_create_by_str(n->sign, "0", "5");
		return (res);
	}
	str_pushchar(&res->int_part, '0');
	while (++i < n->frac_part.size)
		if (i > 0)
			str_pushchar(&res->frac_part, ((n->frac_part.data[i] - 48) +
				(n->frac_part.data[i - 1] - 48) % 2 * 10) / 2 + 48);
		else
			str_pushchar(&res->frac_part, (n->frac_part.data[i] - 48) / 2 + 48);
	str_pushchar(&res->frac_part, (n->frac_part.data[i - 1]));
	return (res);
}

t_bignum		*bin_mult(t_bignum *l)
{
	t_bignum	*res;
	t_string	new_frac_part;

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
	t_string	tmp;

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

static void		put_zeros(int precision, t_string *str)
{
	if (precision > str->size)
		while (precision != str->size)
			str_pushchar(str, '0');
}

int				find_digit(t_string *s, int start)
{
	while (start < str_len(s))
		if (s->data[start++] > '0')
			return (1);
	return (0);
}

char			*cust_strdup(t_string *src)
{
	int			i;
	char		*new_s1;

	if (!src->size)
		return (NULL);
	i = 0;
	if (!(new_s1 = malloc(sizeof(char) * (src->size + 1))))
		return (0);
	while (i < src->size)
	{
		new_s1[i] = str_at(src, i);
		i++;
	}
	new_s1[i] = '\0';
	return (new_s1);
}

static void		add_sign_float(char sign, char **str, t_printf *lst)
{
	if (sign == '-')
		add_sign(str, '-');
	else if (sign == '+')
		add_sign(str, '+');
	if (ft_strchr(&lst->space, ' ') && sign != '-')
		add_sign(str, ' ');
}

void			rround(t_bignum **num, int precision)
{
	t_bignum *temp;

	put_zeros(precision, &(*num)->frac_part);
	if (((*num)->frac_part.size > precision &&
		(*num)->frac_part.data[precision] <= '4') ||
			!find_digit(&(*num)->frac_part, precision + 1))
		return ;
	if (precision == 0)
	{
		(*num)->int_part.data[(*num)->int_part.size - 1]++;
		return ;
	}
	temp = big_num_create();
	str_pushchar(&temp->int_part, '0');
	while (precision-- > 1)
		str_pushchar(&temp->frac_part, '0');
	str_pushchar(&temp->frac_part, '1');
	*num = dec_sum(*num, temp, 3);
}

void		add_sign(char **str, char sign)
{
	char	*new_str;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(*str) + 1;
	new_str = ft_strnew(len);
	new_str[0] = sign;
	while (++i < len)
		new_str[i] = (*str)[i - 1];
	ft_strdel(str);
	*str = new_str;
}

char		del_minus(char **str)
{
	int		i;
	int		len;
	char	sign;

	sign = **str;
	i = -1;
	len = ft_strlen(*str) - 1;
	while (++i < len)
		(*str)[i] = (*str)[i + 1];
	(*str)[i] = 0;
	return (sign);
}

void		width_insert_right(char **new_str, char *substr, int width, char c)
{
	int		i;
	char	sign;

	i = 0;
	if (*substr && c == '0' && (*substr == '-' || *substr == '+' ||
													*substr == ' '))
		sign = del_minus(&substr);
	while (*substr)
		(*new_str)[i++] = *substr++;
	while (width-- > 0)
		(*new_str)[i++] = c;
	if (c == '0' && sign != -1)
	{
		add_sign(new_str, sign);
		i++;
	}
	(*new_str)[i] = '\0';
}

void		width_insert_left(char **new_str, char *substr, int width, char c)
{
	int		i;
	char	sign;

	i = 0;
	sign = -1;
	if (*substr && c == '0' && (*substr == '-' || *substr == '+' ||
													*substr == ' '))
		sign = del_minus(&substr);
	while (width-- > 0)
		(*new_str)[i++] = c;
	while (*substr)
		(*new_str)[i++] = *substr++;
	if (c == '0' && sign != -1)
	{
		add_sign(new_str, sign);
		i++;
	}
	(*new_str)[i] = '\0';
}

void		width_insert(t_printf *list, char **substr)
{
	int		width;
	char	c;
	char	*new_str;

	c = ' ';
	width = list->width - ft_strlen(*substr);
	if (width <= 0)
		return ;
	new_str = ft_strnew((ft_strlen(*substr) + width));
	if (list->zero)
		c = '0';
	if (list->minus)
		width_insert_right(&new_str, *substr, width, c);
	else
		width_insert_left(&new_str, *substr, width, c);
	ft_strdel(substr);
	*substr = new_str;
}

char	*ft_strjoin_free(char *s1, char *s2, int n)
{
	char	*res;
	size_t	len1;
	size_t	len2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	res = NULL;
	res = ft_strnew(len1 + len2);
	if (res == NULL)
		return (NULL);
	ft_strcat(res, s1);
	ft_strcat(res, s2);
	if (n == 1)
		free(s1);
	else if (n == 2)
		free(s2);
	else if (n == 3)
	{
		free(s1);
		free(s2);
	}
	return (res);
}


void    default_float(t_printf *list, double arg, char **format)
{
    char		sign;
	t_bignum	*num;
	char		*str;

    list->precision = 6;
    num = get_the_bits(arg);
    bin_to_dec(num);
	rround(&num, list->precision);
	str = put_bignum_strings_into_one(num, list);
	add_sign_float(sign, &str, list);
	width_insert(list, &str);
 if (ft_strchr(&list->bar, '#') && list->precision == 0)
		*format = ft_strjoin_free(str, ".", 1);
	else
	 	*format = str;
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