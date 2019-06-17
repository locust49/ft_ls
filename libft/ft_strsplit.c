/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzahir <medayoub.zahir@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 17:14:09 by mzahir            #+#    #+#             */
/*   Updated: 2018/10/17 23:58:48 by mzahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(const char *s, char c)
{
	int	i;
	int	count_words;

	i = 0;
	count_words = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count_words++;
			while (s[i] != c && s[i])
				i++;
			if (!s[i])
				break ;
		}
		i++;
	}
	return (count_words);
}

static char	**ft_splitter(char const *s, char c, char **splitted, int i)
{
	int j;
	int nword;

	nword = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			j = i;
			while (s[i] != c && s[i])
				i++;
			if (!(splitted[nword] = (char*)malloc(sizeof(char) * (i - j + 1))))
				return (0);
			i = j;
			j = 0;
			while (s[i] != c && s[i])
				splitted[nword][j++] = s[i++];
			splitted[nword++][j] = '\0';
			if (!s[i])
				break ;
		}
		i++;
	}
	splitted[nword] = 0;
	return (splitted);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**splitted;

	if (!s)
		return (0);
	splitted = (char**)malloc(sizeof(char*) * (ft_count_words(s, c) + 1));
	if (!splitted)
		return (0);
	if (!(splitted = ft_splitter(s, c, splitted, 0)))
		return (0);
	else
		return (splitted);
}
