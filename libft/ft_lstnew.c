/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzahir <medayoub.zahir@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 18:16:28 by mzahir            #+#    #+#             */
/*   Updated: 2018/10/17 21:39:31 by mzahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list;

	if (!(list = (t_list*)malloc(sizeof(t_list))))
		return (0);
	if (!content)
	{
		list->content = 0;
		list->content_size = 0;
		list->next = 0;
		return (list);
	}
	if (!(list->content = malloc(content_size)))
		return (0);
	ft_memcpy(list->content, content, content_size);
	list->content_size = content_size;
	list->next = 0;
	return (list);
}
