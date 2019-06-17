/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_long_double.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <slyazid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 20:29:28 by slyazid           #+#    #+#             */
/*   Updated: 2019/01/23 15:30:41 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static char	*ft_initialize_binary(t_ldnum f, short exponent)
{
	int		size;
	char	*binary;

	size = 65;
	if (exponent < 0)
		size += -exponent;
	else if (exponent > 63)
		size += exponent - 63;
	binary = ft_strnew(size);
	ft_memset(binary, 48, size);
	if (f.mem_rep.m_int)
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

char		*get_ldbl_num(t_ldnum f, short exponent)
{
	int		i;
	char	*num;
	long	cmp;
	char	*binary;

	num = 0;
	binary = ft_initialize_binary(f, exponent);
	cmp = 1;
	i = 65;
	while (--i >= 2)
	{
		if (f.mem_rep.m_frac & cmp)
			binary[i] = '1';
		else
			binary[i] = '0';
		cmp <<= 1;
	}
	set_binary(binary, exponent);
	num = get_ldblnum_val(binary);
	binary ? ft_memdel((void**)(&binary)) : 0;
	return (num);
}
