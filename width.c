/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzahir <mzahir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 03:50:17 by slyazid           #+#    #+#             */
/*   Updated: 2019/02/12 21:52:30 by mzahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_width_ownership(t_width *max, t_lsdet opts, struct stat info,
		t_ownership *owners)
{
	owners->pw = getpwuid(info.st_uid);
	owners->gp = getgrgid(info.st_gid);
	if (!opts.n)
	{
		if (owners->pw->pw_name
			&& ft_strlen(owners->pw->pw_name) > owners->max_pw)
			owners->max_pw = ft_strlen(owners->pw->pw_name);
		else if (!owners->pw->pw_name && owners->pw->pw_uid > max->usr)
			max->usr = owners->pw->pw_uid;
		if (owners->gp->gr_name
			&& ft_strlen(owners->gp->gr_name) > owners->max_gp)
			owners->max_gp = ft_strlen(owners->gp->gr_name);
		else if (!owners->gp->gr_name)
			max->grp = owners->gp->gr_gid;
	}
	else
	{
		owners->pw->pw_uid > owners->max_pw ? max->usr = owners->pw->pw_uid : 0;
		owners->gp->gr_gid > owners->max_gp ? max->grp = owners->gp->gr_gid : 0;
	}
}

void	ft_width_major_minor(t_width *max, struct stat info)
{
	if ((S_ISBLK(info.st_mode) || S_ISCHR(info.st_mode))
		&& major(info.st_rdev) > max->maj)
		max->maj = major(info.st_rdev);
	if ((S_ISBLK(info.st_mode) || S_ISCHR(info.st_mode))
		&& minor(info.st_rdev) > max->min)
		max->min = minor(info.st_rdev);
}

void	ft_width_xatt_lnk(char *path, t_width *max, struct stat info)
{
	ssize_t	xatt;

	xatt = (listxattr(path, NULL, 0, XATTR_NOFOLLOW) > 0) ? 1 : 0;
	xatt > max->xatt ? max->xatt = xatt : 0;
	info.st_nlink > max->lnk ? max->lnk = info.st_nlink : 0;
	info.st_size > max->size ? max->size = info.st_size : 0;
}

void	get_width(t_width *width, t_width max, t_ownership owners)
{
	width->xatt = max.xatt;
	width->lnk = ft_get_size(max.lnk, 10);
	width->size = ft_get_size(max.size, 10);
	max.maj ? width->maj = ft_get_size(max.maj, 10) : 0;
	max.min ? width->min = ft_get_size(max.min, 10) : 0;
	!owners.max_pw ? width->usr = ft_get_size(max.usr, 10)
						: (width->usr = owners.max_pw);
	!owners.max_gp ? width->grp = ft_get_size(max.grp, 10)
						: (width->grp = owners.max_gp);
	if (max.maj >= 0 && width->size < width->maj)
	{
		width->size = 1 + width->maj + 1;
		width->size += width->min + 1;
	}
	else if (max.min >= 0 && width->size && width->size > width->min)
	{
		width->min = width->size;
		width->size += 1 + width->maj + 1 + 1;
	}
}

int		ft_width(char *name, t_args *dirents, t_width *width, t_lsdet opts)
{
	char		*path;
	struct stat	info;
	long long	total;
	t_ownership	owners;
	t_width		max;

	ft_initialize_width(width);
	ft_initialize_width(&max);
	total = 0;
	owners.max_pw = 0;
	owners.max_gp = 0;
	while (dirents)
	{
		path = (*(dirents->name) != '/' && !ft_strstr(dirents->name, "./")) ?
		ft_strjoin(ft_strjoin(name, "/"), dirents->name) : dirents->name;
		lstat(path, &info);
		ft_width_xatt_lnk(path, &max, info);
		ft_width_ownership(&max, opts, info, &owners);
		ft_width_major_minor(&max, info);
		if (*(dirents->name) != '.' || opts.a)
			total += info.st_blocks;
		dirents = dirents->next;
	}
	get_width(width, max, owners);
	return (total);
}
