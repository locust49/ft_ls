/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_chars_strings.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <slyazid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 22:23:58 by slyazid           #+#    #+#             */
/*   Updated: 2019/01/23 17:25:34 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_findstr_inpos(t_format fparts, va_list start)
{
	int		i;
	char	*arg_inpos;

	i = 1;
	while (i <= fparts.position)
	{
		arg_inpos = va_arg(start, char *);
		i++;
	}
	return (arg_inpos);
}

int		ft_print_chars(t_format fparts, va_list arg_lst, va_list start)
{
	char	c;
	int		tot_len;

	if (fparts.specifier == 'C' || fparts.length.l)
		return (ft_print_unicode(fparts, arg_lst, start));
	c = ft_adjust_length(fparts, arg_lst, start, (unsigned long long*)&c);
	tot_len = 1;
	if (fparts.minus)
	{
		ft_putchar(c);
		ft_adjust_width(fparts, &tot_len);
	}
	else
	{
		ft_adjust_width(fparts, &tot_len);
		ft_putchar(c);
	}
	return (tot_len);
}

int		ft_print_strings(t_format fparts, va_list arg_lst, va_list start)
{
	char	*s;
	int		tot_len;
	char	*printted;

	if (fparts.specifier == 'S' || fparts.length.l)
		return (ft_print_unicodestr(fparts, arg_lst, start));
	s = (fparts.position ?
		ft_findstr_inpos(fparts, start) : va_arg(arg_lst, char *));
	!s ? s = ft_strdup("(null)") : 0;
	tot_len = ft_strlen(s);
	fparts.precision >= 0 && fparts.precision < tot_len ?
		tot_len = fparts.precision : 0;
	printted = ft_strsub(s, 0, tot_len);
	if (fparts.minus)
	{
		ft_putstr(printted);
		ft_adjust_width(fparts, &tot_len);
		return (tot_len);
	}
	ft_adjust_width(fparts, &tot_len);
	ft_putstr(printted);
	return (tot_len);
}
