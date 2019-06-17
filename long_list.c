/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <slyazid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 17:23:32 by slyazid           #+#    #+#             */
/*   Updated: 2019/02/15 11:48:49 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*get_fullpath(char *path, char *dirents_name)
{
	char		*name;
	char		*fullpath;
	struct stat	info;

	fullpath = NULL;
	if ((lstat(path, &info) != -1))
	{
		(*dirents_name != '/')
		&& (dirents_name[ft_strlen(dirents_name) - 1] != '/'
			&& (name = ft_strrchr(dirents_name, '/')))
		&& (name - dirents_name) && (name + 1)
			? name++ : (name = dirents_name);
		if ((info.st_mode & S_IFMT) != S_IFDIR)
			fullpath = ft_strjoin("./", dirents_name);
		else if (*dirents_name != '/')
		{
			fullpath = ft_strjoin(path, "/");
			fullpath = ft_strjoin(fullpath, name);
		}
		else
			fullpath = dirents_name;
	}
	else
		ft_display_error(path);
	return (fullpath);
}

char	*ft_find_name(char *fullpath)
{
	char	*last_valid;

	while ((fullpath = ft_strchr(fullpath, '/')))
	{
		while (*fullpath == '/')
			fullpath++;
		if (!*fullpath)
			break ;
		last_valid = fullpath;
	}
	return (last_valid);
}

void	ft_print_name(char *fullpath, t_lsdet opts, struct stat info)
{
	char	*name;

	name = ft_strrchr(fullpath, '/');
	if (!opts.gcap)
	{
		if (*fullpath != '/' || (*fullpath == '/' && (name != fullpath)))
		{
			(name && !*(name + 1)) ?
				ft_putstr(ft_find_name(fullpath))
				: ft_putstr(name + 1);
		}
		else if (*fullpath == '/')
			ft_putstr(fullpath);
	}
	else
	{
		if (*fullpath != '/' || (*fullpath == '/' && (name != fullpath)))
		{
			(name && !*(name + 1)) ?
				ft_print_color(info.st_mode, ft_find_name(fullpath), 0)
				: ft_print_color(info.st_mode, name + 1, 0);
		}
		else if (*fullpath == '/')
			ft_print_color(info.st_mode, fullpath, 0);
	}
}

void	ft_list_long_format(char *fullpath, char *arg_name,
							t_width width, t_lsdet opts)
{
	struct stat	info;

	lstat(fullpath, &info);
	ft_print_type(info.st_mode);
	ft_printf("%s%c", set_permissions(info.st_mode), width.xatt
		? set_xattr_acl(fullpath) : ' ');
	ft_printf(" %*d ", width.lnk, (unsigned int)info.st_nlink);
	ft_print_owners(opts, width, info);
	ft_print_major_minor(width, info);
	ft_print_time(opts, info);
	arg_name ? ft_putstr(arg_name) : ft_print_name(fullpath, opts, info);
	opts.fcap ? ft_print_type_symb(info.st_mode) : 0;
	ft_print_links(fullpath, info);
	ft_putchar('\n');
}

void	ft_display_long_format(char *name, t_args *dirents, t_lsdet opts,
							int isnotrecursive)
{
	t_width		width;
	char		*fullpath;

	ft_width(name, dirents, &width, opts);
	while (dirents)
	{
		if (*(dirents->name) != '.' || opts.a)
		{
			fullpath = get_fullpath(name, dirents->name);
			isnotrecursive
			? ft_list_long_format(fullpath, dirents->name, width, opts)
			: ft_list_long_format(fullpath, 0, width, opts);
			free(fullpath);
		}
		dirents = dirents->next;
	}
}
