/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_address.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <slyazid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 17:39:06 by slyazid           #+#    #+#             */
/*   Updated: 2019/01/20 22:42:40 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_print_p(t_format fparts, int length,
			unsigned long address, int *tot_len)
{
	(!(fparts.minus) && !fparts.zero) ? ft_adjust_width(fparts, tot_len) : 0;
	ft_putstr("0x");
	(!(fparts.minus) && fparts.zero) ? ft_adjust_width(fparts, tot_len) : 0;
	ft_adjust_precision(fparts, length);
	if (address || (!address && fparts.precision))
		ft_putnbr_base(address, 16, 0);
}

void	set_address_length(t_format *fparts)
{
	fparts->length.l = 1;
	fparts->length.ll = 0;
	fparts->length.hh = 0;
	fparts->length.h = 0;
}

int		ft_print_address(t_format fparts, va_list arg_lst, va_list start)
{
	unsigned long	address;
	int				length;
	int				tot_len;

	set_address_length(&fparts);
	ft_adjust_length(fparts, arg_lst, start, (unsigned long long*)(&address));
	length = ft_get_size(address, 16);
	if (!address && !fparts.precision)
		length--;
	tot_len = length;
	if (fparts.precision > length)
		tot_len = fparts.precision;
	tot_len += 2;
	if (!fparts.minus)
	{
		ft_print_p(fparts, length, address, &tot_len);
		return (tot_len);
	}
	ft_print_p(fparts, length, address, &tot_len);
	ft_adjust_width(fparts, &tot_len);
	return (tot_len);
}
