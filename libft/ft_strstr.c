/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzahir <medayoub.zahir@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 14:08:58 by mzahir            #+#    #+#             */
/*   Updated: 2018/10/21 22:17:02 by mzahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	int	i;
	int	j;
	int index;

	i = 0;
	if (*to_find == '\0')
		return ((char*)str);
	while (*(str + i) != '\0')
	{
		if (*to_find == *(str + i))
		{
			index = i;
			j = 0;
			while (*(str + i) == *(to_find + j))
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
