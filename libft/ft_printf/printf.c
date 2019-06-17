/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <slyazid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 12:04:51 by mzahir            #+#    #+#             */
/*   Updated: 2019/01/22 21:55:43 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_handle_last(char **last_arg)
{
	int		length;

	length = 0;
	if (**last_arg)
	{
		while (ft_strchr(*last_arg, '{'))
		{
			length += ft_cut_color(last_arg);
			length += ft_check_eoc(last_arg);
		}
		length += ft_strlen(*last_arg);
		ft_putstr(*last_arg);
	}
	return (length);
}

int		ft_printf(const char *fstr, ...)
{
	va_list	arg_lst;
	va_list	start;
	char	*find_next;
	char	*last_arg;
	int		length;

	length = 0;
	if (!(last_arg = (char *)fstr))
		return (-1);
	va_start(arg_lst, fstr);
	while ((find_next = ft_strchr(last_arg, '%')))
	{
		length += ft_print_nonformatted(last_arg, find_next);
		va_start(start, fstr);
		if (!(last_arg = ft_get_format(find_next, arg_lst, start, &length)))
			return (-1);
	}
	length += ft_handle_last(&last_arg);
	va_end(arg_lst);
	return (length);
}
