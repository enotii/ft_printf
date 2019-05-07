/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 19:22:24 by mbeahan           #+#    #+#             */
/*   Updated: 2018/12/17 19:10:58 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		get_len(int nbr)
{
	int	count;

	count = 0;
	if (nbr < 0)
	{
		count++;
		nbr = nbr * -1;
	}
	if (nbr > 0)
	{
		while (nbr / 10)
		{
			nbr = nbr / 10;
			count++;
		}
	}
	return (count);
}

static	char	*get_arr(char *str, int temp_len, int n, int flag)
{
	while (temp_len--)
	{
		str[temp_len] = n % 10 + '0';
		n = n / 10;
		if (flag == 1)
			str[0] = '-';
	}
	return (str);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		temp_len;
	int		flag;

	flag = 0;
	len = get_len(n);
	str = (char *)malloc(sizeof(char) * (len + 2));
	if (!str)
		return (NULL);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	temp_len = len + 1;
	if (n < 0)
	{
		n = -n;
		flag = 1;
	}
	str = get_arr(str, temp_len, n, flag);
	str[len + 1] = '\0';
	return (str);
}
