/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 19:27:29 by mbeahan           #+#    #+#             */
/*   Updated: 2018/12/17 19:31:05 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_list(t_list *lst)
{
	t_list	*current;

	if (lst)
	{
		if (!lst->next)
			free(lst);
		if (lst->next)
		{
			while (lst->next)
			{
				current = lst->next;
				free(lst);
				lst = current;
			}
			free(current);
		}
	}
}
