/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzahir <medayoub.zahir@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 20:50:30 by mzahir            #+#    #+#             */
/*   Updated: 2018/10/17 23:09:35 by mzahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	int				diff;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	diff = 0;
	str1 = (unsigned char*)s1;
	str2 = (unsigned char*)s2;
	while (!diff && i < n)
	{
		diff = *(str1 + i) - *(str2 + i);
		i++;
	}
	return (diff);
}
