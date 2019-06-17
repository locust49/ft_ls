/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_input_time.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <slyazid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 02:58:35 by slyazid           #+#    #+#             */
/*   Updated: 2019/02/10 03:09:15 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_time_mcmp(const char *item1, const char *item2)
{
	struct stat	info1;
	struct stat	info2;

	lstat(item2, &info2);
	lstat(item1, &info1);
	if (info2.st_mtimespec.tv_sec > info1.st_mtimespec.tv_sec)
		return (1);
	if (info2.st_mtimespec.tv_sec < info1.st_mtimespec.tv_sec)
		return (-1);
	return (0);
}

int		ft_time_acmp(const char *item1, const char *item2)
{
	struct stat	info1;
	struct stat	info2;

	lstat(item2, &info2);
	lstat(item1, &info1);
	if (info2.st_atimespec.tv_sec > info1.st_atimespec.tv_sec)
		return (1);
	if (info2.st_atimespec.tv_sec + info2.st_atimespec.tv_nsec
		< info1.st_atimespec.tv_sec + info1.st_atimespec.tv_nsec)
		return (-1);
	return (0);
}

int		ft_time_ccmp(const char *item1, const char *item2)
{
	struct stat	info1;
	struct stat	info2;

	lstat(item2, &info2);
	lstat(item1, &info1);
	if (info2.st_ctimespec.tv_sec > info1.st_ctimespec.tv_sec)
		return (1);
	if (info2.st_ctimespec.tv_sec + info2.st_ctimespec.tv_nsec
		< info1.st_ctimespec.tv_sec + info1.st_ctimespec.tv_nsec)
		return (-1);
	return (0);
}
