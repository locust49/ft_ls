/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzahir <medayoub.zahir@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 14:08:00 by mzahir            #+#    #+#             */
/*   Updated: 2018/10/17 23:44:08 by mzahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	char	*dup;

	i = 0;
	while (*(src + i) != '\0')
		i++;
	dup = (char*)malloc(sizeof(char) * (i + 1));
	if (dup == NULL)
		return (0);
	i = 0;
	while (*(src + i) != 0)
	{
		*(dup + i) = *(src + i);
		i++;
	}
	*(dup + i) = '\0';
	return (dup);
}
