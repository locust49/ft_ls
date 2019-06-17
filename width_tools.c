/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzahir <mzahir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 03:30:39 by slyazid           #+#    #+#             */
/*   Updated: 2019/02/12 21:27:43 by mzahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_initialize_width(t_width *width)
{
	width->xatt = 0;
	width->lnk = 0;
	width->usr = 0;
	width->grp = 0;
	width->size = 0;
	width->maj = -1;
	width->min = -1;
	width->wtime = 0;
}
