/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caking <caking@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 16:53:41 by caking            #+#    #+#             */
/*   Updated: 2019/05/16 16:46:56 by caking           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	str_pushchar(t_string *s, char c)
{
	if (s->size == s->capacity)
		str_resize(s, s->size + 25);
	s->data[s->size] = c;
	s->size++;
}

int	str_len(t_string *s)
{
	return (s->size);
}

char	str_at(t_string *s, int idx)
{
	return (s->data[idx]);
}

void	str_destroy(t_string *s)
{
	free(s->data);
	s->data = NULL;
	s->capacity = 0;
	s->size = 0;
}

void	str_push_cs(t_string *l, t_string *r)
{
	int i;

	i = -1;
	while (++i < str_len(r))
		str_pushchar(l, str_at(r, i));
}

t_string		str_create_size(int size)
{
	t_string	str;

	str.data = ft_strnew(size - 1);
	str.size = 0;
	str.capacity = size;
	return (str);
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
       ft_putstr (str);
		ft_strdel(&temp2); 
	}
	big_num_destroy(&num);
	return (str);
}