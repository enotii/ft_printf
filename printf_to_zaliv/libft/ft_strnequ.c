/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 16:01:22 by mbeahan           #+#    #+#             */
/*   Updated: 2018/12/15 15:56:45 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int		k;

	k = 0;
	if (!s1 || !s2)
		return (0);
	while ((s1[k] != '\0' || s2[k] != '\0') && (size_t)k < n)
	{
		if (s1[k] != s2[k])
			return (0);
		k++;
	}
	if (s1[k] != s2[k] && (size_t)k < n)
		return (0);
	return (1);
}
