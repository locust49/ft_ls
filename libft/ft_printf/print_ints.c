/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ints.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <slyazid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 17:30:33 by slyazid           #+#    #+#             */
/*   Updated: 2019/01/23 16:27:01 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_put_ints(t_format fparts, unsigned long long un,
			long long n, int *tot_len)
{
	if (fparts.apostrophe)
		ft_putstr(ft_convert_deci(un, 10, 0));
	else if (n || fparts.precision)
		ft_putunsigned_base(un, 10, 0);
	fparts.minus ? ft_adjust_width(fparts, tot_len) : 0;
	return (*tot_len);
}

void	ft_handle_prefix(long long n, t_format fparts, int *tot_len,
		unsigned long long *un)
{
	n < 0 && fparts.zero && fparts.precision < 0 ? ft_put_minus(n, un) : 0;
	n >= 0 && fparts.zero && fparts.precision < 0
		? ft_handle_spnplus(fparts) : 0;
	ft_adjust_width(fparts, tot_len);
	(n >= 0 && (!fparts.zero || fparts.precision >= 0))
		? ft_handle_spnplus(fparts) : 0;
	(n < 0 && !*un) ? ft_put_minus(n, un) : 0;
}

int		ft_handle_length(t_format fparts, long long n, int *length)
{
	if (fparts.apostrophe)
	{
		if (!(*length % 3))
			(*length)--;
		*length += *length / 3;
	}
	((!n && !fparts.precision) ? *length = 0 : 0);
	return (*length);
}

int		ft_print_ints(t_format fparts, va_list arg_lst, va_list start)
{
	unsigned long long	un;
	long long			n;
	int					length;
	int					tot_len;

	un = 0;
	n = ft_adjust_length(fparts, arg_lst, start, &un);
	length = ((n && !un) ? ft_get_size(n, 10) : ft_get_size(un, 10));
	tot_len = ft_handle_length(fparts, n, &length);
	(!un && n >= 0) ? un = n : 0;
	((fparts.precision > tot_len) ? tot_len = fparts.precision : 0);
	(((fparts.space || fparts.plus) && n >= 0) ? tot_len++ : 0);
	((n < 0) ? tot_len++ : 0);
	if (fparts.minus)
	{
		(n < 0 && !un) ? ft_put_minus(n, &un) : 0;
		n >= 0 ? ft_handle_spnplus(fparts) : 0;
		ft_adjust_precision(fparts, length);
		return (ft_put_ints(fparts, un, n, &tot_len));
	}
	ft_handle_prefix(n, fparts, &tot_len, &un);
	ft_adjust_precision(fparts, length);
	ft_put_ints(fparts, un, n, &tot_len);
	return (tot_len);
}

int		ft_print_unsigned(t_format fparts, va_list arg_lst, va_list start)
{
	unsigned long long	n;
	int					length;
	int					tot_len;

	ft_adjust_length(fparts, arg_lst, start, &n);
	length = ft_get_unsize(n, 10);
	tot_len = ft_handle_length(fparts, n, &length);
	((fparts.precision > tot_len) ? tot_len = fparts.precision : 0);
	if (fparts.minus)
	{
		ft_adjust_precision(fparts, length);
		if (fparts.apostrophe)
			ft_putstr(ft_convert_deci(n, 10, 0));
		else if (n || fparts.precision)
			ft_putunsigned_base(n, 10, 0);
		ft_adjust_width(fparts, &tot_len);
		return (tot_len);
	}
	ft_adjust_width(fparts, &tot_len);
	ft_adjust_precision(fparts, length);
	if (fparts.apostrophe)
		ft_putstr(ft_convert_deci(n, 10, 0));
	else if (n || fparts.precision)
		ft_putunsigned_base(n, 10, 0);
	return (tot_len);
}
