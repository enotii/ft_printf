/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 15:42:11 by mbeahan           #+#    #+#             */
/*   Updated: 2018/12/16 14:52:22 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(char const *s1, char const *s2)
{
	int len;

	len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	return (len);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		k;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	k = 0;
	str = (char *)malloc(sizeof(char) * (ft_len(s1, s2) + 1));
	if ((s1 && s2) && str)
	{
		while (*s1)
		{
			str[k] = *s1;
			k++;
			s1++;
		}
		while (*s2)
		{
			str[k] = *s2;
			k++;
			s2++;
		}
		str[k] = '\0';
		return (str);
	}
	return (NULL);
}
