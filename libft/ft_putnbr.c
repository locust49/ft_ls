/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzahir <medayoub.zahir@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 21:49:50 by mzahir            #+#    #+#             */
/*   Updated: 2018/10/17 23:56:38 by mzahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	print_digits(long nb, long ten_power)
{
	while (ten_power > 0)
	{
		if (nb < 0)
		{
			ft_putchar('-');
			nb *= -1;
		}
		ft_putchar((nb / ten_power) + 48);
		nb %= ten_power;
		ten_power /= 10;
	}
}

void		ft_putnbr(int nb)
{
	long	nb2;
	int		ten_power;
	long	casted;

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
