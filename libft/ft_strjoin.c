/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzahir <medayoub.zahir@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 16:30:37 by mzahir            #+#    #+#             */
/*   Updated: 2018/10/17 21:10:44 by mzahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*join;
	size_t	size;

	if (!s1 || !s2)
		return (0);
	size = ft_strlen((char*)s1) + ft_strlen((char*)s2) + 1;
	if (!(join = (char*)malloc(sizeof(char) * size)))
		return (0);
	i = 0;
	while (*s1)
		join[i++] = *(s1++);
	while (*s2)
		join[i++] = *(s2++);
	join[i] = '\0';
	return (join);
}
