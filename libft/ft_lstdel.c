/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 16:15:41 by mbeahan           #+#    #+#             */
/*   Updated: 2018/12/16 18:17:21 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp_lst;
	t_list	*tmp_lst_next;

	if (alst && del && *alst)
	{
		tmp_lst = *alst;
		while (tmp_lst)
		{
			tmp_lst_next = tmp_lst->next;
			del(tmp_lst->content, tmp_lst->content_size);
			free(tmp_lst);
			tmp_lst = tmp_lst_next;
		}
		*alst = NULL;
	}
}
