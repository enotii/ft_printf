/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 19:23:55 by mbeahan           #+#    #+#             */
/*   Updated: 2018/12/17 19:27:52 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_words(char const *s, char c)
{
	int		i;
	int		count;

	count = 0;
	i = 0;
	if (s)
	{
		while (s[i])
		{
			if (s[i] == c && (s[i + 1] != c && s[i + 1] != '\0'))
				count++;
			i++;
		}
		if (s[0] != c)
			count += 1;
		return (count);
	}
	return (0);
}
