/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 16:11:16 by mbeahan           #+#    #+#             */
/*   Updated: 2018/12/16 14:51:31 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		len;
	char	*dup;
	int		i;

	i = 0;
	len = 0;
	while (src[len] != '\0')
		len++;
	dup = (char*)malloc(sizeof(char) * (len + 1));
	if (dup && src)
	{
		while (i < len)
		{
			dup[i] = src[i];
			i++;
		}
		dup[i] = '\0';
		return (dup);
	}
	return (NULL);
}
