/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <slyazid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 11:09:33 by mzahir            #+#    #+#             */
/*   Updated: 2019/02/02 22:39:11 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include "../libft.h"
# include <wchar.h>
# include <stdarg.h>

typedef struct		s_length
{
	int	h;
	int	hh;
	int	l;
	int	ll;
	int	lcap;
}					t_length;

typedef struct		s_format
{
	char		specifier;
	int			position;
	int			hash;
	int			plus;
	int			space;
	int			zero;
	int			minus;
	int			width;
	int			precision;
	int			apostrophe;
	int			hexcaps;
	int			dollar;
	int			asterisk;
	t_length	length;
}					t_format;

typedef struct		s_funcps
{
	char	*specifiers;
	int		(*funcp)(t_format, va_list, va_list);
}					t_funcps;

typedef struct		s_float
{
	int m: 23;
	int x: 8;
	int s: 1;
}					t_float;

typedef union		u_float
{
	float	f;
	t_float	mem_rep;
}					t_fnum;

typedef struct		s_ldbl
{
	long	m_frac: 63;
	long	m_int: 1;
	long	exp: 15;
	long	sign: 1;
}					t_ldbl;

typedef struct		s_dbl
{
	long	m_frac: 52;
	long	exp: 11;
	long	sign: 1;
}					t_dbl;

typedef union		u_dbl
{
	double	d;
	t_dbl	mem_rep;
}					t_dnum;

typedef union		u_ldbl
{
	long double	d;
	t_ldbl		mem_rep;
}					t_ldnum;

void				ft_putnbr_base(long long nb, int base, int caps);
void				ft_putunsigned_base(unsigned long long nb,
					int base, int caps);
void				ft_putnbr_octal(unsigned int nb);

int					ft_isspecifier(int c);
int					ft_isflag(int c);
int					ft_iswidth_orprecision(int c);
int					ft_islength(int c);

void				ft_putunsigned_base(unsigned long long nb,
					int base, int caps);

int					ft_print_ints(t_format fparts,
					va_list arg_lst, va_list start);
int					ft_print_unsigned(t_format fparts,
					va_list arg_lst, va_list start);
int					ft_print_octals(t_format fparts,
					va_list arg_lst, va_list start);
int					ft_print_binary(t_format fparts,
					va_list arg_lst, va_list start);

int					ft_print_hex(t_format fparts,
					va_list arg_lst, va_list start);

int					ft_print_chars(t_format fparts,
					va_list arg_lst, va_list start);
int					ft_print_strings(t_format fparts,
					va_list arg_lst, va_list start);
int					ft_print_address(t_format fparts,
					va_list arg_lst, va_list start);

int					ft_print_notspeci(t_format fparts, char c);

void				ft_initialize_dispatcher(t_funcps dispatcher[]);

int					ft_get_size(long long n, int base);

int					ft_print_floats(t_format fparts, va_list arg_lst,
					va_list start);

void				ft_initialize_flags(t_format *fparts);
void				ft_set_flags(char **format, t_format *fparts);
void				ft_set_width(char **format,
					va_list arg_lst, t_format *fparts);
void				ft_set_precision(char **format,
					va_list arg_lst, t_format *fparts);
void				ft_set_length(char **format, t_format *fparts);

char				*ft_convert_deci(unsigned long long nb, int base, int caps);

long long			ft_adjust_length(t_format fparts, va_list arg_lst,
					va_list start, unsigned long long *un);

void				ft_handle_spnplus(t_format fparts);
void				ft_put_minus(long long n, unsigned long long *un);
long long			ft_find_inpos(t_format fparts, va_list start);
unsigned long long	ft_find_uninpos(t_format fparts, va_list start);

void				ft_adjust_width(t_format fparts, int *tot_len);
void				ft_adjust_precision(t_format fparts, int length);

int					ft_deal_dollar(t_format *fparts, va_list start,
					char **format);

double				get_binary_val(char *binary);

int					ft_get_size(long long n, int base);
int					ft_get_unsize(unsigned long long n, int base);
char				*ft_get_format(char *format, va_list arg_lst,
					va_list start, int *length);

int					ft_add_strings(char *num, char *to_add, int pos);
void				ft_multiply_strings(char *num, char multiplier);
short				get_dbl_exponent(t_dnum f);
short				get_ldbl_exponent(t_ldnum f);
char				*get_dbl_num(t_dnum f, short exponent);
char				*get_ldblnum_val(char *binary);
char				*get_ldbl_num(t_ldnum f, short exponent);
void				ft_minus_orplus(t_format fparts, int sign);
int					ft_check_nans(t_format fparts, short exponent,
					t_dbl d_memrep, t_ldbl ldbl_memrep);
char				*ft_set_nans(t_format fparts, short exponent,
					t_dbl d_memrep, t_ldbl ld_memrep);
int					ft_print_nans(t_format fparts, char *num, int sign);
int					get_number(char **num, t_format fparts,
					va_list arg_lst, va_list start);
char				*get_float_number(char *binary);
int					ft_round_number(char **num, int precision);

char				*ft_findstr_inpos(t_format fparts, va_list start);

int					ft_print_nonprintable(t_format fparts, va_list arg_lst,
					va_list start);

int					ft_print_unicode(t_format fparts,
					va_list arg_lst, va_list start);
int					ft_print_unicodestr(t_format fparts,
					va_list arg_lst, va_list start);
int					get_unistr_len(wchar_t *unistr);
int					get_unirealprecision(wchar_t *unistr, int precision);
unsigned int		set_utf8(wchar_t c, int *i);

int					ft_print_date(t_format fparts, va_list arg_lst,
					va_list start);

int					ft_print_nonformatted(char *last_arg, char *find_next);
int					ft_cut_color(char **str);
int					ft_check_color(char *str);
int					ft_check_eoc(char **str);

int					ft_printf(const char *fstr, ...);

#endif
