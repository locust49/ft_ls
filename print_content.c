/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <slyazid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 20:29:31 by slyazid           #+#    #+#             */
/*   Updated: 2019/02/19 18:21:26 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_readding_dir(t_args **dirents, DIR *a_dir, t_lsdet opts, char *path)
{
	t_args			*current;
	t_args			*last;
	struct dirent	*elem;

	current = (t_args *)malloc(sizeof(t_args));
	*dirents = current;
	last = 0;
	while ((elem = readdir(a_dir)))
		if (*(elem->d_name) != '.' || opts.a)
		{
			if (ft_check_content(path, elem, opts))
				continue ;
			current->name = ft_strdup(elem->d_name);
			current->len = elem->d_namlen;
			current->type = elem->d_type;
			current->next = (t_args *)malloc(sizeof(t_args));
			last = current;
			current = current->next;
		}
	last ? (last->next = NULL) : 0;
	last ? 0 : (*dirents = 0);
	free(current);
}

void	ft_print_recursively(char *name, t_args *dirs, t_lsdet opts)
{
	char	*path;
	DIR		*pdir;

	while (dirs)
	{
		path = ft_join_path(name, dirs->name);
		errno = 0;
		if (((pdir = opendir(path)) || errno != 20) && dirs->type != DT_LNK)
		{
			pdir ? closedir(pdir) : 0;
			if (*(dirs->name) != '.' || opts.a)
				if (ft_strcmp(dirs->name, ".") && ft_strcmp(dirs->name, ".."))
				{
					ft_printf("\n%s:\n", path);
					ft_print_dir(path, opts);
				}
		}
		else if (errno != 20)
			pdir ? closedir(pdir) : 0;
		path ? free(path) : 0;
		dirs = dirs->next;
	}
}

void	ft_sortnprint_contents(char *name, t_args *dirents, t_lsdet opts)
{
	t_width w;

	!opts.f ? dirents = ft_sort_input(dirents, name, opts) : 0;
	if (dirents && !opts.l && !opts.n && !opts.o && !opts.g)
		ft_ls_display(dirents, opts);
	else if (dirents)
	{
		ft_printf("total %d\n", ft_width(name, dirents, &w, opts));
		ft_display_long_format(name, dirents, opts, 0);
	}
	if (dirents && opts.rcap)
		ft_print_recursively(name, dirents, opts);
}

void	ft_print_dir(char *name, t_lsdet opts)
{
	DIR		*a_dir;
	t_args	*dirents;

	if ((a_dir = opendir(name)))
	{
		errno = 0;
		ft_readding_dir(&dirents, a_dir, opts, name);
		if (!dirents)
			return ;
		ft_sortnprint_contents(name, dirents, opts);
		closedir(a_dir);
	}
	else
		ft_display_error(ft_strrchr(name, '/') + 1);
}

t_args	*ft_print_files(t_args *list, t_lsdet opts)
{
	t_args *files;
	t_args *dirs;

	files = list;
	errno = 0;
	if (!list)
		return (0);
	while (list->next && list->next->type != DT_DIR)
		list = list->next;
	dirs = (list->type == DT_DIR ? list : list->next);
	if (list->type != DT_DIR)
	{
		list->next = 0;
		ft_ls_display(files, opts);
		errno = 0;
	}
	dirs && (list != dirs) ? ft_putchar('\n') : 0;
	return (dirs);
}
