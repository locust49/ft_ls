/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <slyazid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 23:17:06 by slyazid           #+#    #+#             */
/*   Updated: 2019/01/22 13:00:42 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_initialize(t_format *fparts, t_funcps dispatcher[])
{
	ft_initialize_dispatcher(dispatcher);
	ft_initialize_flags(fparts);
}

void	ft_setters(t_format *fparts, char **frt, va_list arg_lst, va_list start)
{
	while (ft_isflag(*(++(*frt))))
		ft_set_flags(frt, fparts);
	while (ft_iswidth_orprecision(**frt))
		ft_set_width(frt, arg_lst, fparts);
	(**frt == '.') ? ft_set_precision(frt, arg_lst, fparts) : 0;
	(**frt == '$') && ft_deal_dollar(fparts, start, frt) ?
		va_copy(arg_lst, start) : 0;
	((ft_islength(**frt)) ? ft_set_length(frt, fparts) : 0);
}

int		(*ft_print_format(t_format fparts,
		t_funcps dispatcher[]))(t_format, va_list, va_list)
{
	int	i;

	i = -1;
	while (++i < 11)
		while (*(dispatcher[i].specifiers))
			if (fparts.specifier == *(dispatcher[i].specifiers++))
				return (dispatcher[i].funcp);
	return (0);
}

void	ft_adjust_form(t_format *fparts, char *frt,
	va_list arg_lst, va_list arg_lst2)
{
	fparts->specifier = *frt;
	((*frt == 'D' || *frt == 'O' || *frt == 'U') ? fparts->length.l = 1 : 0);
	if (*frt == 'D')
		if (!fparts->length.h && !fparts->length.hh && !fparts->length.ll)
			fparts->specifier = 'd';
	((*frt == 'X') ? fparts->hexcaps = 1 : 0);
	va_copy(arg_lst2, arg_lst);
}

char	*ft_get_format(char *frt, va_list arg_lst, va_list start, int *length)
{
	int			(*funcp)(t_format, va_list, va_list);
	int			ret_val;
	t_format	fparts;
	va_list		arg_lst2;
	t_funcps	dispatcher[11];

	ft_initialize(&fparts, dispatcher);
	ft_setters(&fparts, &frt, arg_lst, start);
	if (ft_isspecifier(*frt))
	{
		ft_adjust_form(&fparts, frt, arg_lst, arg_lst2);
		if (!(funcp = ft_print_format(fparts, dispatcher)))
			*length += ft_print_notspeci(fparts, *frt);
		else if ((ret_val = (*funcp)(fparts, arg_lst2, start)) < 0)
			return (0);
		else
			*length += ret_val;
		frt++;
		va_copy(arg_lst, arg_lst2);
	}
	else if (*frt && fparts.width)
		*length += ft_print_notspeci(fparts, *(frt++));
	return (frt);
}
