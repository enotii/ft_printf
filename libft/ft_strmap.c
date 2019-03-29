/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 15:30:11 by mbeahan           #+#    #+#             */
/*   Updated: 2018/12/18 16:46:48 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (s != NULL && f != NULL)
	{
		while (s[i] != '\0')
			i++;
		str = (char *)malloc(sizeof(char) * i + 1);
		if (str)
		{
			while (j < i)
			{
				str[j] = f(s[j]);
				j++;
			}
			str[j] = '\0';
			return (str);
		}
	}
	return (NULL);
}
