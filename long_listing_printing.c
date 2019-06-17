/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_listing_printing.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <slyazid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 02:23:48 by slyazid           #+#    #+#             */
/*   Updated: 2019/02/10 07:09:01 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_owners(t_lsdet opts, t_width width, struct stat info)
{
	if (!opts.g && (!(opts.g && opts.o)))
		ft_print_owner(info.st_uid, width.usr, opts);
	if (!opts.o && (!(opts.g && opts.o)))
		ft_print_group(info.st_gid, width.grp, opts);
	if (opts.o && opts.g)
		ft_putstr("  ");
}

void	ft_print_major_minor(t_width width, struct stat info)
{
	if ((info.st_mode & S_IFMT) == S_IFBLK
		|| (info.st_mode & S_IFMT) == S_IFCHR)
		ft_printf(" %*d, %*d", width.maj, major(info.st_rdev),
			width.min, minor(info.st_rdev));
	else
		ft_printf("%*u", width.size, info.st_size);
}

void	ft_print_time(t_lsdet opts, struct stat info)
{
	if (opts.u)
		ft_printf(" %k ", info.st_atime);
	else if (opts.c)
		ft_printf(" %k ", info.st_ctime);
	else
		ft_printf(" %k ", info.st_mtime);
}

/*
** void    ft_print_fullpath()
** {
** }
*/

void	ft_print_links(char *fullpath, struct stat info)
{
	char	link[PATH_MAX];
	int		len;

	len = 0;
	if (((info.st_mode & S_IFMT) == S_IFLNK)
			&& ((len = readlink(fullpath, link, 1024)) >= 0))
	{
		link[len] = '\0';
		ft_putstr(" -> ");
		ft_putstr(link);
	}
}
