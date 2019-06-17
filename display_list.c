/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <slyazid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 07:12:20 by slyazid           #+#    #+#             */
/*   Updated: 2019/02/15 10:49:56 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_display_dirname(char *dirs_name, DIR *pdir)
{
	struct stat	info;

	if (lstat(dirs_name, &info) == -1)
		return ;
	if (pdir && (info.st_mode & S_IFMT) == S_IFDIR)
	{
		ft_putstr(dirs_name);
		ft_putendl(":");
	}
}

void	ft_display_links(DIR *pdir, char *dirs_name, t_width w, t_lsdet opts)
{
	struct stat	info;
	char		*name;
	char		link[PATH_MAX];
	ssize_t		read;

	name = ft_strrchr(dirs_name, '/');
	if (lstat(dirs_name, &info) != -1)
	{
		if (pdir && (info.st_mode & S_IFMT) == S_IFDIR)
			ft_print_dir(dirs_name, opts);
		else if (dirs_name[ft_strlen(dirs_name) - 1] != '/')
			ft_list_long_format(dirs_name, dirs_name, w, opts);
		else
		{
			read = readlink(dirs_name, link, PATH_MAX);
			read > 0 ? ft_list_long_format(link, dirs_name, w, opts)
				: ft_list_long_format(dirs_name, dirs_name, w, opts);
		}
	}
	else
		ft_display_error(dirs_name);
}

void	ft_display_single_arg(t_args *dirs, t_lsdet opts, int err)
{
	t_width		w;
	struct stat	info;
	DIR			*pdir;

	lstat(dirs->name, &info);
	ft_initialize_width(&w);
	if ((pdir = opendir(dirs->name)) && !opts.d
		&& (!opts.l && !opts.n && !opts.o && !opts.g))
	{
		closedir(pdir);
		pdir = 0;
		if (err)
			ft_printf("%s:\n", dirs->name);
		ft_print_dir(dirs->name, opts);
	}
	else if (!pdir && errno != 20 && (dirs->type != DT_LNK || errno != 2))
		ft_display_error(dirs->name);
	else if (opts.l || opts.n || opts.o || opts.g)
		ft_single_arg_details(dirs, w, opts);
	else if (!pdir)
		ft_putendl(dirs->name);
	else
		ft_display_error(dirs->name);
	pdir ? closedir(pdir) : 0;
}

void	ft_display_multiple_arg(char *name, t_args *dirs, t_lsdet opts)
{
	DIR			*pdir;
	t_width		w;

	if (!opts.l && !opts.n && !opts.o && !opts.g)
		dirs = ft_print_files(dirs, opts);
	ft_width(name, dirs, &w, opts);
	while (dirs)
	{
		if ((pdir = opendir(dirs->name))
			&& (!opts.l && !opts.n && !opts.o && !opts.g))
		{
			closedir(pdir);
			pdir = 0;
			ft_printf("%s:\n", dirs->name);
			ft_print_dir(dirs->name, opts);
			dirs && dirs->next ? ft_putchar('\n') : 0;
		}
		else if (!pdir && errno != 20
			&& (dirs->type != DT_LNK || errno != 2))
			ft_display_error(dirs->name);
		else
			ft_multiplearg_details(dirs, w, opts);
		pdir ? closedir(pdir) : 0;
		dirs = dirs->next;
	}
}
