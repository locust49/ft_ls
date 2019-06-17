/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <slyazid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 15:55:00 by mzahir            #+#    #+#             */
/*   Updated: 2019/02/15 11:39:45 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		get_tab_size(int max_len)
{
	int		size;

	size = 0;
	if (!(max_len % 8))
		return (8);
	while (max_len++ % 8)
		size++;
	return (size);
}

int		get_max_len(t_args *lst)
{
	size_t	max;

	max = 0;
	while (lst)
	{
		if (max < lst->len)
			max = lst->len;
		lst = lst->next;
	}
	return (max);
}

t_args	*get_item_inpos(t_args *list, int step, int init)
{
	static t_args	**lsttab;
	static int		size;
	static int		pos;
	static int		i;

	if (init)
	{
		lsttab ? free(lsttab) : 0;
		size = step;
		lsttab = (t_args**)malloc(sizeof(t_args*) * size);
		i = 0;
		while (list)
		{
			lsttab[i++] = list;
			list = list->next;
		}
		i = 0;
		pos = 0;
	}
	else
		pos += step;
	if (pos < size)
		return (lsttab[pos]);
	pos = ++i;
	return (0);
}

int		get_list_length(t_args *list)
{
	int	len;

	len = 0;
	while (list)
	{
		len++;
		list = list->next;
	}
	return (len);
}
