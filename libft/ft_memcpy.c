/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzahir <medayoub.zahir@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 23:49:33 by mzahir            #+#    #+#             */
/*   Updated: 2018/10/17 21:32:27 by mzahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	const char	*str;
	char		*dest;

	i = 0;
	str = src;
	dest = dst;
	while (i < n)
	{
		dest[i] = str[i];
		i++;
	}
	return (dst);
}
