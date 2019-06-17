/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <slyazid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 12:44:20 by slyazid           #+#    #+#             */
/*   Updated: 2019/01/18 13:24:59 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int				ft_isuniformat(char *fmt, va_list arg_lst)
{
	wchar_t	*str;
	va_list	arg_lst2;
	int		cnt;

	cnt = 0;
	va_copy(arg_lst2, arg_lst);
	if (!(str = va_arg(arg_lst2, wchar_t *)))
		return (0);
	while (*(++fmt))
	{
		if (!ft_isspecifier(*fmt) && *fmt != 'l')
			cnt++;
		else
			break ;
	}
	return (cnt && (*fmt == 'S' || (*fmt == 's' && *(fmt - 1) == 'l')) ? 1 : 0);
}

int				get_unistr_len(wchar_t *unistr)
{
	int	length;
	int	i;

	length = 0;
	while (*unistr)
	{
		if (set_utf8(*unistr, &i) == 0xFFFFFF)
			return (-1);
		length += i;
		unistr++;
	}
	return (length);
}

int				get_unirealprecision(wchar_t *unistr, int precision)
{
	int	i;
	int	len;

	len = 0;
	while (*unistr)
	{
		set_utf8(*unistr, &i);
		if (len + i > precision)
			return (len);
		len += i;
		unistr++;
	}
	return (len);
}

int				ft_set_unicode(wchar_t c, unsigned int *wchar)
{
	int	nbytes;

	nbytes = 1;
	if (c > 0x10FFFF)
		return (0xFFFFFF);
	(c <= 0x10FFFF) ? (*wchar = 0xF0808080) : 0;
	(c <= 0xFFFF) ? (*wchar = 0xE08080) : 0;
	(c <= 0x7FF) ? (*wchar = 0xC080) : 0;
	(c <= 0x7F) ? (*wchar = 0x0) : 0;
	(c > 0xFFFF) ? (nbytes++) : 0;
	(c > 0x7FF) ? (nbytes++) : 0;
	(c > 0x7F) ? (nbytes++) : 0;
	return (nbytes);
}

unsigned int	set_utf8(wchar_t c, int *i)
{
	int				nbytes;
	unsigned int	wchar;
	unsigned char	*byte;

	nbytes = ft_set_unicode(c, &wchar);
	*i = 0;
	byte = (unsigned char *)(&wchar) + nbytes - 1;
	while (nbytes > 0)
	{
		*byte |= (c >> (6 * (--nbytes)));
		if (*i && (*byte & 0x40))
			*byte ^= 0x40;
		if (nbytes && !*i && (*byte & (0x80 >> (nbytes + 1))))
			*byte ^= (0x80 >> (nbytes + 1));
		byte--;
		(*i)++;
	}
	return (wchar);
}
