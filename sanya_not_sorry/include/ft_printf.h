/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caking <caking@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 18:53:51 by mbeahan           #+#    #+#             */
/*   Updated: 2019/06/27 20:02:57 by caking           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft/libft.h"
# include <stdarg.h>
# include <stdio.h>

typedef struct  s_printf
{
    char    minus;
    char    plus;
    char    space;
    char    bar;
    char    zero;
    int     width;
    int     precision;
    char    *size;
    char    type;
    int     symbs;
}               t_printf;

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

//-----------------Parse function's-----------------//
void    parse_flags(char *string, t_printf *list, int i, int stop);
void    parse_size(char *string, t_printf *list, int i, int stop);
int     parse_type(char *string, t_printf *list, int i);
void    parse_precision(char *string, t_printf *list, int i, int stop);
void    parse_width(char *string, t_printf *list, int i, int stop);
//----------------Print char and string-------------//
void    ft_print_char(t_printf *list, int c);
void    ft_print_string(t_printf *list, char *string);
//------------------Print pointer-------------------//
void    parse_address(t_printf *list, void *address);
void    get_string_addres(t_printf *list, int *array, int count);
//-------------------Print unsigned-----------------//
void    unsigned_l(t_printf *list, unsigned long long u);
void    unsigned_ll(t_printf *list, unsigned long long u);
void    unsigned_h(t_printf *list, unsigned long long u);
void    unsigned_hh(t_printf *list, unsigned long long u);
void    print_unsigned(char *string, t_printf *list);
//---------------------Print INT---------------------//
void    default_int(t_printf *list, long long int d);
void    hh_int(t_printf *list, long long int d);
void    h_int(t_printf *list, long long int d);
void    ll_int(t_printf *list, long long int d);
void    l_int(t_printf *list, long long int d);
void    print_int(char *string, t_printf *list);
//--------------------Print X ----------------------//
void     print_x(t_printf *lst, char *string);
void     get_x_string(t_printf *list, int *array, int count);
void     default_x(t_printf *list, unsigned long long x);
void     hh_x(t_printf *list, unsigned long long x);
void     h_x(t_printf *list, unsigned long long x);
void     ll_x(t_printf *list, unsigned long long x);
void     l_x(t_printf *list, unsigned long long x);
//--------------------Print Octal-------------------//
void    print_octal(t_printf *lst, char *string);
void    get_o_string(t_printf *list, int *array, int count);
void    default_o(t_printf *list, unsigned long long x);
void    hh_o(t_printf *list, unsigned long long x);
void    h_o(t_printf *list, unsigned long long x);
void    ll_o(t_printf *list, unsigned long long x);
void    l_o(t_printf *list, unsigned long long x);
//--------------------Print Float-------------------//
void        default_float(t_printf *list, double arg, char **format);
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
void		long_float(t_printf *list, long double arg, char **format);
//------------------Help function's-----------------//
void    zeroing_args(t_printf **list);
void    ft_print(char *string, int start);
char    *reverse_string(char *string);
void    putstr_symbs(char *str, t_printf *lst);
void    print_n_times(int i, char c, t_printf *lst);
void    print_n_symbs(char *str, int i, t_printf *lst);
//----------------------PRINTF----------------------//
int     ft_printf(const char *format, ...);
int     help_ft_printf(t_printf *lst, const char *string, va_list ap);
void    needed_to_print(t_printf *lst, va_list ap, char *s);

#endif
