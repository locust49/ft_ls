/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_apply_suffix.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzahir <medayoub.zahir@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 17:41:50 by mzahir            #+#    #+#             */
/*   Updated: 2018/10/21 17:42:37 by mzahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btree_apply_suffix(t_btree *root, void (*applyf)(void *))
{
	if (root->left)
		ft_btree_apply_suffix(root->left, applyf);
	if (root->right)
		ft_btree_apply_suffix(root->right, applyf);
	if (root)
		(*applyf)(root->item);
}
