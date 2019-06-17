/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_content_tools.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <slyazid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 11:20:40 by slyazid           #+#    #+#             */
/*   Updated: 2019/02/15 11:21:11 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_check_content(char *path, struct dirent *elem, t_lsdet opts)
{
	char			*fullpath;
	char			*interm;
	struct stat		info;
	DIR				*pdir;

	interm = ft_strjoin(path, "/");
	fullpath = ft_strjoin(interm, elem->d_name);
	free(interm);
	errno = 0;
	pdir = 0;
	if (lstat(fullpath, &info) == -1
		&& (opts.l || opts.rcap) && !(pdir = opendir(fullpath))
		&& (errno != ENOTDIR || elem->d_type == DT_REG))
	{
		free(fullpath);
		return (1);
	}
	pdir ? closedir(pdir) : 0;
	free(fullpath);
	return (0);
}

char	*ft_join_path(char *name, char *dirs_name)
{
	char	*path;
	char	*interm;

	path = 0;
	interm = ft_strjoin(name, "/");
	if (ft_strcmp(dirs_name, ".") && ft_strcmp(name, "/"))
		path = ft_strjoin(interm, dirs_name);
	else if (!ft_strcmp(name, "/"))
		path = ft_strjoin(name, dirs_name);
	interm ? free(interm) : 0;
	return (path);
}
