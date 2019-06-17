/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjust.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <slyazid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 17:55:42 by slyazid           #+#    #+#             */
/*   Updated: 2019/01/22 12:47:49 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_adjust_width(t_format fparts, int *tot_len)
{
	while ((*tot_len)++ < fparts.width)
		if (fparts.zero && !fparts.minus
				&& (fparts.precision <= 0 || fparts.specifier == 'f'))
			ft_putchar('0');
		else
			ft_putchar(' ');
	(*tot_len)--;
}

void	ft_adjust_precision(t_format fparts, int length)
{
	while (length++ < fparts.precision)
		ft_putchar('0');
}
