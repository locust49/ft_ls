/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operands_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <slyazid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 20:17:45 by slyazid           #+#    #+#             */
/*   Updated: 2019/02/10 06:46:01 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	set_options_format(char *opt, t_lsdet *det)
{
	if (*opt == '1')
	{
		det->o ? det->o = 0 : 0;
		det->g ? det->g = 0 : 0;
		det->l ? det->l = 0 : 0;
		det->n ? det->n = 0 : 0;
		det->one = 1;
	}
	if (*opt == 'l' || *opt == 'n' || *opt == 'o' || *opt == 'g')
	{
		det->one ? det->one = 0 : 0;
		*opt == 'l' ? det->l = 1 : 0;
		*opt == 'n' ? det->n = 1 : 0;
		*opt == 'o' ? det->o = 1 : 0;
		*opt == 'g' ? det->g = 1 : 0;
	}
	(*opt == 'd') ? det->d = 1 : 0;
}

void	set_options_sort(char *opt, t_lsdet *det)
{
	if (*opt == 'f')
	{
		det->t ? det->t = 0 : 0;
		det->scap ? det->scap = 0 : 0;
		det->r ? det->r = 0 : 0;
		det->f = 1;
	}
	(*opt == 'r' && !det->f) ? det->r = 1 : 0;
	(*opt == 't' && !det->scap && !det->f) ? det->t = 1 : 0;
	if (*opt == 'u')
	{
		det->c ? det->c = 0 : 0;
		det->u = 1;
	}
	if (*opt == 'c')
	{
		det->u ? det->u = 0 : 0;
		det->c = 1;
	}
	if (*opt == 'S' && !det->f)
	{
		det->t ? det->t = 0 : 0;
		det->scap = 1;
	}
}

int		ft_isoption(char opt)
{
	short	i;
	char	*all_opts;

	all_opts = "-1FGRSacdfglnortu";
	i = 0;
	while (all_opts[i])
		if (opt == all_opts[i++])
			return (1);
	return (0);
}

char	set_options(char *opt, t_lsdet *det)
{
	while (*opt)
	{
		if (!ft_isoption(*opt))
			return (*opt);
		if (*opt == '-' && *(opt - 1) == '-' && !(*(opt + 1)))
			break ;
		if (*opt == '-')
			return (*opt);
		(*opt == 'a') ? det->a = 1 : 0;
		(*opt == 'R') ? det->rcap = 1 : 0;
		(*opt == 'G') ? det->gcap = 1 : 0;
		(*opt == 'F') ? det->fcap = 1 : 0;
		set_options_format(opt, det);
		set_options_sort(opt, det);
		opt++;
	}
	if (!det->t && !det->l)
	{
		det->u ? det->u = 0 : 0;
		det->c ? det->c = 0 : 0;
	}
	return (0);
}
