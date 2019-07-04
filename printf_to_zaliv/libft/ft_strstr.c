/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 14:17:16 by mbeahan           #+#    #+#             */
/*   Updated: 2018/12/02 16:34:27 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *src, const char *to_find)
{
	int		i;
	char	*find;
	char	*str;
	int		j;

	i = 0;
	str = (char *)src;
	find = (char *)to_find;
	j = ft_strlen(find);
	if (j != 0)
	{
		while (str[i] != '\0')
		{
			if (find[0] == str[i])
			{
				if (ft_strncmp(&str[i], find, j) == 0)
					return (&str[i]);
			}
			i++;
		}
		return (NULL);
	}
	return (str);
}
