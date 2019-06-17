/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzahir <medayoub.zahir@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 16:10:06 by mzahir            #+#    #+#             */
/*   Updated: 2018/10/17 21:23:06 by mzahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*substr;

	i = 0;
	if (!s)
		return (0);
	s += start;
	if (!(substr = (char*)malloc(sizeof(char) * (len + 1))))
		return (0);
	while (i < len)
	{
		*(substr + i) = *(s + i);
		i++;
	}
	*(substr + i) = '\0';
	return (substr);
}
