/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 17:15:11 by mbeahan           #+#    #+#             */
/*   Updated: 2018/12/16 14:47:28 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest_arr, const void *src_ptr, size_t num)
{
	size_t i;

	i = 0;
	while (i < num)
	{
		((char*)dest_arr)[i] = ((char*)src_ptr)[i];
		i++;
	}
	return (dest_arr);
}
