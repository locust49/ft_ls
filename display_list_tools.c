/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_list_tools.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <slyazid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 10:44:13 by slyazid           #+#    #+#             */
/*   Updated: 2019/02/15 10:45:15 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_multiplearg_details(t_args *dirs, t_width w, t_lsdet opts)
{
	DIR			*pdir;

	if (opts.l || opts.n || opts.o || opts.g)
	{
		pdir = opendir(dirs->name);
		ft_display_dirname(dirs->name, pdir);
		ft_display_links(pdir, dirs->name, w, opts);
		pdir ? closedir(pdir) : 0;
		if (dirs->next && dirs->next->type == DT_DIR)
			ft_putchar('\n');
	}
	else
		ft_display_error(dirs->name);
}

void	ft_single_arg_details(t_args *dirs, t_width w, t_lsdet opts)
{
	DIR			*pdir;

	if (!(pdir = opendir(dirs->name)))
	{
		if (opts.d)
			ft_list_long_format(dirs->name, dirs->name, w, opts);
		else
			ft_display_links(pdir, dirs->name, w, opts);
	}
	else
	{
		pdir ? closedir(pdir) : 0;
		ft_display_links(pdir, dirs->name, w, opts);
	}
}
