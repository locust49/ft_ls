/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzahir <medayoub.zahir@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 15:38:37 by mzahir            #+#    #+#             */
/*   Updated: 2018/10/17 21:14:24 by mzahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		n;
	char	*str;

	n = 0;
	if (!s)
		return (0);
	while (s[n])
		n++;
	if (!(str = (char*)malloc(sizeof(*str) * (n + 1))))
		return (0);
	i = 0;
	while (i < n)
	{
		str[i] = (*f)((unsigned int)i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
