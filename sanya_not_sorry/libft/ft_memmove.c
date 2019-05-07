/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 17:15:46 by mbeahan           #+#    #+#             */
/*   Updated: 2018/12/17 18:08:38 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dest_tmp;
	char		*src_tmp;
	int			i;

	dest_tmp = (char *)dst;
	src_tmp = (char *)src;
	if (!dst && !src)
		return (NULL);
	if (!len)
		return (dst);
	i = (int)len;
	if (src < dst)
		while ((--i) >= 0)
			*(dest_tmp + i) = *(src_tmp + i);
	else
	{
		i = 0;
		while (i < (int)len)
		{
			*(dest_tmp + i) = *(src_tmp + i);
			i++;
		}
	}
	return (dst);
}
