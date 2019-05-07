/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 14:17:16 by mbeahan           #+#    #+#             */
/*   Updated: 2018/12/13 16:41:20 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *src, const char *to_find, size_t len)
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
			if (find[0] == str[i] && len >= (size_t)i + (size_t)j)
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
