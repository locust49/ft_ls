/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzahir <medayoub.zahir@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 17:37:31 by mzahir            #+#    #+#             */
/*   Updated: 2018/10/17 23:44:35 by mzahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	int		j;
	size_t	ret_size;

	j = 0;
	i = ft_strlen(dest);
	if (!*dest)
		ret_size = ft_strlen(src);
	else if (size < ft_strlen(dest))
		ret_size = ft_strlen(src) + size;
	else
		ret_size = ft_strlen(dest) + ft_strlen(src);
	if (size <= 1)
		return (ret_size);
	while (*(src + j) != '\0' && i < size - 1)
	{
		*(dest + i) = *(src + j);
		i++;
		j++;
	}
	*(dest + i) = '\0';
	return (ret_size);
}
