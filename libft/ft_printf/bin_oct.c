/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin_oct.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <slyazid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 19:18:05 by slyazid           #+#    #+#             */
/*   Updated: 2019/01/20 20:05:09 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_put_bin(t_format fparts, int length, int *tot_len, int n)
{
	ft_adjust_precision(fparts, length);
	if (fparts.hash && (n || !fparts.precision))
		ft_putchar('0');
	if (n || fparts.precision)
		ft_putunsigned_base(n, 2, 0);
	ft_adjust_width(fparts, tot_len);
	return (*tot_len);
}

int	ft_put_oct(t_format fparts, int length, int *tot_len, int n)
{
	ft_adjust_precision(fparts, length);
	if (fparts.hash && (n || !fparts.precision))
		ft_putchar('0');
	if (n || fparts.precision)
		fparts.length.l || fparts.length.ll
		? ft_putunsigned_base(n, 8, 0) : ft_putnbr_octal((unsigned int)n);
	ft_adjust_width(fparts, tot_len);
	return (*tot_len);
}

int	ft_print_octals(t_format fparts, va_list arg_lst, va_list start)
{
	unsigned long long	n;
	int					length;
	int					tot_len;

	ft_adjust_length(fparts, arg_lst, start, &n);
	length = ft_get_unsize(n, 8);
	if (!n && !fparts.precision)
		length = 0;
	if (fparts.hash && (n || !fparts.precision))
		length++;
	tot_len = length;
	if (fparts.precision > tot_len)
		tot_len = fparts.precision;
	!fparts.precision ? fparts.zero = 0 : 0;
	if (fparts.minus)
		return (ft_put_oct(fparts, length, &tot_len, n));
	ft_adjust_width(fparts, &tot_len);
	ft_adjust_precision(fparts, length);
	if (fparts.hash && (n || !fparts.precision))
		ft_putchar('0');
	if (n || fparts.precision)
		fparts.length.l || fparts.length.ll ?
			ft_putunsigned_base(n, 8, 0) : ft_putnbr_octal((unsigned int)n);
	return (tot_len);
}

int	ft_print_binary(t_format fparts, va_list arg_lst, va_list start)
{
	unsigned long long	n;
	int					length;
	int					tot_len;

	ft_adjust_length(fparts, arg_lst, start, &n);
	length = ft_get_unsize(n, 2);
	if (!n && !fparts.precision)
		length = 0;
	if (fparts.hash && (n || !fparts.precision))
		length++;
	tot_len = length;
	if (fparts.precision > tot_len)
		tot_len = fparts.precision;
	if (fparts.minus)
		return (ft_put_bin(fparts, length, &tot_len, n));
	ft_adjust_width(fparts, &tot_len);
	ft_adjust_precision(fparts, length);
	if (fparts.hash && (n || !fparts.precision))
		ft_putchar('0');
	if (n || fparts.precision)
		ft_putunsigned_base(n, 2, 0);
	return (tot_len);
}
