/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <slyazid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 22:01:07 by slyazid           #+#    #+#             */
/*   Updated: 2019/02/10 03:35:44 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_alphacmp(const char *item1, const char *item2)
{
	if (ft_strcmp(item1, item2) > 0 && ft_strcmp(item1, item2) != 32)
		return (1);
	if (ft_strcmp(item1, item2) < 0 || ft_strcmp(item1, item2) == 32
		|| ft_strcmp(item1, item2) == -32)
		return (-1);
	return (0);
}

int		ft_size(const char *item1, const char *item2)
{
	struct stat	info1;
	struct stat	info2;

	lstat(item2, &info2);
	lstat(item1, &info1);
	if (info2.st_size > info1.st_size)
		return (1);
	if (info2.st_size < info1.st_size)
		return (-1);
	return (0);
}

t_args	*ft_sort_reverse(t_args *lst)
{
	t_args	*first;
	t_args	*last;
	t_args	*current;
	t_args	*next;

	last = lst;
	next = lst->next;
	while (lst)
	{
		if (next)
		{
			current = next->next;
			next->next = lst;
			first = next;
		}
		lst = next;
		next = current;
	}
	last->next = 0;
	!first ? (first = last) : 0;
	return (first);
}

t_args	*ft_sort_bytime(t_args *lst, char *path, t_lsdet opts)
{
	if (!opts.r && opts.u)
		return (ft_merge_sort(lst, path, &ft_time_acmp));
	if (!opts.r && opts.c)
		return (ft_merge_sort(lst, path, &ft_time_ccmp));
	if (!opts.r)
		return (ft_merge_sort(lst, path, &ft_time_mcmp));
	if (!opts.r && opts.u)
		return (ft_merge_sort(lst, path, &ft_time_acmp));
	if (!opts.r && opts.c)
		return (ft_merge_sort(lst, path, &ft_time_ccmp));
	if (opts.r && opts.u)
		return (ft_sort_reverse(ft_merge_sort(lst, path, &ft_time_acmp)));
	if (opts.r && opts.c)
		return (ft_sort_reverse(ft_merge_sort(lst, path, &ft_time_ccmp)));
	if (opts.r)
		return (ft_sort_reverse(ft_merge_sort(lst, path, &ft_time_mcmp)));
	return (lst);
}

t_args	*ft_sort_input(t_args *lst, char *path, t_lsdet opts)
{
	lst = ft_merge_sort(lst, path, &ft_strcmp);
	if (!opts.r && !opts.t && !opts.scap)
		return (lst);
	if (opts.r && !opts.t && !opts.scap)
		return (ft_sort_reverse(lst));
	if (!opts.r && opts.scap)
		return (ft_merge_sort(lst, path, &ft_size));
	if (opts.r && opts.scap)
		return (ft_sort_reverse(ft_merge_sort(lst, path, &ft_size)));
	if (opts.t)
		return (ft_sort_bytime(lst, path, opts));
	return (lst);
}
