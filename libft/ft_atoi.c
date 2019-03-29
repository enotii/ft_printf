/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 16:53:41 by mbeahan           #+#    #+#             */
/*   Updated: 2018/12/17 17:59:48 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	long	nb;
	int		isnegative;
	long	check;

	nb = 0;
	isnegative = 1;
	while (*str == ' ' || *str == '\f' || *str == '\t'
			|| *str == '\n' || *str == '\v' || *str == '\r')
		str++;
	if (*str == '-')
		isnegative = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str != '\0' && (*str >= '0' && *str <= '9'))
	{
		check = nb;
		nb = nb * 10 + ((*str - '0') * isnegative);
		str++;
		if ((check < 0) && (nb > check))
			return (0);
		if ((check > 0) && (nb < check))
			return (-1);
	}
	return (nb);
}
