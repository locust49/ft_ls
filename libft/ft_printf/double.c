/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <slyazid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 19:49:31 by slyazid           #+#    #+#             */
/*   Updated: 2019/01/23 15:29:27 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static char	*ft_initialize_binary(t_dnum f, short exponent)
{
	int		size;
	char	*binary;

	size = 54;
	if (exponent < 0)
		size += -exponent;
	else if (exponent > 52)
		size += exponent - 52;
	binary = ft_strnew(size);
	ft_memset(binary, 48, size);
	if (f.mem_rep.exp)
		binary[0] = '1';
	else
		binary[0] = '0';
	binary[1] = '.';
	return (binary);
}

static void	set_binary(char *binary, short exponent)
{
	int	i;

	if (exponent > 0)
	{
		i = 0;
		while (++i <= exponent)
		{
			binary[i + 1] = binary[i] + binary[i + 1];
			binary[i] = binary[i + 1] - binary[i];
			binary[i + 1] = binary[i + 1] - binary[i];
		}
	}
	else if (exponent < 0)
	{
		exponent *= -1;
		i = ft_strlen(binary);
		while (--i >= exponent)
		{
			if (binary[i - exponent] == '.' && i > exponent)
				exponent++;
			binary[i] = binary[i - exponent] + binary[i];
			binary[i - exponent] = binary[i] - binary[i - exponent];
			binary[i] = binary[i] - binary[i - exponent];
		}
	}
}

char		*get_dbl_num(t_dnum f, short exponent)
{
	int		i;
	char	*num;
	long	cmp;
	char	*binary;

	num = 0;
	cmp = 1;
	i = 54;
	binary = ft_initialize_binary(f, exponent);
	while (--i >= 2)
	{
		if (f.mem_rep.m_frac & cmp)
			binary[i] = '1';
		else
			binary[i] = '0';
		cmp <<= 1;
	}
	set_binary(binary, exponent);
	num = get_float_number(binary);
	binary ? ft_memdel((void**)(&binary)) : 0;
	return (num);
}
