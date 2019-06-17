/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <slyazid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 20:09:11 by slyazid           #+#    #+#             */
/*   Updated: 2019/02/15 10:36:54 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_recursive_display(t_args *list, int pos, int width, t_lsdet opts)
{
	t_args		*item;
	struct stat	info;

	info.st_mode = 0;
	if (opts.fcap)
	{
		lstat(list->name, &info);
		ft_add_symbol(list, info.st_mode);
	}
	if (!opts.gcap)
		ft_printf("%-*s", width, list->name);
	else
	{
		if (!info.st_mode)
			lstat(list->name, &info);
		ft_print_color(info.st_mode, list->name, width);
	}
	if ((item = get_item_inpos(list, pos, 0)))
	{
		!opts.one ? ft_putchar('\t') : 0;
		ft_recursive_display(item, pos, width, opts);
	}
}

int		ft_onecol_display(t_args *list, t_lsdet opts)
{
	if (!opts.one)
		return (0);
	while (list)
	{
		ft_putendl(list->name);
		list = list->next;
	}
	return (1);
}

void	ft_ls_display(t_args *list, t_lsdet opts)
{
	struct ttysize	ts;
	int				width;
	int				wsize;
	int				cols;
	int				i;

	wsize = get_list_length(list);
	width = get_max_len(list) + (opts.fcap && !opts.gcap);
	if (ft_onecol_display(list, opts))
		return ;
	ioctl(0, TIOCGWINSZ, &ts);
	cols = ts.ts_cols / (width + get_tab_size(width));
	cols ? 0 : (cols = 1);
	get_item_inpos(list, wsize, 1);
	wsize % cols ? (wsize = wsize / cols + 1) : (wsize /= cols);
	i = 0;
	while (i < wsize)
	{
		ft_recursive_display(list, wsize, width, opts);
		ft_putchar('\n');
		list = list->next;
		i++;
	}
}

void	ft_basic_display(char *name, t_args *files, t_lsdet opts)
{
	struct stat	info;
	t_args		*dirs;
	char		*path;

	if (!files)
		return ;
	dirs = ft_print_files(files, opts);
	while (dirs)
	{
		if ((lstat(dirs->name, &info) == -1))
			ft_display_error(ft_strrchr(dirs->name, '/') + 1);
		else
		{
			ft_printf("%s:\n", dirs->name);
			path = (*(dirs->name) == '/' ? ft_strdup(dirs->name)
					: ft_strjoin(name, dirs->name));
			ft_print_dir(path, opts);
		}
		dirs = dirs->next;
	}
}

void	ft_display_args(char *name, t_args *dirs, t_lsdet opts, int err)
{
	if (dirs && !dirs->next)
		ft_display_single_arg(dirs, opts, err);
	else
		ft_display_multiple_arg(name, dirs, opts);
}
