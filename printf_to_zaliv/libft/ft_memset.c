/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 16:53:28 by mbeahan           #+#    #+#             */
/*   Updated: 2018/12/16 14:47:54 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *arr, int value, size_t len)
{
	size_t i;

	i = 0;
	while (i < len)
	{
		((char*)arr)[i] = (unsigned char)value;
		i++;
	}
	return (arr);
}
