/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergesort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <slyazid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 17:57:59 by mzahir            #+#    #+#             */
/*   Updated: 2019/02/08 07:15:44 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_args	*get_middle(t_args *list)
{
	t_args	*slow_ptr;
	t_args	*fast_ptr;

	slow_ptr = list;
	fast_ptr = list->next;
	while (fast_ptr)
	{
		fast_ptr = fast_ptr->next;
		if (fast_ptr)
		{
			slow_ptr = slow_ptr->next;
			fast_ptr = fast_ptr->next;
		}
	}
	return (slow_ptr);
}

t_args	*ft_sorted_merge(t_args *left, t_args *right, char *parent,
			int (*ft_cmpfunc)(const char *, const char *))
{
	t_args	*result;
	char	*path;
	char	*pathleft;
	char	*pathright;

	result = 0;
	path = ft_strjoin(parent, "/");
	if (!right)
		return (left);
	if (!left)
		return (right);
	pathright = ft_strjoin(path, right->name);
	pathleft = ft_strjoin(path, left->name);
	if (ft_cmpfunc(pathleft, pathright) > 0)
	{
		result = right;
		result->next = ft_sorted_merge(left, right->next, parent, ft_cmpfunc);
	}
	else
	{
		result = left;
		result->next = ft_sorted_merge(left->next, right, parent, ft_cmpfunc);
	}
	return (result);
}

t_args	*ft_merge_sort(t_args *head, char *parent,
						int (*ft_cmpfunc)(const char *, const char *))
{
	t_args	*middle;
	t_args	*lst2;
	t_args	*left;
	t_args	*right;
	t_args	*sorted;

	if (!head || !head->next)
		return (head);
	middle = get_middle(head);
	lst2 = middle->next;
	middle->next = 0;
	left = ft_merge_sort(head, parent, ft_cmpfunc);
	right = ft_merge_sort(lst2, parent, ft_cmpfunc);
	sorted = ft_sorted_merge(left, right, parent, ft_cmpfunc);
	return (sorted);
}
