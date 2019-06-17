/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_floats.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <slyazid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 21:59:52 by mzahir            #+#    #+#             */
/*   Updated: 2019/01/23 16:56:09 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

double		ft_finddbl_inpos(t_format fparts, va_list start)
{
	int		i;
	double	arg_inpos;

	i = 1;
	while (i <= fparts.position)
	{
		arg_inpos = va_arg(start, double);
		i++;
	}
	return (arg_inpos);
}

long double	ft_findldbl_inpos(t_format fparts, va_list start)
{
	int			i;
	long double	arg_inpos;

	i = 1;
	while (i <= fparts.position)
	{
		arg_inpos = va_arg(start, long double);
		i++;
	}
	return (arg_inpos);
}

int			get_number(char **num, t_format fparts,
			va_list arg_lst, va_list start)
{
	t_dnum	dbl;
	t_ldnum	ldbl;
	short	exponent;

	if (fparts.length.lcap)
	{
		ldbl.d = (fparts.position ?
			ft_findldbl_inpos(fparts, start) : va_arg(arg_lst, long double));
		exponent = get_ldbl_exponent(ldbl);
		*num = ft_check_nans(fparts, exponent, dbl.mem_rep, ldbl.mem_rep) ?
			ft_set_nans(fparts, exponent, dbl.mem_rep, ldbl.mem_rep)
			: get_ldbl_num(ldbl, exponent);
		return (ldbl.mem_rep.sign);
	}
	dbl.d = (fparts.position ?
			ft_finddbl_inpos(fparts, start) : va_arg(arg_lst, double));
	exponent = get_dbl_exponent(dbl);
	*num = ft_check_nans(fparts, exponent, dbl.mem_rep, ldbl.mem_rep) ?
			ft_set_nans(fparts, exponent, dbl.mem_rep, ldbl.mem_rep)
			: get_dbl_num(dbl, exponent);
	return (dbl.mem_rep.sign);
}

void		ft_put_float(t_format fparts, char *num, int sign, int *tot_len)
{
	int		i;

	if (fparts.minus)
		ft_minus_orplus(fparts, sign);
	else
	{
		fparts.zero ? ft_minus_orplus(fparts, sign) : 0;
		ft_adjust_width(fparts, tot_len);
		fparts.zero ? 0 : ft_minus_orplus(fparts, sign);
	}
	while (*num && *num != '.')
		ft_putchar(*num++);
	if (fparts.precision)
	{
		ft_putchar('.');
		i = 1;
		while (num[i] && i <= fparts.precision)
			ft_putchar(num[i++]);
		i--;
		while (++i <= fparts.precision)
			ft_putchar('0');
	}
	else
		fparts.hash ? ft_putchar('.') : 0;
	fparts.minus ? ft_adjust_width(fparts, tot_len) : 0;
}

int			ft_print_floats(t_format fparts, va_list arg_lst, va_list start)
{
	int		sign;
	char	*num;
	char	*freenum;
	int		tot_len;

	start = 0;
	fparts.precision < 0 ? fparts.precision = 6 : 0;
	sign = get_number(&num, fparts, arg_lst, start);
	if (!ft_strcmp(num, "nan") || !ft_strcmp(num, "inf")
		|| !ft_strcmp(num, "NAN") || !ft_strcmp(num, "INF"))
		return (ft_print_nans(fparts, num, sign));
	ft_round_number(&num, fparts.precision);
	freenum = num;
	while (!(*num - 48) && *(num + 1) != '.')
		num++;
	tot_len = (int)(ft_strchr(num, '.') - num) + fparts.precision;
	fparts.precision || fparts.hash ? tot_len++ : 0;
	((!sign && (fparts.plus || fparts.space)) || sign) ? tot_len++ : 0;
	if (fparts.minus)
	{
		ft_put_float(fparts, num, sign, &tot_len);
		return (tot_len);
	}
	ft_put_float(fparts, num, sign, &tot_len);
	return (tot_len);
}
