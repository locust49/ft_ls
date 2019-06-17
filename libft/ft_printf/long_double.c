/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_double.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <slyazid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 15:08:13 by slyazid           #+#    #+#             */
/*   Updated: 2019/01/23 17:04:31 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static char	*ft_initialize(char *binary, char **num, char **power, int *i)
{
	int				pos;
	char			*frac;
	unsigned int	size;

	*i = 0;
	while (binary[*i])
	{
		if (binary[*i] - 48)
			pos = *i;
		(*i)++;
	}
	frac = ft_strchr(binary, '.');
	size = (frac ?
	(unsigned int)(binary + ft_strlen(binary) - frac) + 4933
		: 4933 + 63 + 1);
	*num = ft_strnew(size);
	ft_memset(*num, 48, size);
	*power = ft_strnew(size);
	ft_memset(*power, 48, size);
	*i = pos;
	(*num)[4933] = '.';
	return (frac);
}

static void	ft_calculate_power_frac(char *binary, char *power,
			char *frac, int i)
{
	int	j;

	j = (int)(frac - binary);
	ft_memset(power, 48, ft_strlen(power));
	power[i + 4933 - j] = '5';
	while (j < i - 1)
	{
		ft_multiply_strings(power, '5');
		j++;
	}
}

static void	ft_calculate_power_int(char *power, char *num, int i, int *pos)
{
	int	j;

	if (i < *pos)
	{
		if (!(power[4932] - 48))
			power[4932] = '2';
		j = i;
		while (j < *pos - 1)
		{
			ft_multiply_strings(power, '2');
			j++;
		}
		*pos = i + 1;
		ft_add_strings(num, power, 4932);
	}
	else
		num[4932] = '1';
}

static int	ft_calculate_pos_int(char *binary, char *num, int *i)
{
	ft_memset(num, 48, 4933);
	num[4933] = '.';
	(*i) = ft_strlen(binary);
	return ((*i) - 1);
}

char		*get_ldblnum_val(char *binary)
{
	char	*num;
	char	*power;
	int		i;
	int		pos;
	char	*frac;

	if ((frac = ft_initialize(binary, &num, &power, &i)))
	{
		while (binary[i] != '.')
		{
			if (binary[i] - 48)
			{
				ft_calculate_power_frac(binary, power, frac, i);
				ft_add_strings(num, power, i + 4933 - (int)(frac - binary));
			}
			i--;
		}
		pos = (int)(frac - binary) - 1;
	}
	else
		pos = ft_calculate_pos_int(binary, num, &i);
	ft_memset(power, 48, 4933 + 64);
	while (--i >= 0)
		(binary[i] - 48) ? ft_calculate_power_int(power, num, i, &pos) : 0;
	return (num);
}
