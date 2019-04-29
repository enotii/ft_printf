/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gachibass228 <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 21:43:43 by gachibass22       #+#    #+#             */
/*   Updated: 2019/04/30 00:15:40 by gachibass22      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	defaut_f(t_printf *list, long double f)
{
	long double new_f;
	long double tmp_f;
	int count;

	new_f = f;
	tmp_f = (float)new_f;
	count = 0;
	if (tmp_f >= 10)
	{
		while (tmp_f >= 10)
		{
			tmp_f = tmp_f / 10;
			count++;
		}
	}
	printf("%0.60Lf\n", new_f);
}
void	l_float(t_printf *list, long double f)
{

}
void	L_float(t_printf *list, long double f)
{

} 