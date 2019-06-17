/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_args_time.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <slyazid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 02:56:13 by slyazid           #+#    #+#             */
/*   Updated: 2019/02/10 03:09:46 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_sort_argsmt(int nargs, char **args, int nops)
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
			if (info2.st_mtimespec.tv_sec > info1.st_mtimespec.tv_sec)
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

int		ft_sort_argsat(int nargs, char **args, int nops)
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
			if (info2.st_atimespec.tv_sec > info1.st_atimespec.tv_sec)
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

int		ft_sort_argsct(int nargs, char **args, int nops)
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
			if (info2.st_ctimespec.tv_sec > info1.st_ctimespec.tv_sec)
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
