/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzahir <mzahir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 17:41:53 by slyazid           #+#    #+#             */
/*   Updated: 2019/02/12 20:05:03 by mzahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_get_size(long long n, int base)
{
	int i;

	i = 1;
	while ((n /= base))
		i++;
	return (i);
}

int		ft_get_unsize(unsigned long long n, int base)
{
	int i;

	i = 1;
	while ((n /= base))
		i++;
	return (i);
}

double	get_binary_val(char *binary)
{
	double	n;
	double	multiplier;
	int		i;
	int		j;

	n = 0;
	multiplier = 1;
	i = ft_strlen(binary);
	j = 0;
	while (--i >= 0)
	{
		n += (double)(binary[i] - 48) * multiplier;
		multiplier *= 2;
		j++;
	}
	return (n);
}

int		ft_get_float_size(double num)
{
	int	size;

	size = 0;
	while ((int)(num / (double)10))
	{
		num /= 10;
		size++;
	}
	return (size);
}
