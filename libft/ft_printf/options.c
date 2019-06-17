/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <slyazid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 17:19:36 by slyazid           #+#    #+#             */
/*   Updated: 2019/01/22 21:55:55 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_isspecifier(int c)
{
	char *specifiers;

	specifiers = "cCdDifFkoOrsSuUxXpnb%";
	while (*specifiers)
		if (c == *specifiers++)
			return (1);
	return (0);
}

int	ft_isflag(int c)
{
	char *flags;

	flags = "-+ #0'";
	while (*flags)
		if (c == *flags++)
			return (1);
	return (0);
}

int	ft_iswidth_orprecision(int c)
{
	char *width;

	width = "0123456789*";
	while (*width)
		if (c == *width++)
			return (1);
	return (0);
}

int	ft_islength(int c)
{
	if (c == 'h' || c == 'l' || c == 'L'
			|| c == 'z' || c == 'j')
		return (1);
	return (0);
}

int	ft_iscolor(char *color)
{
	int	i;

	i = ft_strlen(color);
	if (color[0] == '[' && color[i - 1] == 'm')
		return (1);
	return (0);
}
