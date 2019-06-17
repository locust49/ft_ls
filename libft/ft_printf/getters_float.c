/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters_float.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <slyazid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 16:35:59 by slyazid           #+#    #+#             */
/*   Updated: 2019/01/23 15:31:15 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

short	get_dbl_exponent(t_dnum f)
{
	int				i;
	unsigned short	cmp;
	short			exponent;
	char			*binary;

	i = 0;
	cmp = 1 << 10;
	binary = ft_strnew(11);
	while (i < 11)
	{
		if (f.mem_rep.exp & cmp)
			binary[i] = '1';
		else
			binary[i] = '0';
		cmp >>= 1;
		i++;
	}
	exponent = get_binary_val(binary) - 1023;
	binary ? ft_memdel((void**)(&binary)) : 0;
	return (exponent);
}

short	get_ldbl_exponent(t_ldnum f)
{
	int		i;
	short	cmp;
	short	exponent;
	char	*binary;

	i = 0;
	cmp = 1 << 14;
	binary = ft_strnew(15);
	while (i < 15)
	{
		if (f.mem_rep.exp & cmp)
			binary[i] = '1';
		else
			binary[i] = '0';
		cmp >>= 1;
		i++;
	}
	exponent = get_binary_val(binary) - 16383;
	binary ? ft_memdel((void**)(&binary)) : 0;
	return (exponent);
}
