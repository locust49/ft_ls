/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzahir <medayoub.zahir@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 18:32:42 by mzahir            #+#    #+#             */
/*   Updated: 2018/10/17 23:55:53 by mzahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_fill_str(unsigned int num, char *str, int i)
{
	if (num == 0)
		str[0] = '0';
	while (num)
	{
		str[i] = num % 10 + 48;
		num /= 10;
		i--;
	}
	if (i == 0 && str[1])
		str[0] = '-';
}

char		*ft_itoa(int n)
{
	char			*str;
	int				i;
	int				sign;
	unsigned int	num;
	unsigned int	temp;

	i = 0;
	sign = 0;
	if (n < 0)
	{
		num = -n;
		sign++;
	}
	else
		num = n;
	temp = num;
	while (temp /= 10)
		i++;
	if (sign)
		i++;
	if (!(str = (char*)malloc(sizeof(char) * ((++i) + 1))))
		return (0);
	str[i--] = '\0';
	ft_fill_str(num, str, i);
	return (str);
}
