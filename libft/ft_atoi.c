/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzahir <medayoub.zahir@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 14:06:30 by mzahir            #+#    #+#             */
/*   Updated: 2018/10/17 23:55:21 by mzahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_not_a_number(char c)
{
	if (c >= '0' && c <= '9')
		return (0);
	else
		return (1);
}

static int	ft_check_start(char *str)
{
	int i;

	i = 0;
	while (*(str + i) == ' '
			|| *(str + i) == '\n'
			|| *(str + i) == '\t'
			|| *(str + i) == '\r'
			|| *(str + i) == '\f'
			|| *(str + i) == '\v')
		i++;
	if (*(str + i) == '+' || *(str + i) == '-')
		i++;
	return (i);
}

int			ft_atoi(const char *str)
{
	int				i;
	unsigned long	biggest;
	int				sign;

	sign = 0;
	biggest = 0;
	i = ft_check_start((char*)str);
	if (*(str + i - 1) == '-')
		sign = 1;
	while (*(str + i) != '\0' && ft_not_a_number(*(str + i)) == 0)
	{
		if (biggest == 0)
			biggest = *(str + i) - 48;
		else
			biggest = (biggest * 10) + *(str + i) - 48;
		i++;
	}
	if (sign)
		return ((int)-biggest);
	return ((int)biggest);
}
