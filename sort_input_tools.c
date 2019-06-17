/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_input_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <slyazid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 16:32:22 by slyazid           #+#    #+#             */
/*   Updated: 2019/02/10 03:07:27 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_swap_fields(t_args *lst, t_args *next)
{
	char	*name_swapper;

	lst->type += next->type;
	next->type = lst->type - next->type;
	lst->type -= next->type;
	lst->len += next->len;
	next->len = lst->len - next->len;
	lst->len -= next->len;
	name_swapper = lst->name;
	lst->name = next->name;
	next->name = name_swapper;
}
