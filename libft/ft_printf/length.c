/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <slyazid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 17:56:33 by slyazid           #+#    #+#             */
/*   Updated: 2019/01/20 21:54:24 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

long long			ft_find_inpos(t_format fparts, va_list start)
{
	int			i;
	long long	arg_inpos;

	i = 1;
	while (i <= fparts.position)
	{
		arg_inpos = va_arg(start, long long);
		i++;
	}
	return (arg_inpos);
}

unsigned long long	ft_find_uninpos(t_format fparts, va_list start)
{
	int					i;
	unsigned long long	unarg_inpos;

	i = 1;
	while (i <= fparts.position)
	{
		unarg_inpos = va_arg(start, unsigned long long);
		i++;
	}
	return (unarg_inpos);
}

void				ft_int_length(t_format fparts, va_list arg_lst,
					va_list start, long long *n)
{
	if (fparts.position)
	{
		if (fparts.length.hh)
			*n = (char)ft_find_inpos(fparts, start);
		else if (fparts.length.h)
			*n = (short)ft_find_inpos(fparts, start);
		else if (fparts.length.l)
			*n = (long)ft_find_inpos(fparts, start);
		else if (fparts.length.ll)
			*n = (long long)ft_find_inpos(fparts, start);
		else
			*n = (int)ft_find_inpos(fparts, start);
		va_copy(arg_lst, start);
		return ;
	}
	if (fparts.length.hh)
		*n = (char)va_arg(arg_lst, int);
	else if (fparts.length.h)
		*n = (short)va_arg(arg_lst, int);
	else if (fparts.length.l)
		*n = (long)va_arg(arg_lst, long);
	else if (fparts.length.ll)
		*n = (long long)va_arg(arg_lst, long long);
	else
		*n = (int)va_arg(arg_lst, int);
}

void				ft_unsigned_length(t_format fparts, va_list arg_lst,
					va_list start, unsigned long long *un)
{
	if (fparts.position)
	{
		if (fparts.length.hh)
			*un = (unsigned long long)ft_find_uninpos(fparts, start);
		else if (fparts.length.h)
			*un = (unsigned long)ft_find_uninpos(fparts, start);
		else if (fparts.length.l)
			*un = (unsigned short)ft_find_uninpos(fparts, start);
		else if (fparts.length.ll)
			*un = (unsigned char)ft_find_uninpos(fparts, start);
		else
			*un = (unsigned int)ft_find_uninpos(fparts, start);
		va_copy(arg_lst, start);
		return ;
	}
	if (fparts.length.ll)
		*un = (unsigned long long)va_arg(arg_lst, unsigned long long);
	else if (fparts.length.l)
		*un = (unsigned long)va_arg(arg_lst, unsigned long);
	else if (fparts.length.h)
		*un = (unsigned short)va_arg(arg_lst, int);
	else if (fparts.length.hh)
		*un = (unsigned char)va_arg(arg_lst, int);
	else
		*un = (unsigned int)va_arg(arg_lst, unsigned int);
}

long long			ft_adjust_length(t_format fparts, va_list arg_lst,
					va_list start, unsigned long long *un)
{
	long long n;

	n = 0;
	if (fparts.specifier == 'd'
		|| fparts.specifier == 'i' || fparts.specifier == 'c')
		ft_int_length(fparts, arg_lst, start, &n);
	else
		ft_unsigned_length(fparts, arg_lst, start, un);
	return (n);
}
