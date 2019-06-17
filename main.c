/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <slyazid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 14:33:13 by slyazid           #+#    #+#             */
/*   Updated: 2019/02/15 12:55:11 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_display_error(char *path)
{
	char *error;

	error = ft_strjoin("ls: ", path);
	perror(error);
	free(error);
	errno = 0;
	return (1);
}

void	ft_current_details(t_lsdet opts)
{
	struct stat	info;
	t_width		width;

	lstat(".", &info);
	ft_initialize_width(&width);
	ft_list_long_format(ft_strdup("./."), ".", width, opts);
}

int		main(int argc, char **argv)
{
	t_args		*dirs;
	t_lsdet		opts;
	int			nops;
	int			err;
	int			bounds[2];

	nops = ft_operands(argc, argv, &opts);
	bounds[0] = nops;
	bounds[1] = argc;
	!opts.f ? ft_sort_args(argc, argv, nops, opts) : 0;
	dirs = get_dir_lst(bounds, argv, opts, &err);
	dirs && opts.d ? (dirs = ft_sort_input(dirs, ".", opts)) : 0;
	if (argc - nops == 1 && !opts.d)
		ft_print_dir(".", opts);
	else if (argc - nops == 1 && opts.d && !opts.l)
		ft_putendl(".");
	else if (argc - nops == 1 && opts.d && opts.l)
		ft_current_details(opts);
	else if (!opts.d)
		ft_display_args("./", dirs, opts, err);
	else if (opts.d && opts.l)
		ft_display_long_format("./", dirs, opts, 1);
	else
		ft_ls_display(dirs, opts);
	return (0);
}
