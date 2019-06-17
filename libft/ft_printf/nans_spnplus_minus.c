/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nans_spnplus_minus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <slyazid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 15:19:38 by slyazid           #+#    #+#             */
/*   Updated: 2019/01/23 17:24:29 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_minus_orplus(t_format fparts, int sign)
{
	sign ? ft_putchar('-') : ft_handle_spnplus(fparts);
}

int		ft_check_nans(t_format fparts, short exponent,
		t_dbl d_memrep, t_ldbl ld_memrep)
{
	short cmp_exp;

	cmp_exp = (fparts.length.lcap) ? 16384 : 1024;
	if ((exponent == 16384 && !ld_memrep.m_frac)
		|| (exponent == 16384 && ld_memrep.m_frac)
		|| (exponent == 1024 && !d_memrep.m_frac)
		|| (exponent == 1024 && d_memrep.m_frac))
		return (1);
	return (0);
}

char	*ft_set_nans(t_format fparts, short exponent,
		t_dbl d_memrep, t_ldbl ld_memrep)
{
	char	*num;
	short	cmp_exp;

	cmp_exp = (fparts.length.lcap) ? 16384 : 1024;
	if (exponent == 16384 && !ld_memrep.m_frac)
		num = (fparts.specifier == 'f') ? ft_strdup("inf") : ft_strdup("INF");
	if (exponent == 16384 && ld_memrep.m_frac)
		num = (fparts.specifier == 'f' ? ft_strdup("nan") : ft_strdup("NAN"));
	if (exponent == 1024 && !d_memrep.m_frac)
		num = (fparts.specifier == 'f' ? ft_strdup("inf") : ft_strdup("INF"));
	if (exponent == 1024 && d_memrep.m_frac)
		num = (fparts.specifier == 'f' ? ft_strdup("nan") : ft_strdup("NAN"));
	return (num);
}

int		ft_print_nans(t_format fparts, char *num, int sign)
{
	int	tot_len;

	tot_len = 3;
	fparts.zero = 0;
	((!sign && (fparts.plus || fparts.space)) || sign) ? tot_len++ : 0;
	if (fparts.minus)
	{
		!sign ? ft_handle_spnplus(fparts) : ft_putchar('-');
		ft_putstr(num);
		ft_adjust_width(fparts, &tot_len);
		return (tot_len);
	}
	ft_adjust_width(fparts, &tot_len);
	!sign && !fparts.zero ? ft_handle_spnplus(fparts) : 0;
	sign && !fparts.zero ? ft_putchar('-') : 0;
	ft_putstr(num);
	return (tot_len);
}
