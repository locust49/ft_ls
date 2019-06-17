/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <slyazid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 18:48:11 by slyazid           #+#    #+#             */
/*   Updated: 2019/01/23 17:26:01 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_is_color(char *color)
{
	if (!ft_strcmp(color, "red"))
		return (31);
	else if (!ft_strcmp(color, "green"))
		return (32);
	else if (!ft_strcmp(color, "yellow"))
		return (33);
	else if (!ft_strcmp(color, "blue"))
		return (34);
	else if (!ft_strcmp(color, "magenta"))
		return (35);
	else if (!ft_strcmp(color, "cyan"))
		return (36);
	else if (!ft_strcmp(color, "RED"))
		return (41);
	else if (!ft_strcmp(color, "GREEN"))
		return (42);
	else if (!ft_strcmp(color, "YELLOW"))
		return (43);
	else if (!ft_strcmp(color, "BLUE"))
		return (44);
	else if (!ft_strcmp(color, "MAGENTA"))
		return (45);
	else if (!ft_strcmp(color, "CYAN"))
		return (46);
	return (0);
}

int		ft_check_color(char *str)
{
	char	*start;
	char	*color;
	int		ret;

	start = str + 1;
	ret = 0;
	if (ft_strchr(str, '}'))
	{
		color = ft_strsub(start, 0, ft_strchr(str, '}') - start);
		while (*start && *start != '}')
			start++;
		ret = ft_is_color(color);
	}
	return (ret);
}

int		ft_cut_color(char **str)
{
	char	*newstr;
	char	*oldstr;
	int		length;
	int		code;
	int		i;

	i = 0;
	length = 0;
	oldstr = *str;
	newstr = ft_strnew(ft_strlen(*str));
	while (*oldstr && *oldstr != '{')
		newstr[i++] = *oldstr++;
	if ((code = ft_check_color(oldstr)))
	{
		length += ft_strlen(newstr);
		ft_putstr(newstr);
		ft_putchar('\033');
		ft_putstr("[0;");
		ft_putstr(ft_itoa(code));
		ft_putchar('m');
		if (ft_strchr(oldstr, '}'))
			*str = ft_strchr(oldstr, '}') + 1;
	}
	return (length);
}

int		ft_check_eoc(char **str)
{
	char	*newstr;
	char	*oldstr;
	int		length;
	int		i;

	i = 0;
	length = 0;
	oldstr = *str;
	newstr = ft_strnew(ft_strlen(*str));
	while (*oldstr && *oldstr != '{')
		newstr[i++] = *oldstr++;
	if (oldstr[1] == 'e' && oldstr[2] == 'o'
		&& oldstr[3] == 'c' && oldstr[4] == '}')
	{
		length += ft_strlen(newstr);
		ft_putstr(newstr);
		ft_putchar('\033');
		ft_putstr("[0m");
		if (ft_strchr(oldstr, '}'))
			*str = ft_strchr(oldstr, '}') + 1;
	}
	return (length);
}

int		ft_print_nonformatted(char *last_arg, char *find_next)
{
	char	*simple_str;
	int		len_check;
	int		len;

	len = 0;
	len_check = 1;
	simple_str = ft_strsub(last_arg, 0, find_next - last_arg);
	while (ft_strchr(simple_str, '{') && len_check)
	{
		len_check = len;
		len += ft_cut_color(&simple_str);
		len += ft_check_eoc(&simple_str);
		len_check = len - len_check;
	}
	len += ft_strlen(simple_str);
	ft_putstr(simple_str);
	return (len);
}
