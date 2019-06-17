/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <slyazid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 19:02:38 by slyazid           #+#    #+#             */
/*   Updated: 2019/01/04 16:57:29 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	print_digits(long long nb, long ten_power)
{
	unsigned long long	nbpositive;

	if (nb < 0)
	{
		ft_putchar('-');
		nbpositive = -nb;
	}
	else
		nbpositive = nb;
	while (ten_power > 0)
	{
		ft_putchar((nbpositive / ten_power) + 48);
		nbpositive %= ten_power;
		ten_power /= 10;
	}
}

void		ft_count_nbr(unsigned long long nb, int base, int *i)
{
	unsigned long long	nb2;

	nb2 = nb;
	*i = 1;
	while ((nb2 /= base))
		(*i)++;
	if (base == 10)
	{
		if (!((*i) % 3))
		{
			*i += *i / 3;
			(*i)--;
		}
		else
			*i += *i / 3;
	}
}

char		*ft_convert_deci(unsigned long long nb, int base, int caps)
{
	char				*nbstr;
	int					i;
	int					count;

	ft_count_nbr(nb, base, &i);
	count = 1;
	nbstr = ft_strnew(i);
	while (--i >= 0)
	{
		if (base == 10 && i && !(count % 4))
			nbstr[i] = ',';
		else
		{
			if (nb % base > 9 && caps)
				nbstr[i] = nb % base + 55;
			else if (nb % base > 9)
				nbstr[i] = nb % base + 87;
			else
				nbstr[i] = nb % base + 48;
			nb /= base;
		}
		count++;
	}
	return (nbstr);
}

void		ft_putnbr_base(long long nb, int base, int caps)
{
	unsigned long long	nb2;
	long long			ten_power;
	long long			casted;

	if (base != 10)
		ft_putstr(ft_convert_deci(nb, base, caps));
	else
	{
		casted = nb;
		if (casted < 0)
			nb2 = -casted;
		else
			nb2 = casted;
		ten_power = 1;
		while (nb2 >= 10)
		{
			nb2 /= 10;
			ten_power *= 10;
		}
		print_digits(casted, ten_power);
	}
}

void		ft_putunsigned_base(unsigned long long nb, int base, int caps)
{
	unsigned long long	nb2;
	unsigned long long	ten_power;

	if (base != 10)
		ft_putstr(ft_convert_deci(nb, base, caps));
	else
	{
		nb2 = nb;
		ten_power = 1;
		while (nb2 >= 10)
		{
			nb2 /= 10;
			ten_power *= 10;
		}
		while (ten_power > 0)
		{
			ft_putchar((nb / ten_power) + 48);
			nb %= ten_power;
			ten_power /= 10;
		}
	}
}
