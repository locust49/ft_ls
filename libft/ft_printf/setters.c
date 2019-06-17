/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <slyazid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 17:22:52 by slyazid           #+#    #+#             */
/*   Updated: 2019/01/18 12:49:35 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_initialize_flags(t_format *fparts)
{
	fparts->position = 0;
	fparts->hash = 0;
	fparts->plus = 0;
	fparts->space = 0;
	fparts->zero = 0;
	fparts->minus = 0;
	fparts->width = 0;
	fparts->precision = -1;
	fparts->length.h = 0;
	fparts->length.hh = 0;
	fparts->length.l = 0;
	fparts->length.ll = 0;
	fparts->length.lcap = 0;
	fparts->apostrophe = 0;
	fparts->hexcaps = 0;
	fparts->asterisk = 0;
}

void	ft_set_flags(char **format, t_format *fparts)
{
	if (**format == '#')
		fparts->hash = 1;
	else if (**format == '0')
		fparts->zero = 1;
	else if (**format == '-')
		fparts->minus = 1;
	else if (**format == '+')
		fparts->plus = 1;
	else if (**format == ' ')
		fparts->space = 1;
	else if (**format == '\'')
		fparts->apostrophe = 1;
}

void	ft_set_width(char **format, va_list arg_lst, t_format *fparts)
{
	if (ft_isdigit(**format))
	{
		fparts->width = ft_atoi(ft_strdup(*format));
		while (ft_isdigit(**format))
			(*format)++;
	}
	if (**format == '*')
	{
		fparts->asterisk = 1;
		if ((fparts->width = va_arg(arg_lst, int)) < 0)
		{
			fparts->minus = 1;
			fparts->width *= -1;
		}
		(*format)++;
	}
}

void	ft_set_precision(char **format, va_list arg_lst, t_format *fparts)
{
	if (ft_iswidth_orprecision(*(*format + 1)))
	{
		if (ft_isdigit(*(*format + 1)))
		{
			fparts->precision = ft_atoi(++(*format));
			while (ft_isdigit(**format))
				(*format)++;
		}
		if (*(*format + 1) == '*' || **format == '*')
		{
			fparts->precision = va_arg(arg_lst, int);
			*format = ft_strchr(*format, '*') + 1;
		}
	}
	else
	{
		fparts->precision = 0;
		(*format)++;
	}
}

void	ft_set_length(char **format, t_format *fparts)
{
	if (**format == 'h' && *(*format + 1) == 'h')
	{
		fparts->length.hh = 1;
		(*format)++;
	}
	else if ((**format == 'l' && *(*format + 1) == 'l')
				|| **format == 'z' || **format == 'j')
	{
		fparts->length.ll = 1;
		**format == 'l' ? (*format)++ : 0;
	}
	else if (**format == 'h')
		fparts->length.h = 1;
	else if (**format == 'l')
		fparts->length.l = 1;
	else if (**format == 'L')
		fparts->length.lcap = 1;
	(*format)++;
}
