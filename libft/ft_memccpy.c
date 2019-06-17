/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzahir <medayoub.zahir@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 15:03:21 by mzahir            #+#    #+#             */
/*   Updated: 2018/10/17 23:08:59 by mzahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*mysrc;
	unsigned char	*mydst;

	i = 0;
	mysrc = (unsigned char*)src;
	mydst = (unsigned char*)dst;
	while (i < n)
	{
		mydst[i] = mysrc[i];
		if (mysrc[i] == (unsigned char)c)
			return (mydst + i + 1);
		i++;
	}
	return (0);
}
