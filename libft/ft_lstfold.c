/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfold.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzahir <medayoub.zahir@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 21:39:23 by mzahir            #+#    #+#             */
/*   Updated: 2018/10/19 17:09:42 by mzahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_lstfold(t_list *lst, void *(*f)(void*, void*))
{
	void			*accumulator;

	accumulator = lst->content;
	while (lst)
	{
		accumulator = (*f)(accumulator, lst->content);
		lst = lst->next;
	}
	return (accumulator);
}
