/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzahir <medayoub.zahir@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 16:43:55 by mzahir            #+#    #+#             */
/*   Updated: 2018/10/17 21:56:00 by mzahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*trimmed;
	int		i;
	int		j;
	int		n;

	i = 0;
	if (!s)
		return (0);
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	if (!s[i])
		return (ft_strdup(""));
	n = ft_strlen((char*)s) - 1;
	while (*(s + n) == ' ' || *(s + n) == '\t' || *(s + n) == '\n')
		n--;
	if (!(trimmed = (char*)malloc(sizeof(char) * (n - i + 2))))
		return (0);
	j = 0;
	while (i <= n)
		trimmed[j++] = (char)s[i++];
	trimmed[j] = '\0';
	return (trimmed);
}
