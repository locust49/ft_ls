/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <slyazid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 16:26:38 by slyazid           #+#    #+#             */
/*   Updated: 2019/02/15 10:41:58 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_add_directory(t_args **dirs, char *name, mode_t type)
{
	t_args	*tmp;

	tmp = *dirs;
	while (tmp && tmp->next)
		tmp = tmp->next;
	tmp->next = (t_args*)malloc(sizeof(t_args));
	tmp->next->name = ft_strdup(name);
	tmp->next->len = ft_strlen(name);
	tmp->next->type = IFTODT(type);
	tmp->next->next = NULL;
}

void	ft_add_file(t_args **dirs, char *name, mode_t type, t_lsdet opts)
{
	t_args			*head;

	head = *dirs;
	errno = 0;
	if ((*dirs)->type == DT_DIR)
	{
		*dirs = ft_add_first(name, *dirs, type, opts);
		return ;
	}
	while (*dirs && (*dirs)->next)
	{
		errno = 0;
		if ((*dirs)->next->type == DT_DIR)
			break ;
		*dirs = (*dirs)->next;
	}
	ft_new_file(*dirs, name, type);
	*dirs = head;
}

void	ft_add_link(t_args **dirs, char *name, mode_t type, t_lsdet opts)
{
	DIR	*pdir;

	if ((pdir = opendir(name))
		&& (!opts.l || name[ft_strlen(name) - 1] == '/'))
	{
		closedir(pdir);
		pdir = 0;
		ft_add_directory(dirs, name, DTTOIF(DT_DIR));
	}
	else if (name[ft_strlen(name) - 1] == '/' && errno != 20)
		ft_add_directory(dirs, name, DTTOIF(DT_DIR));
	else
		ft_add_file(dirs, name, type, opts);
	pdir ? closedir(pdir) : 0;
}

void	ft_add_field(t_args **dirs, char *name, mode_t type, t_lsdet opts)
{
	DIR			*pdir;

	errno = 0;
	if ((!(pdir = opendir(name)) && errno == 20))
		ft_add_file(dirs, name, type, opts);
	else if (IFTODT(type) == DT_LNK)
		ft_add_link(dirs, name, type, opts);
	else
		ft_add_directory(dirs, name, type);
	pdir ? closedir(pdir) : 0;
}

t_args	*get_dir_lst(int bounds[], char **argv, t_lsdet opts, int *err)
{
	t_args		*head;
	struct stat	info;

	*err = 0;
	head = NULL;
	while (bounds[0] + 1 < bounds[1])
	{
		if (lstat(argv[bounds[0] + 1], &info) == -1)
			*err = 1;
		else
			(!head) ?
			(head = ft_add_first(argv[bounds[0] + 1], NULL, info.st_mode, opts))
			: ft_add_field(&head, argv[bounds[0] + 1], info.st_mode, opts);
		bounds[0]++;
	}
	return (head);
}
