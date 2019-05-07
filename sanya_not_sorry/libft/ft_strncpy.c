/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 12:48:16 by mbeahan           #+#    #+#             */
/*   Updated: 2018/12/11 19:06:43 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	int		i;
	int		src_len;
	size_t	c;

	src_len = ft_strlen((char *)src);
	c = 0;
	i = 0;
	while (src[i] != '\0' && c < n)
	{
		dest[i] = src[i];
		i++;
		c++;
	}
	if ((size_t)src_len < n)
	{
		while ((size_t)i < n)
		{
			dest[i] = '\0';
			i++;
		}
	}
	return (dest);
}
