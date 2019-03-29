/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <mbeahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 18:53:51 by mbeahan           #+#    #+#             */
/*   Updated: 2019/03/29 21:50:02 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#include "libft/libft.h"
#include <stdarg.h>

typedef struct s_printf
{
    char    minus;
    char    plus;
    char    space;
    char    oktotorp;
    char    zero;
    int     width;
    int     precision;
    char    size;
    char    type;
}              t_printf;
#endif
