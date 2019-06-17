/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_float.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <slyazid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 16:53:23 by slyazid           #+#    #+#             */
/*   Updated: 2019/01/23 17:05:30 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static char			*ft_initialize(char *binary, char **num,
						char **power, int *i)
{
	int				pos;
	unsigned int	size;
	char			*frac;

	*i = 0;
	while (binary[*i])
	{
		if (binary[*i] - 48)
			pos = *i;
		(*i)++;
	}
	frac = ft_strchr(binary, '.');
	size = (frac ?
	(unsigned int)(binary + ft_strlen(binary) - frac) + 310 : 362);
	*num = ft_strnew(size);
	ft_memset(*num, 48, size);
	*power = ft_strnew(size);
	ft_memset(*power, 48, size);
	*i = pos;
	(*num)[310] = '.';
	return (frac);
}

static int			ft_calculate_pos_int(char *binary, char *num, int i)
{
	ft_memset(num, 48, 310);
	num[310] = '.';
	i = ft_strlen(binary);
	return (i - 1);
}

static void			ft_calculate_power_frac(char *binary, char *power,
						char *frac, int i)
{
	int	j;

	j = (int)(frac - binary);
	ft_memset(power, 48, ft_strlen(power));
	power[i + 310 - j] = '5';
	while (j < i - 1)
	{
		ft_multiply_strings(power, '5');
		j++;
	}
}

static void			ft_calculate_power_int(char *power, char *num,
						int i, int *pos)
{
	int	j;

	if (i < *pos)
	{
		if (!(power[309] - 48))
			power[309] = '2';
		j = i;
		while (j < *pos - 1)
		{
			ft_multiply_strings(power, '2');
			j++;
		}
		*pos = i + 1;
		ft_add_strings(num, power, 309);
	}
	else
		num[309] = '1';
}

char				*get_float_number(char *binary)
{
	char				*num;
	char				*power;
	int					i;
	int					pos;
	char				*frac;

	if ((frac = ft_initialize(binary, &num, &power, &i)))
	{
		while (binary[i] != '.' && i > 0)
		{
			if (binary[i] - 48)
			{
				ft_calculate_power_frac(binary, power, frac, i);
				ft_add_strings(num, power, i + 310 - (int)(frac - binary));
			}
			i--;
		}
		pos = (int)(frac - binary) - 1;
	}
	else
		pos = ft_calculate_pos_int(binary, num, i);
	ft_memset(power, 48, 362);
	while (--i >= 0)
		(binary[i] - 48) ? ft_calculate_power_int(power, num, i, &pos) : 0;
	return (num);
}
