/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <slyazid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 19:15:16 by slyazid           #+#    #+#             */
/*   Updated: 2019/01/20 23:23:04 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_tot_len_hex(t_format fparts, unsigned long long hex_num,
		int *tot_len, int length)
{
	if (fparts.hash && (fparts.precision || fparts.width) && hex_num)
	{
		if (fparts.hexcaps)
			ft_putstr("0X");
		else
			ft_putstr("0x");
	}
	ft_adjust_precision(fparts, length);
	if (hex_num || (!hex_num && fparts.precision))
		ft_putunsigned_base(hex_num, 16, fparts.hexcaps);
	ft_adjust_width(fparts, tot_len);
	return (*tot_len);
}

void	ft_put_prefixe_hex(t_format fparts, int hex_num)
{
	if (fparts.hash && (fparts.precision || fparts.width) && hex_num)
	{
		if (fparts.hexcaps)
			ft_putstr("0X");
		else
			ft_putstr("0x");
	}
}

int		ft_print_hex(t_format fparts, va_list arg_lst, va_list start)
{
	unsigned long long	hex_num;
	int					length;
	int					tot_len;

	ft_adjust_length(fparts, arg_lst, start, &hex_num);
	length = ft_get_unsize(hex_num, 16);
	(!hex_num && !fparts.precision) ? length-- : 0;
	tot_len = length;
	!fparts.precision && !hex_num ? fparts.zero = 0 : 0;
	if (fparts.precision > length)
		tot_len = fparts.precision;
	if (fparts.hash && (fparts.precision || fparts.width) && hex_num)
		tot_len += 2;
	fparts.hash && !fparts.precision ? fparts.zero = 0 : 0;
	if (fparts.minus)
		return (ft_tot_len_hex(fparts, hex_num, &tot_len, length));
	!fparts.zero || fparts.precision >= 0 ?
		ft_adjust_width(fparts, &tot_len) : 0;
	ft_put_prefixe_hex(fparts, hex_num);
	fparts.zero && fparts.precision < 0 ? ft_adjust_width(fparts, &tot_len) : 0;
	ft_adjust_precision(fparts, length);
	if (hex_num || (!hex_num && fparts.precision))
		ft_putunsigned_base(hex_num, 16, fparts.hexcaps);
	return (tot_len);
}
