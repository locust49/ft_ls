/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <slyazid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 18:01:23 by slyazid           #+#    #+#             */
/*   Updated: 2019/01/23 17:23:41 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_fparts_value(t_format *fparts, int w, int p, int l)
{
	int	number_pos;

	number_pos = 0;
	(fparts->width) ? number_pos = fparts->width : 0;
	(fparts->precision > 0) ? number_pos = fparts->precision : 0;
	fparts->width = w;
	fparts->precision = p;
	fparts->length.h = l;
	fparts->length.hh = l;
	fparts->length.ll = l;
	fparts->length.l = l;
	return (number_pos);
}

int		ft_ret_isspecifier(t_format *fparts, int number_pos, va_list start)
{
	fparts->position = number_pos;
	fparts->width = ft_find_inpos(*fparts, start);
	fparts->position = 0;
	return (1);
}

int		ft_read_width(char *format_dup)
{
	int		ret_val;

	ret_val = ft_atoi(format_dup);
	return (ret_val);
}

int		ft_ret_isdigit(t_format *fparts, char **format, int number_pos,
			va_list start)
{
	(*format)++;
	fparts->position = ft_read_width(ft_strdup(*format));
	if ((fparts->width = ft_find_inpos(*fparts, start)) < 0)
	{
		fparts->minus = 1;
		fparts->width *= -1;
	}
	fparts->position = number_pos;
	while (ft_isdigit(**format))
		(*format)++;
	if (**format != '$')
	{
		fparts->width = fparts->position;
		fparts->position = 0;
	}
	if (ft_isdigit(**format))
	{
		fparts->width = ft_read_width(ft_strdup(*format));
		while (ft_isdigit(**format))
			(*format)++;
	}
	(*format)++;
	return (1);
}

int		ft_deal_dollar(t_format *fparts, va_list start, char **format)
{
	va_list	first;
	int		ret_val;
	int		number_pos;

	va_copy(first, start);
	number_pos = ft_fparts_value(fparts, 0, -1, 0);
	while (ft_isflag(*(++(*format))))
		ft_set_flags(format, fparts);
	if (fparts->asterisk || (**format == '*' && ft_isspecifier(*(*format + 1))))
	{
		ret_val = ft_ret_isspecifier(fparts, number_pos, start);
		((!ft_isspecifier(**format)) ? (*format)++ : va_copy(start, first));
		return (ret_val);
	}
	else if (**format == '*' && ft_isdigit(*(*(format) + 1)))
	{
		ret_val = ft_ret_isdigit(fparts, format, number_pos, start);
		va_copy(start, first);
		return (ret_val);
	}
	while (ft_iswidth_orprecision(**format))
		ft_set_width(format, 0, fparts);
	(**format == '.') ? ft_set_precision(format, 0, fparts) : 0;
	fparts->position = number_pos;
	return (0);
}
