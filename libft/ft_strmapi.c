/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 15:30:11 by mbeahan           #+#    #+#             */
/*   Updated: 2018/12/13 17:03:12 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;
	unsigned int	j;

	j = 0;
	i = 0;
	if (s != NULL && f != NULL)
	{
		while (s[i] != '\0')
			i++;
		str = (char *)malloc(sizeof(char) * (i + 1));
		if (str)
		{
			while (j < i)
			{
				str[j] = f(j, s[j]);
				j++;
			}
			str[j] = '\0';
			return (str);
		}
	}
	return (NULL);
}
