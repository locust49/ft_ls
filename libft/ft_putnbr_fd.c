/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzahir <medayoub.zahir@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 21:51:05 by mzahir            #+#    #+#             */
/*   Updated: 2018/10/17 23:57:05 by mzahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	print_digits_fd(long nb, long ten_power, int fd)
{
	while (ten_power > 0)
	{
		if (nb < 0)
		{
			ft_putchar_fd('-', fd);
			nb *= -1;
		}
		ft_putchar_fd((nb / ten_power) + 48, fd);
		nb %= ten_power;
		ten_power /= 10;
	}
}

void		ft_putnbr_fd(int n, int fd)
{
	long	nb2;
	int		ten_power;
	long	casted;

	casted = n;
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
	print_digits_fd(casted, ten_power, fd);
}
