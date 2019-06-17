/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <slyazid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 16:30:51 by slyazid           #+#    #+#             */
/*   Updated: 2019/02/10 03:08:55 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_rev_args(int nargs, char **args, int nops)
{
	int		i;
	int		j;
	char	*swapper;

	i = nops;
	j = nargs;
	while (--j > ++i)
	{
		swapper = args[j];
		args[j] = args[i];
		args[i] = swapper;
	}
}

int		ft_sort_argsize(int nargs, char **args, int nops)
{
	int			i;
	char		*swapper;
	struct stat	info1;
	struct stat	info2;

	while (nargs > 1)
	{
		i = nops + 1;
		while (i + 1 < nargs)
		{
			if (stat(args[i + 1], &info2) == -1 || stat(args[i], &info1) == -1)
				return (0);
			if (info2.st_size > info1.st_size)
			{
				swapper = args[i + 1];
				args[i + 1] = args[i];
				args[i] = swapper;
			}
			i++;
		}
		nargs--;
	}
	return (1);
}

void	ft_sort_args(int nargs, char **args, int nops, t_lsdet opts)
{
	struct stat	info;
	int			i;

	i = 1;
	!opts.f ? quick_sort(args, nops + 1, nargs - 1, &ft_strcmp)
			: quick_sort(args, nops + 1, nargs - 1, &ft_alphacmp);
	while (nops + i < nargs && ft_strcmp(args[nops + i], ""))
	{
		if (lstat(args[nops + i], &info) == -1)
			ft_display_error(args[nops + i]);
		i++;
	}
	if (nops + i < nargs && !ft_strcmp(args[nops + i], ""))
	{
		args[i] = ft_strdup("fts_open");
		lstat(args[i], &info);
		ft_display_error(args[i]);
		exit(EXIT_FAILURE);
	}
	opts.t && !opts.u && !opts.c ? ft_sort_argsmt(nargs, args, nops) : 0;
	opts.u ? ft_sort_argsat(nargs, args, nops) : 0;
	opts.c ? ft_sort_argsct(nargs, args, nops) : 0;
	opts.scap ? ft_sort_argsize(nargs, args, nops) : 0;
	opts.r ? ft_rev_args(nargs, args, nops) : 0;
}
