/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <mbeahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 22:07:41 by mbeahan           #+#    #+#             */
/*   Updated: 2019/07/05 17:42:01 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define MAXBUFFSIZE 100
# include <stdarg.h>
# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_printf 
{
    char            buff[MAXBUFFSIZE];
    unsigned int    b_i;
    int             len;
    int             width;
    int     precision;
    char    *str;
    va_list arg;
    char    minus;
    char    plus;
    char    space;
    char    sharp;
    char    zero;
    char    precision_status;
    char    type;
    char    size;
}               t_printf;

typedef struct s_help_struct
{
    unsigned long long int number;
    int space;
    int zero;
    int minus;
    int plus;
    int base;
    int len;
}              t_help_struct;

typedef struct		s_string
{
	char			*data;
	int				size;
	int				capacity;
}					t_string;

typedef struct		s_bignum
{
    char			sign;
	t_string	    int_part;
	t_string		frac_part;
}					t_bignum;
union
{
	long double		d_num;
	struct			s_double
	{
		__uint128_t mantissa:64;
		__uint128_t exponent:15;
		__uint128_t sign:1;
	}				t_double;
}					t;

void    print_buff(t_printf *storage);
void    write_into_buff(t_printf *storage, size_t len, char symb);
void    parse_flags(t_printf *storage);
void    parse_width(t_printf *storage);
void    parse_precision(t_printf *storage);
void    parse_size(t_printf *storage);
void    int_format(t_printf *storage, t_help_struct *lst, int flag);
void	modified_itoa(t_help_struct *lst, t_printf *storage, int flag);
void	zeroing_args(t_printf *storage);
void	ft_bzero(void *s, size_t n);
int     print_char(t_printf *storage);
int     parse_int(t_printf *storage);
int     parse_unsigned(t_printf *storage);
int	    parse_other(t_printf *storage);
int     symbs_count(unsigned long long d, int base);
int     change_values(t_printf *storage, int len, int flag, size_t number);
int     ft_printnbr_unsigned(t_printf *storage, unsigned long long number);
int		print_other(t_printf *storage, unsigned long long int number, int flag);
int     ft_format(t_printf *storage);
int     ft_printnbr(t_printf *storage, long long number);
int     print_string(t_printf *storage);
size_t	ft_strlen(const char *str);
int	    ft_printf(char const *s, ...);
//--------------------Print Float-------------------//



//void    print_float(t_printf *list, long double arg);
void        long_float(t_printf *list, long double arg);
void        default_float(t_printf *list, double arg);
t_bignum    *get_the_bits(long double arg);
t_bignum    *big_num_create(void);
t_string    str_create_size(int size);
void        str_pushchar(t_string *s, char c);
void        str_resize(t_string *s, int new_size);
void        pos_pow(t_bignum **n, int power, t_bignum *(*f)(t_bignum *));
void        big_num_destroy(t_bignum **num);
void        str_destroy(t_string *s);
t_bignum    *bin_div(t_bignum *l);
t_bignum    *bin_mult(t_bignum *l);
t_string	str_cut(t_string *str, int start, int end);
void        str_push_cs(t_string *l, t_string *r);
char        str_at(t_string *s, int idx);
void        bin_to_dec(t_bignum *num);
void        do_int_part(t_bignum *num);
t_bignum    *big_num_create_by_str(char sign, char *int_part, char *frac_part);
t_string    str_create_str(char *s);
t_bignum    *dec_sum(t_bignum *l, t_bignum *r, int n);
t_bignum    *dec_mult(t_bignum *n);
static char frac_sum(t_string l, t_string r, t_string *res);
static void int_sum(t_string l, t_string r, t_string *res, char rem);
char		frac_dec_mult(t_string *n, t_string *res);
void		swap_comp_str(t_string *s1, t_string *s2);
void		str_rev(t_string *s);
void		do_frac_part(t_bignum *num);
t_bignum	*dec_div(t_bignum *n);
int			find_digit(t_string *s, int start);
static void	put_zeros(int precision, t_string *str);
char		*put_bignum_strings_into_one(t_bignum *num, t_printf *lst);
char		*cust_strjoin_left(t_string *s1, char *s2);
char		*cust_strdup(t_string *src);
char		*ft_strjoin_free(char *s1, char *s2, int n);
static void	add_sign_float(char sign, char **str, t_printf *lst);
void		add_sign(char **str, char sign);
void		width_insert(t_printf *list, char **substr);
void		width_insert_left(char **new_str, char *substr, int width, char c);
void		width_insert_right(char **new_str, char *substr, int width, char c);
char		del_minus(char **str);
int			str_len(t_string *s);
void		int_dec_mult(t_string *n, t_string *res, char rem);
///void		long_float(t_printf *list, long double arg, char **format);


#endif