/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gachibass228 <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 20:15:10 by gachibass22       #+#    #+#             */
/*   Updated: 2019/04/05 20:16:35 by gachibass22      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*res(int i, int n, int *convert)
{
	char		*base;
	char		*res;

	base = "0123456789ABCDEF";
	res = (char *)malloc(i * sizeof(res));
	i--;
	if (n == 1)
		res[0] = '-';
	while (i >= 0)
	{
		res[n] = base[convert[i]];
		n++;
		i--;
	}
	res[n] = '\0';
	return (res);
}

char	*ft_itoa_base(int value, int base)
{
	long int	val;
	int			i;
	int			n;
	int			convert[64];

	val = value;
	n = 0;
	if (val < 0)
	{
		val *= -1;
		if (base == 10)
			n = 1;
	}
	i = 0;
	if (val == 0)
		return ("0");
	while (val != 0)
	{
		convert[i++] = val % base;
		val = val / base;
	}
	return (res(i, n, convert));
}