/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 13:39:54 by mbeahan           #+#    #+#             */
/*   Updated: 2018/12/02 18:04:28 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	int		i;
	int		j;
	int		k;
	size_t	c;

	c = 0;
	i = 0;
	j = ft_strlen(dest);
	k = ft_strlen((char *)src);
	if (src)
	{
		while (src[i] != '\0' && c < n)
		{
			dest[j] = src[i];
			j++;
			i++;
			c++;
		}
		dest[j] = '\0';
		return (dest);
	}
	if (k > j)
		return (NULL);
	return (NULL);
}
