/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <slyazid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 15:31:28 by slyazid           #+#    #+#             */
/*   Updated: 2019/02/10 07:37:40 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		n_op(int ac, char **av)
{
	int i;

	i = 1;
	while (ac != i && av[i][0] == '-' && av[i][1])
	{
		if (av[i][1] == '-')
		{
			i++;
			break ;
		}
		i++;
	}
	return (i - 1);
}

void	ft_initialize_opts(t_lsdet *det)
{
	det->a = 0;
	det->c = 0;
	det->scap = 0;
	det->f = 0;
	det->l = 0;
	det->n = 0;
	det->r = 0;
	det->t = 0;
	det->n = 0;
	det->d = 0;
	det->o = 0;
	det->g = 0;
	det->u = 0;
	det->one = 0;
	det->rcap = 0;
	det->gcap = 0;
}

int		ft_operands(int ac, char **av, t_lsdet *opts)
{
	int		i;
	int		nb_op;
	char	check;
	char	*usage;

	i = 0;
	nb_op = n_op(ac, av);
	ft_initialize_opts(opts);
	while (i < nb_op)
	{
		if ((check = set_options(av[i + 1] + 1, opts)))
		{
			usage = ft_strdup("[-1FGRSacdfglnortu] [file ...]\n");
			ft_printf("ls: illegal option -- %c\nusage: ls %s",
				check, usage);
			free(usage);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	if (opts->f || opts->d)
		opts->a = 1;
	return (nb_op);
}
