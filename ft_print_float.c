/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gachibass228 <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 15:29:14 by gachibass22       #+#    #+#             */
/*   Updated: 2019/04/27 17:29:25 by gachibass22      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_float(t_printf *list, long double f)
{
	
}
/*
%f float: storage size 4 byte
1.2E-38 to 3.4E+38

%lf double: storage size 8 byte
2.3E-308 to 1.7E+308

%Lf long double: storage size 10 byte
3.4E-4932 to 1.1E+4932
*/