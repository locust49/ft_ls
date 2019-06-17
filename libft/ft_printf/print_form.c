/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_form.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <slyazid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 18:27:02 by slyazid           #+#    #+#             */
/*   Updated: 2019/01/20 23:23:05 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_handle_spnplus(t_format fparts)
{
	if (fparts.plus)
		ft_putchar('+');
	else if (fparts.space)
		ft_putchar(' ');
}

void	ft_put_minus(long long n, unsigned long long *un)
{
	ft_putchar('-');
	*un = -n;
}

int		ft_print_notspeci(t_format fparts, char c)
{
	int	tot_len;

	tot_len = 1;
	fparts.precision >= 0 ? fparts.precision = -1 : 0;
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
