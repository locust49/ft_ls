/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_tolst.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzahir <medayoub.zahir@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 14:15:08 by mzahir            #+#    #+#             */
/*   Updated: 2018/10/18 21:27:13 by mzahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_create_word(char const *s, char c, t_word *words_list)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	if (!(words_list->word = (char*)malloc(sizeof(char) * (i + 1))))
		return ;
	if (!(words_list->next = (t_word*)malloc(sizeof(t_word))))
		return ;
}

static void	ft_splitter_tolst(char const *s, char c, t_word *words_list)
{
	int		i;
	int		j;
	t_word	*link;

	link = words_list;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			if (link->word)
				link = link->next;
			ft_create_word(&s[i], c, link);
			if (!words_list->word || !words_list->next)
				return ;
			j = 0;
			while (s[i] != c && s[i])
				link->word[j++] = s[i++];
			link->word[j] = '\0';
			if (!s[i])
				break ;
		}
		i++;
	}
	ft_memdel((void**)&(link->next));
}

t_word		*ft_strsplit_tolst(char const *s, char c)
{
	t_word	*words_list;

	if (!s)
		return (0);
	if (!(words_list = (t_word*)malloc(sizeof(t_word))))
		return (0);
	words_list->word = 0;
	ft_splitter_tolst(s, c, words_list);
	if (!words_list)
		return (0);
	else
		return (words_list);
}
