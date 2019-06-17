/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzahir <mzahir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 04:44:42 by slyazid           #+#    #+#             */
/*   Updated: 2019/02/10 19:56:53 by mzahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_add_symbol(t_args *lst, mode_t st_mode)
{
	char	*name;

	name = lst->name;
	if ((st_mode & S_IFMT) == S_IFDIR)
		lst->name = ft_strjoin(name, "/");
	else if ((st_mode & S_IFMT) == S_IFIFO)
		lst->name = ft_strjoin(name, "|");
	else if ((st_mode & S_IFMT) == S_IFLNK)
		lst->name = ft_strjoin(name, "@");
	else if ((st_mode & S_IFMT) == S_IFSOCK)
		lst->name = ft_strjoin(name, "=");
	else if ((st_mode & S_IFMT) == S_IFWHT)
		lst->name = ft_strjoin(name, "%");
	else if (st_mode & (S_IXUSR | S_IXGRP | S_IXOTH))
		lst->name = ft_strjoin(name, "*");
	else
		lst->name = ft_strdup(name);
	free(name);
}

void	ft_print_type_symb(mode_t st_mode)
{
	if ((st_mode & S_IFMT) == S_IFDIR)
		ft_putchar('/');
	else if ((st_mode & S_IFMT) == S_IFIFO)
		ft_putchar('|');
	else if ((st_mode & S_IFMT) == S_IFLNK)
		ft_putchar('@');
	else if ((st_mode & S_IFMT) == S_IFSOCK)
		ft_putchar('=');
	else if ((st_mode & S_IFMT) == S_IFWHT)
		ft_putchar('%');
	else if (st_mode & (S_IXUSR | S_IXGRP | S_IXOTH))
		ft_putchar('*');
}

void	ft_print_color(mode_t st_mode, char *toprint, int width)
{
	if (S_ISDIR(st_mode) && (st_mode & S_IWOTH) && (st_mode & S_ISVTX))
		ft_printf("\033[30;42m%-*s\033[0m", width, toprint);
	else if (S_ISDIR(st_mode) && (st_mode & S_IWOTH & !(st_mode & S_ISVTX)))
		ft_printf("\033[30;42m%-*s\033[0m", width, toprint);
	else if ((st_mode & S_IFMT) == S_IFDIR)
		ft_printf("{blue}%-*s{eoc}", width, toprint);
	else if ((st_mode & S_IFMT) == S_IFLNK)
		ft_printf("{magenta}%-*s{eoc}", width, toprint);
	else if ((st_mode & S_IFMT) == S_IFSOCK)
		ft_printf("{green}%-*s{eoc}", width, toprint);
	else if ((st_mode & S_IFMT) == S_IFIFO)
		ft_printf("{yellow}%-*s{eoc}", width, toprint);
	else if (st_mode & (S_IXUSR | S_IXGRP | S_IXOTH))
		ft_printf("{red}%-*s{eoc}", width, toprint);
	else if ((st_mode & S_IFMT) == S_IFBLK)
		ft_printf("\033[34;46m%-*s\033[0m", width, toprint);
	else if ((st_mode & S_IFMT) == S_IFCHR)
		ft_printf("\033[34;43m%-*s\033[0m", width, toprint);
	else if ((st_mode & (S_IXUSR | S_IXGRP | S_IXOTH)) == S_ISUID)
		ft_printf("\033[30;41m%-*s[0m", width, toprint);
	else if ((st_mode & (S_IXUSR | S_IXGRP | S_IXOTH)) == S_ISGID)
		ft_printf("\033[30;46m%-*s\033[0m", width, toprint);
	else
		ft_printf("%-*s", width, toprint);
}
