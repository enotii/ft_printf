/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 17:24:57 by mbeahan           #+#    #+#             */
/*   Updated: 2018/12/17 19:13:38 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_symb_start(char const *s)
{
	int i;
	int count;

	count = 0;
	i = 0;
	if (s)
	{
		while (s[i] != '\0')
		{
			if (s[i] != ' ' && s[i] != '\n' && s[i] != '\t')
			{
				count = i;
				break ;
			}
			i++;
		}
		return (count);
	}
	return (0);
}

static int	count_symb_all(char const *s)
{
	int i;
	int count;

	i = 0;
	count = 0;
	if (s)
	{
		while (s[i] != '\0')
		{
			if (s[i] != ' ' && s[i] != '\n' && s[i] != '\t')
				count++;
			i++;
		}
		return (count);
	}
	return (0);
}

static int	count_symb_end(char const *s)
{
	int i;
	int count;

	count = 0;
	i = 0;
	if (s)
	{
		while (s[i] != '\0')
		{
			if (s[i] != ' ' && s[i] != '\n' && s[i] != '\t')
				count = i;
			i++;
		}
		return (count);
	}
	return (0);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	j = count_symb_start(s);
	k = count_symb_end(s);
	i = 0;
	str = (char *)malloc(sizeof(char) * (k - j + 2));
	if (str && s)
	{
		if (count_symb_all(s) != 0)
		{
			while (j <= k)
			{
				str[i] = s[j];
				i++;
				j++;
			}
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
