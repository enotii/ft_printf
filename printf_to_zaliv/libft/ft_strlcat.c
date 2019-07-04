/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 16:26:47 by mbeahan           #+#    #+#             */
/*   Updated: 2018/12/16 14:52:32 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t i;
	size_t arr_end;

	i = 0;
	if (n > 0)
	{
		while (dst[i] && i < n)
			i++;
		arr_end = i;
		while (src[i - arr_end] && i < n - 1)
		{
			dst[i] = src[i - arr_end];
			i++;
		}
		if (arr_end < n)
			dst[i] = '\0';
		return (arr_end + ft_strlen((char *)src));
	}
	return (ft_strlen((char *)src));
}
