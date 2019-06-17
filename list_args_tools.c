/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_args_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <slyazid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 10:39:05 by slyazid           #+#    #+#             */
/*   Updated: 2019/02/15 10:40:45 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_args	*ft_add_first(char *name, t_args *pos, mode_t type, t_lsdet opts)
{
	t_args	*dirs;
	DIR		*pdir;

	dirs = (t_args *)malloc(sizeof(t_args));
	dirs->name = ft_strdup(name);
	dirs->len = ft_strlen(dirs->name);
	errno = 0;
	if (((pdir = opendir(name))
			&& (IFTODT(type) != DT_LNK
				|| (!opts.l || name[ft_strlen(name) - 1] == '/')))
		|| (name[ft_strlen(name) - 1] == '/' && errno != 20))
	{
		pdir ? closedir(pdir) : 0;
		dirs->type = DT_DIR;
	}
	else
		dirs->type = IFTODT(type);
	dirs->next = pos;
	return (dirs);
}

void	ft_new_file(t_args *dirs, char *name, mode_t type)
{
	t_args	*interm;

	interm = dirs->next;
	dirs->next = (t_args*)malloc(sizeof(t_args));
	dirs->next->name = ft_strdup(name);
	dirs->next->len = ft_strlen(name);
	dirs->next->type = IFTODT(type);
	dirs->next->next = interm;
}
