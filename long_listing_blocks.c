/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_listing_blocks.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <slyazid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 20:47:50 by slyazid           #+#    #+#             */
/*   Updated: 2019/02/15 12:37:02 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_type(mode_t st_mode)
{
	if ((st_mode & S_IFMT) == S_IFBLK)
		ft_putchar('b');
	else if ((st_mode & S_IFMT) == S_IFREG)
		ft_putchar('-');
	else if ((st_mode & S_IFMT) == S_IFCHR)
		ft_putchar('c');
	else if ((st_mode & S_IFMT) == S_IFLNK)
		ft_putchar('l');
	else if ((st_mode & S_IFMT) == S_IFSOCK)
		ft_putchar('s');
	else if ((st_mode & S_IFMT) == S_IFIFO)
		ft_putchar('p');
	else if ((st_mode & S_IFMT) == S_IFDIR)
		ft_putchar('d');
	else
		ft_putchar('?');
}

char	set_xattr_acl(char *path)
{
	ssize_t			xattr;
	acl_t			acl;
	acl_entry_t		acl_entry;

	acl = acl_get_link_np(path, ACL_TYPE_EXTENDED);
	if (acl && acl_get_entry(acl, ACL_FIRST_ENTRY, &acl_entry) == -1)
	{
		acl_free(acl);
		acl = NULL;
	}
	xattr = listxattr(path, NULL, 0, XATTR_NOFOLLOW);
	if (xattr < 0)
		xattr = 0;
	if (xattr > 0)
		return ('@');
	if (acl != NULL)
		return ('+');
	return (' ');
}

char	*set_permissions(unsigned short mode)
{
	int				i;
	char			*permstr;
	char			*possib_perms;
	unsigned short	cmp;

	possib_perms = "rwxrwxrwx";
	permstr = ft_strnew(10);
	i = 0;
	while (i < 9)
	{
		cmp = 1 << (8 - i);
		permstr[i] = (cmp & mode) ? possib_perms[i] : '-';
		cmp <<= (i + ((8 - i + 3) / 3));
		if (!((8 - i + 3) % 3) && (mode & cmp))
		{
			if (i == 8)
				permstr[i] = ((permstr[i] == 'x') ? 't' : 'T');
			else
				permstr[i] = ((permstr[i] == 'x') ? 's' : 'S');
		}
		i++;
	}
	return (permstr);
}

void	ft_print_owner(uid_t uid, int w, t_lsdet opts)
{
	struct passwd	*pw;

	pw = getpwuid(uid);
	if (!opts.n && pw->pw_name)
		ft_printf("%-*s", w, pw->pw_name);
	else
		ft_printf("%-*u", w, pw->pw_uid);
	if (!opts.g)
		ft_putstr("  ");
}

void	ft_print_group(gid_t gid, int w, t_lsdet opts)
{
	struct group	*gp;

	gp = getgrgid(gid);
	if (!opts.n && gp->gr_name)
		ft_printf("%-*s", w, gp->gr_name);
	else
		ft_printf("%-*u", w, gp->gr_gid);
	if (!opts.o)
		ft_putstr("  ");
}
