/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 17:38:39 by mbeahan           #+#    #+#             */
/*   Updated: 2018/12/01 19:01:56 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *src, int c)
{
	int		len;
	char	*str;

	len = 0;
	str = (char *)src;
	while (str[len] != '\0')
		len++;
	while (len != 0 && str[len] != (char)c)
		len--;
	if (str[len] == (char)c)
		return (str + len);
	return (NULL);
}
