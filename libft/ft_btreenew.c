/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzahir <medayoub.zahir@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 18:16:28 by mzahir            #+#    #+#             */
/*   Updated: 2018/10/20 22:52:15 by mzahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_btree	*ft_btreenew(void *item)
{
	t_btree	*btree;

	btree = item;
	if (!item)
		return (0);
	if (!(btree = (t_btree*)malloc(sizeof(t_btree))))
		return (0);
	btree->item = item;
	btree->left = 0;
	btree->right = 0;
	return (btree);
}
