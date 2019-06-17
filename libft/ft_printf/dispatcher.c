/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <slyazid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 17:49:39 by slyazid           #+#    #+#             */
/*   Updated: 2019/01/21 23:26:21 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

t_funcps	ft_set_dispatcher_field(char *specifiers,
				int (*funcp)(t_format fparts, va_list arg_lst, va_list start))
{
	t_funcps	field;

	field.specifiers = specifiers;
	field.funcp = funcp;
	return (field);
}

void		ft_initialize_dispatcher(t_funcps dispatcher[])
{
	dispatcher[0] = ft_set_dispatcher_field("Ddi", &ft_print_ints);
	dispatcher[1] = ft_set_dispatcher_field("oO", &ft_print_octals);
	dispatcher[2] = ft_set_dispatcher_field("cC", &ft_print_chars);
	dispatcher[3] = ft_set_dispatcher_field("sS", &ft_print_strings);
	dispatcher[4] = ft_set_dispatcher_field("p", &ft_print_address);
	dispatcher[5] = ft_set_dispatcher_field("xX", &ft_print_hex);
	dispatcher[6] = ft_set_dispatcher_field("uU", &ft_print_unsigned);
	dispatcher[7] = ft_set_dispatcher_field("b", &ft_print_binary);
	dispatcher[8] = ft_set_dispatcher_field("fF", &ft_print_floats);
	dispatcher[9] = ft_set_dispatcher_field("r", &ft_print_nonprintable);
	dispatcher[10] = ft_set_dispatcher_field("k", &ft_print_date);
}
