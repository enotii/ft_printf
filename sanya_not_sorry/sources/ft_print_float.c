/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caking <caking@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 17:10:15 by mbeahan           #+#    #+#             */
/*   Updated: 2019/06/27 19:58:11 by caking           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int	str_len(t_string *s)
{
	return (s->size);
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

static void		add_sign_float(char sign, char **str, t_printf *lst)
{
	if (sign == '-')
		add_sign(str, '-');
	else if (sign == '+')
		add_sign(str, '+');
	if (ft_strchr(&lst->space, ' ') && sign != '-')
		add_sign(str, ' ');
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

char			*cust_strjoin_left(t_string *s1, char *s2)
{
	char		*new_str;
	size_t		i;
	size_t		j;
	size_t		len;

	if (!s1->size || !s2)
		return (0);
	len = ft_strlen(s2);
	new_str = ft_strnew(s1->size + len);
	if (!new_str)
		return (0);
	i = -1;
	j = -1;
	while (++i < (size_t)s1->size)
		*(new_str + i) = str_at(s1, i);
	while (++j < len)
		*(new_str + i++) = *(s2 + j);
	*(new_str + i) = '\0';
	return (new_str);
}

char			*put_bignum_strings_into_one(t_bignum *num, t_printf *lst)
{
	char	*str;
	char	*temp;
	char	*temp2;
	char	*temp3;

	if (lst->precision == 0)
		str = cust_strdup(&num->int_part);
	else
	{
		temp = cust_strjoin_left(&num->int_part, ".");
		temp2 = cust_strdup(&num->frac_part);
		temp3 = ft_strsub(temp2, 0, lst->precision);
		str = ft_strjoin_free(temp, temp3, 3);
		ft_strdel(&temp2); 
	}
	big_num_destroy(&num);
	return (str);
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

void			rround(t_bignum **num, int precision)
{
	t_bignum	*temp;
	char		save_sign;

	save_sign = (*num)->sign;
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
	(*num)->sign = save_sign;
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

void		str_rev(t_string *s)
{
	int		i;
	char	tmp;

	i = 0;
	while (i * 2 < str_len(s))
	{
		tmp = s->data[i];
		s->data[i] = s->data[str_len(s) - i - 1];
		s->data[str_len(s) - i - 1] = tmp;
		++i;
	}
}

void			swap_comp_str(t_string *s1, t_string *s2)
{
	t_string	tmp;

	if (str_len(s1) < str_len(s2))
	{
		tmp = *s1;
		*s1 = *s2;
		*s2 = tmp;
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

static void			int_sum(t_string l, t_string r, t_string *res, char rem)
{
	int				i;
	int				j;
	char			num_res;

	j = 0;
	swap_comp_str(&l, &r);
	i = str_len(&l) - 1;
	j = str_len(&r);
	while (--j >= 0)
	{
		num_res = (rem + (str_at(&l, i) + str_at(&r, j) - 2 * '0')) % 10 + '0';
		rem = (rem + str_at(&l, i) + str_at(&r, j) - 2 * '0') / 10;
		str_pushchar(res, num_res);
		--i;
	}
	while (i >= 0)
	{
		num_res = (rem + (str_at(&l, i) - '0')) % 10 + '0';
		rem = (rem + str_at(&l, i) - '0') / 10;
		str_pushchar(res, num_res);
		--i;
	}
	if (rem > 0)
		str_pushchar(res, rem + '0');
	str_rev(res);
}

static char			frac_sum(t_string l, t_string r, t_string *res)
{
	int				i;
	char			rem;
	char			num_res;

	rem = 0;
	swap_comp_str(&l, &r);
	i = str_len(&l);
	while (--i >= str_len(&r))
		str_pushchar(res, str_at(&l, i));
	while (i >= 0)
	{
		num_res = (rem + (str_at(&l, i) - '0' +
							str_at(&r, i) - '0')) % 10 + '0';
		rem = (rem + str_at(&l, i) + str_at(&r, i) - 2 * '0') / 10;
		str_pushchar(res, num_res);
		--i;
	}
	str_rev(res);
	return (rem);
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

t_bignum			*dec_sum(t_bignum *l, t_bignum *r, int n)
{
	t_bignum		*res;
	char			rem;

	res = big_num_create();
	res->sign = l->sign;
	rem = frac_sum(l->frac_part, r->frac_part, &res->frac_part);
	int_sum(l->int_part, r->int_part, &res->int_part, rem);
	if (n == 1)
		big_num_destroy(&l);
	else if (n == 2)
		big_num_destroy(&r);
	else if (n == 3)
	{
		big_num_destroy(&l);
		big_num_destroy(&r);
	}
	return (res);
}

t_string		str_create_str(char *s)
{
	t_string	str;
	int			len;
	int			i;

	i = -1;
	len = ft_strlen(s);
	str.data = (char *)malloc(sizeof(char) * len * 3 / 2);
	str.size = len;
	str.capacity = len * 3 / 2;
	while (++i < len)
		str.data[i] = s[i];
	return (str);
}

t_bignum		*big_num_create_by_str(char sign, char *int_part, char *frac_part)
{
	t_bignum	*num;

	num = (t_bignum *)malloc(sizeof(t_bignum));
	num->sign = sign;
	num->int_part = str_create_str(int_part);
	num->frac_part = str_create_str(frac_part);
	return (num);
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

void			bin_to_dec(t_bignum *num)
{
	do_int_part(num);
	do_frac_part(num);
}

char	str_at(t_string *s, int idx)
{
	return (s->data[idx]);
}

void	str_push_cs(t_string *l, t_string *r)
{
	int i;

	i = -1;
	while (++i < str_len(r))
		str_pushchar(l, str_at(r, i));
}

t_string		str_cut(t_string *str, int start, int end)
{
	t_string	new_str;

	new_str = str_create_size(10);
	start--;
	while (++start < end && start < str_len(str))
		str_pushchar(&new_str, str_at(str, start));
	return (new_str);
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

void	str_destroy(t_string *s)
{
	free(s->data);
	s->data = NULL;
	s->capacity = 0;
	s->size = 0;
}

void	big_num_destroy(t_bignum **num)
{
	str_destroy(&(*num)->int_part);
	str_destroy(&(*num)->frac_part);
	free(*num);
	*num = NULL;
}

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

void		str_resize(t_string *s, int new_size)
{
	char	*new_data;
	int		i;

	i = -1;
	new_data = ft_strnew(new_size - 1);
	while (++i < s->size)
		new_data[i] = s->data[i];
	free(s->data);
	s->data = new_data;
	s->capacity = new_size;
}

void	str_pushchar(t_string *s, char c)
{
	if (s->size == s->capacity)
		str_resize(s, s->size + 25);
	s->data[s->size] = c;
	s->size++;
}

t_string		str_create_size(int size)
{
	t_string	str;

	str.data = ft_strnew(size - 1);
	str.size = 0;
	str.capacity = size;
	return (str);
}

t_bignum		*big_num_create(void)
{
	t_bignum	*num;

	num = (t_bignum *)malloc(sizeof(t_bignum));
	num->int_part = str_create_size(5);
	num->frac_part = str_create_size(5);
	return (num);
}

t_bignum		*get_the_bits(long double arg)
{
	int			i;
	int			byte;
	t_bignum	*num;
	int			test;


	i = 62;
	num = big_num_create();
	t.d_num = (long double)arg;
	str_pushchar(&num->int_part, (t.t_double.mantissa >> 63 & 1) + 48);
	byte = 0;
	test = t.t_double.sign >> 0 & 1;
	if ((t.t_double.sign >> 0 & 1) == 0)
		num->sign = '+';
	else
		num->sign = '-';
	while (i >= 0)
	{
		byte = t.t_double.mantissa >> i & 1;
		str_pushchar(&num->frac_part, byte + 48);
		--i;
	}
	if (t.t_double.exponent - 16383 > 0)
		pos_pow(&num, t.t_double.exponent - 16383, bin_mult);
	else
		pos_pow(&num, t.t_double.exponent - 16383, bin_div);
	return (num);
}

void    long_float(t_printf *list, long double arg, char **format)
{
    char		sign;
	t_bignum	*num;
	char		*str;

	if (list->precision == -1)
    	list->precision = 6;
    num = get_the_bits(arg);
    bin_to_dec(num);
	rround(&num, list->precision);
	str = put_bignum_strings_into_one(num, list);
	if (num->sign == '-' || list->plus == '+')
		sign = num->sign;
	add_sign_float(sign, &str, list);
	width_insert(list, &str);
 	if (ft_strchr(&list->bar, '#') && list->precision == 0)
		*format = ft_strjoin_free(str, ".", 1);
	else
	 	*format = str;
	list->symbs += ft_strlen(str);
	ft_putstr(*format);
}

void    default_float(t_printf *list, double arg, char **format)
{
    char		sign;
	t_bignum	*num;
	char		*str;

	if (list->precision == -1)
    	list->precision = 6;
    num = get_the_bits((long double)arg);
    bin_to_dec(num);
	rround(&num, list->precision);
	str = put_bignum_strings_into_one(num, list);
	if (num->sign == '-' || list->plus == '+')
		sign = num->sign;
	add_sign_float(sign, &str, list);
	width_insert(list, &str);
 	if (ft_strchr(&list->bar, '#') && list->precision == 0)
		*format = ft_strjoin_free(str, ".", 1);
	else
	 	*format = str;
	list->symbs += ft_strlen(str);
	ft_putstr(*format);
}