/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzahir <medayoub.zahir@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 14:09:25 by mzahir            #+#    #+#             */
/*   Updated: 2018/10/17 23:43:42 by mzahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int		diff;
	size_t	i;

	i = 0;
	diff = 0;
	while (!diff && *(s1 + i) != '\0' && *(s2 + i) != '\0' && i < n)
	{
		diff = (unsigned char)*(s1 + i) - (unsigned char)*(s2 + i);
		i++;
	}
	if ((*(s1 + i) == '\0' || *(s2 + i) == '\0') && i < n && !diff)
		return ((unsigned char)*(s1 + i) - (unsigned char)*(s2 + i));
	return (diff);
}
