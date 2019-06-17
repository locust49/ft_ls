/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <slyazid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 18:50:15 by mzahir            #+#    #+#             */
/*   Updated: 2019/02/13 13:24:35 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	initialize_tab(char **tab, int nops, int nargs)
{
	char	*swap;
	int		mid;
	int		fst;
	int		last;

	fst = nops + 1;
	last = nargs - 1;
	mid = fst + (last - fst) / 2;
	swap = tab[last];
	if (ft_strcmp(tab[fst], tab[mid]) > 0 && ft_strcmp(tab[fst], swap) > 0)
	{
		tab[last] = tab[fst];
		tab[fst] = swap;
	}
	else if (ft_strcmp(tab[mid], tab[fst]) > 0 && ft_strcmp(tab[mid], swap) > 0)
	{
		tab[last] = tab[mid];
		tab[mid] = swap;
	}
	swap = tab[mid];
	if (ft_strcmp(tab[fst], swap) > 0)
	{
		tab[mid] = tab[fst];
		tab[fst] = swap;
	}
}

void	swap(char **str1, char **str2)
{
	char	*swapper;

	swapper = *str1;
	*str1 = *str2;
	*str2 = swapper;
}

int		partition(char **argv, int left, int right,
					int (*ft_cmpfunc)(const char *, const char *))
{
	char	*pivot;
	char	*pivpath;

	pivot = argv[left + (right - left) / 2];
	pivpath = ft_strjoin("./", pivot);
	while (left <= right)
	{
		while (ft_cmpfunc(ft_strjoin("./", argv[left]), pivpath) < 0)
			left++;
		while (ft_cmpfunc(ft_strjoin("./", argv[right]), pivpath) > 0)
			right--;
		if (left <= right)
		{
			swap(argv + left, argv + right);
			left++;
			right--;
		}
	}
	return (left);
}

void	quick_sort(char **argv, int left, int right,
					int (*ft_cmpfunc)(const char *, const char *))
{
	int		i;
	int		j;

	if (left >= right)
		return ;
	i = partition(argv, left, right, ft_cmpfunc);
	j = 0;
	quick_sort(argv, left, i - 1, ft_cmpfunc);
	quick_sort(argv, i, right, ft_cmpfunc);
}
