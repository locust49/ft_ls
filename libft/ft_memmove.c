/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzahir <medayoub.zahir@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 14:16:32 by mzahir            #+#    #+#             */
/*   Updated: 2018/10/17 23:09:49 by mzahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*dest;
	char	*source;
	char	*endsrc;
	char	*endest;

	dest = (char*)dst;
	source = (char*)src;
	endest = dest + n - 1;
	endsrc = source + n - 1;
	if (source < dest)
	{
		while (endest >= dest)
			*(endest--) = *(endsrc--);
		return (dst);
	}
	while (source <= endsrc)
		*(dest++) = *(source++);
	return (dst);
}
