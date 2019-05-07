/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 18:00:52 by mbeahan           #+#    #+#             */
/*   Updated: 2018/12/23 14:11:24 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
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

static int	symbs_count(char const *s, char c, int i)
{
	int count;

	count = 0;
	if (s)
	{
		while (s[i] != '\0' && s[i] != c)
		{
			count++;
			i++;
		}
		return (count);
	}
	return (0);
}

static char	*add_string(char const *s, char c, int i)
{
	int		word_len;
	char	*str;
	int		j;

	j = 0;
	word_len = symbs_count(s, c, i);
	str = (char *)malloc(sizeof(char) * (word_len + 1));
	if (s && str)
	{
		while (s[i] != '\0' && s[i] != c)
		{
			str[j] = s[i];
			j++;
			i++;
		}
		str[j] = '\0';
		return (str);
	}
	return (0);
}

static char	**ft_while(char const *s, char **str, char c, int i)
{
	int j;

	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			str[j] = add_string(s, c, i);
			if (!str[j])
			{
				while (j >= 0)
				{
					free(str[j]);
					--j;
				}
				return (str);
			}
			j++;
			i = symbs_count(s, c, i) + i;
		}
		if (s[i])
			i++;
	}
	return (str);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		i;
	int		words;

	words = count_words(s, c);
	i = 0;
	str = (char **)malloc(sizeof(char *) * (words + 1));
	if (!(str))
		return (NULL);
	str[words] = NULL;
	if (s && c)
	{
		str = ft_while(s, str, c, i);
		return (str);
	}
	return (NULL);
}
