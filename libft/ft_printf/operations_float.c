/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_float.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <slyazid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 16:56:02 by slyazid           #+#    #+#             */
/*   Updated: 2019/01/23 17:05:14 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_round_even(char **num, char *to_add, int last_digit, int nth_place)
{
	int		i;

	i = nth_place;
	while ((*num)[++i])
		if ((*num)[i] - 48)
			return (ft_add_strings(*num, to_add, last_digit));
	if (((*num)[last_digit] - 48) % 2 && (*num)[last_digit] != 0)
		return (ft_add_strings(*num, to_add, last_digit));
	return (1);
}

int		ft_round_number(char **num, int precision)
{
	int		nth_place;
	int		last_digit;
	char	*to_add;
	int		ret;

	ret = 1;
	last_digit = (int)(ft_strchr(*num, '.') - *num) + precision;
	nth_place = last_digit + 1;
	(!precision) ? last_digit-- : 0;
	to_add = ft_strnew(last_digit + 1);
	ft_memset(to_add, 48, last_digit);
	to_add[last_digit] = '1';
	if ((*num)[nth_place] > '5')
		ret = ft_add_strings(*num, to_add, last_digit);
	else if ((*num)[nth_place] == '5')
		ret = ft_round_even(num, to_add, last_digit, nth_place);
	return (ret);
}

void	ft_multiply_strings(char *num, char multiplier)
{
	int		i;
	int		this_mul;
	int		res;
	int		carry;

	i = ft_strlen(num);
	this_mul = multiplier - 48;
	carry = 0;
	while (--i >= 0)
	{
		res = this_mul * (num[i] - 48) + carry;
		num[i] = res % 10 + 48;
		carry = res / 10;
	}
}

int		ft_add_strings(char *num, char *to_add, int pos)
{
	int res;
	int	carry;

	carry = 0;
	while (pos >= 0)
	{
		if (num[pos] != '.' && to_add[pos] != '.')
		{
			res = num[pos] - 48 + to_add[pos] - 48 + carry;
			num[pos] = res % 10 + 48;
			carry = res / 10;
		}
		pos--;
	}
	return (0);
}
