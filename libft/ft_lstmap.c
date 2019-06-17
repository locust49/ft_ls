/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzahir <medayoub.zahir@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 01:58:21 by mzahir            #+#    #+#             */
/*   Updated: 2018/10/17 22:11:26 by mzahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*mapped_lst;
	t_list	*start;

	if (!lst)
		return (0);
	mapped_lst = (*f)(lst);
	start = mapped_lst;
	while (lst->next)
	{
		mapped_lst->next = (*f)(lst->next);
		lst = lst->next;
		mapped_lst = mapped_lst->next;
	}
	mapped_lst->next = 0;
	return (start);
}
