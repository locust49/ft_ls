/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   date.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <slyazid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 20:50:49 by slyazid           #+#    #+#             */
/*   Updated: 2019/02/15 11:37:11 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

time_t	ft_findate_inpos(t_format fparts, va_list start)
{
	int		i;
	time_t	arg_inpos;

	i = 1;
	while (i <= fparts.position)
	{
		arg_inpos = va_arg(start, time_t);
		i++;
	}
	return (arg_inpos);
}

int		ft_print_date(t_format fparts, va_list arg_lst, va_list start)
{
	time_t		dt;
	time_t		diff;
	char		*date;
	char		*str;

	dt = (fparts.position ? ft_findate_inpos(fparts, start)
			: va_arg(arg_lst, time_t));
	diff = time(NULL) - dt;
	str = ctime(&dt);
	date = ft_strnew(13);
	if (dt < 253402214399 && (diff >= 15768000 || diff <= -15768000))
	{
		ft_strncpy(date, str + 4, 7);
		ft_strncat(date, str + 19, 5);
	}
	else if (dt < 253402214399)
		date = ft_strncpy(date, str + 4, 12);
	else
	{
		ft_strncpy(date, str + 4, 7);
		ft_strncat(date, str + 23, 6);
	}
	ft_putstr(date);
	free(date);
	return (ft_strlen(date));
}
