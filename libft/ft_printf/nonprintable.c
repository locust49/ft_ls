/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nonprintable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <slyazid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 02:16:34 by slyazid           #+#    #+#             */
/*   Updated: 2019/01/23 17:24:47 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	ft_equivalent(char a)
{
	int c;

	c = a;
	if (a == 7)
		c = 'a';
	else if (a == 8)
		c = 'b';
	else if (a == 9)
		c = 't';
	else if (a == 10)
		c = 'n';
	else if (a == 11)
		c = 'v';
	else if (a == 12)
		c = 'f';
	else if (a == 13)
		c = 'r';
	else if (a == 27)
		c = 'e';
	return (c);
}

int		ft_count_bs(char *str, int *i)
{
	int	bs;

	*i = 0;
	bs = 0;
	while (str[*i])
		if (str[(*i)++] < 32)
			bs++;
	return (bs);
}

char	*ft_replace_es(char *str)
{
	int		i;
	int		j;
	int		bs;
	char	*str0;

	if ((bs = ft_count_bs(str, &i)))
	{
		j = ft_strlen(str) + bs;
		str0 = ft_strnew(j);
		while (i + 1 > 0)
		{
			str0[j - 1] = ft_equivalent((str)[i - 1]);
			if ((str)[i-- - 1] < 32)
				str0[--j - 1] = 92;
			j--;
		}
		return (str0);
	}
	return (str);
}

char	*ft_nonprintable(char *str)
{
	int		i;
	int		j;
	int		bs;
	char	*c;
	char	*str0;

	str = ft_replace_es(str);
	if (!(bs = ft_count_bs(str, &i)))
		return (str);
	j = ft_strlen(str) + 2 * bs;
	str0 = ft_strnew(j);
	while (i-- > 0)
	{
		if (str[i] < 32)
		{
			c = ft_convert_deci(str[i], 16, 1);
			str0[j-- - 1] = c[ft_strlen(c) - 1];
			str0[j-- - 1] = c[ft_strlen(c) - 2];
			str0[j-- - 1] = 'x';
			c ? ft_memdel((void**)(&c)) : 0;
		}
		else
			str0[j-- - 1] = str[i];
	}
	return (str0);
}

int		ft_print_nonprintable(t_format fparts, va_list arg_lst, va_list start)
{
	char	*s;
	int		length;
	int		tot_len;
	char	*printted;

	s = (fparts.position ?
		ft_findstr_inpos(fparts, start) : va_arg(arg_lst, char *));
	s = ft_nonprintable(s);
	!s ? s = ft_strdup("(null)") : 0;
	length = ft_strlen(ft_nonprintable(s));
	if (fparts.precision >= 0 && fparts.precision < length)
		length = fparts.precision;
	tot_len = length;
	printted = ft_strsub(ft_nonprintable(s), 0, length);
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
