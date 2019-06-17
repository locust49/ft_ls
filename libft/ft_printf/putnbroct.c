/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbroct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <slyazid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 19:02:38 by slyazid           #+#    #+#             */
/*   Updated: 2019/02/01 09:44:27 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void		ft_count_nbr_oct(unsigned int nb, int base, int *i)
{
	unsigned int	nb2;

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

void			ft_putnbr_octal(unsigned int nb)
{
	char				*nbstr;
	int					i;
	int					count;

	ft_count_nbr_oct(nb, 8, &i);
	count = 1;
	nbstr = ft_strnew(i);
	while (--i >= 0)
	{
		nbstr[i] = nb % 8 + 48;
		nb /= 8;
		count++;
	}
	ft_putstr(nbstr);
	nbstr ? ft_memdel((void**)(&nbstr)) : 0;
}
