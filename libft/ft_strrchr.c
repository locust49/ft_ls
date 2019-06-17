/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzahir <medayoub.zahir@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 14:59:36 by mzahir            #+#    #+#             */
/*   Updated: 2018/10/17 23:49:11 by mzahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *last_occur;

	last_occur = 0;
	if (!ft_isascii(c) || (c && !*s))
		return (0);
	while (*s)
	{
		if (*s == (char)c)
			last_occur = (char*)s;
		s++;
	}
	if (!c)
		return ((char*)s);
	if (last_occur)
		return (last_occur);
	return (0);
}
