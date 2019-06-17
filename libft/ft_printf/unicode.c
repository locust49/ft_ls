/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <slyazid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 13:18:38 by mzahir            #+#    #+#             */
/*   Updated: 2019/01/21 19:43:19 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

wint_t			ft_findunicode_inpos(t_format fparts, va_list start)
{
	int		i;
	wint_t	arg_inpos;

	i = 1;
	while (i <= fparts.position)
	{
		arg_inpos = va_arg(start, wint_t);
		i++;
	}
	return (arg_inpos);
}

int				ft_print_unicode(t_format fparts,
					va_list arg_lst, va_list start)
{
	int				tot_len;
	int				i;
	unsigned char	*byte;
	unsigned int	wchar;
	wchar_t			c;

	c = (fparts.position ?
	ft_findunicode_inpos(fparts, start) : va_arg(arg_lst, wint_t));
	if (c && MB_CUR_MAX != 4)
		return (-1);
	byte = (unsigned char *)(&c);
	if ((wchar = set_utf8(c, &i)) == 0xFFFFFF)
		return (-1);
	byte = (unsigned char *)(&wchar);
	tot_len = i;
	fparts.minus ? 0 : ft_adjust_width(fparts, &tot_len);
	while (--i >= 0)
		ft_putchar(byte[i]);
	fparts.minus ? ft_adjust_width(fparts, &tot_len) : 0;
	return (tot_len);
}

int				ft_put_unistr(wchar_t *unistr, int nchars)
{
	unsigned char	*byte;
	unsigned int	wchar;
	int				length;
	int				i;

	length = 0;
	while (*unistr)
	{
		if ((wchar = set_utf8(*unistr, &i)) == 0xFFFFFF)
			return (-1);
		if (length + i > nchars)
			return (length);
		length += i;
		byte = (unsigned char *)(&wchar);
		while (--i >= 0)
			ft_putchar(byte[i]);
		unistr++;
	}
	return (nchars < length ? -1 : length);
}

wchar_t			*ft_findunistr_inpos(t_format fparts, va_list start)
{
	int		i;
	wchar_t	*arg_inpos;

	i = 1;
	while (i <= fparts.position)
	{
		arg_inpos = va_arg(start, wchar_t *);
		i++;
	}
	return (arg_inpos);
}

int				ft_print_unicodestr(t_format fparts,
					va_list arg_lst, va_list start)
{
	wchar_t	*s;
	int		length;
	int		tot_len;

	s = fparts.position ?
		ft_findunistr_inpos(fparts, start) : va_arg(arg_lst, wchar_t *);
	if (!s)
		s = L"(null)";
	else if (MB_CUR_MAX != 4)
		return (-1);
	if ((length = get_unistr_len(s)) < 0)
		return (-1);
	if (fparts.precision >= 0 && fparts.precision < length)
		length = get_unirealprecision(s, fparts.precision);
	tot_len = length;
	if (fparts.minus)
	{
		if ((ft_put_unistr(s, length)) < 0)
			return (-1);
		ft_adjust_width(fparts, &tot_len);
		return (tot_len);
	}
	ft_adjust_width(fparts, &tot_len);
	return (ft_put_unistr(s, length) < 0 ? -1 : tot_len);
}
