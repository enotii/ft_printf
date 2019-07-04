/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 14:47:03 by mbeahan           #+#    #+#             */
/*   Updated: 2018/12/18 16:43:08 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free(t_list *lst)
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

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_list;
	t_list	*begin;

	if (lst && f)
	{
		begin = f(lst);
		new_list = begin;
		while (lst->next)
		{
			lst = lst->next;
			begin->next = f(lst);
			if (!(begin->next = f(lst)))
			{
				ft_free(begin);
				return (NULL);
			}
			begin = begin->next;
		}
		return (new_list);
	}
	return (NULL);
}
