/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 17:13:50 by mbeahan           #+#    #+#             */
/*   Updated: 2018/12/16 14:50:35 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *src, int n)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)src;
	while (str[i] != n)
	{
		if (str[i] == '\0')
			return (NULL);
		i++;
	}
	return (str + i);
}
