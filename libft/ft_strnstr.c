/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzahir <medayoub.zahir@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 20:36:18 by mzahir            #+#    #+#             */
/*   Updated: 2018/10/17 21:17:21 by mzahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	int		j;
	int		index;

	i = 0;
	if (*to_find == '\0')
		return ((char*)str);
	while (*(str + i) != '\0' && i < len)
	{
		if (*to_find == *(str + i))
		{
			index = i;
			j = 0;
			while (*(str + i) == *(to_find + j) && i < len)
			{
				if (*(to_find + j + 1) == '\0')
					return ((char*)(str + index));
				i++;
				j++;
			}
			i -= i - index;
		}
		i++;
	}
	return (0);
}
