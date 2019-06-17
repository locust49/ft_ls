/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzahir <medayoub.zahir@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 14:33:44 by mzahir            #+#    #+#             */
/*   Updated: 2018/11/09 21:56:11 by mzahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	t_buff	*ft_create_buff(int fd, t_buff *previous)
{
	t_buff	*buff;

	if (!(buff = (t_buff*)malloc(sizeof(t_buff))))
		return (0);
	buff->previous = 0;
	buff->next = 0;
	if (previous)
	{
		buff->previous = previous;
		if (previous->next)
		{
			buff->next = previous->next;
			previous->next->previous = buff;
		}
		else
			buff->next = 0;
		previous->next = buff;
	}
	buff->data = "";
	buff->fd = fd;
	return (buff);
}

static	t_buff	*ft_find_fd(int fd, t_buff *buff)
{
	if (buff->previous)
		while (buff->previous)
			buff = buff->previous;
	while (buff)
	{
		if (buff->fd == fd)
			return (buff);
		buff = buff->next;
	}
	return (0);
}

static	t_buff	*ft_prepare_buff(int fd, t_buff *buff)
{
	t_buff	*temp;

	if (!buff)
	{
		if (!(buff = ft_create_buff(fd, 0)))
			return (0);
	}
	else
	{
		if ((temp = ft_find_fd(fd, buff)))
			buff = temp;
		else if (!(buff = ft_create_buff(fd, buff)))
			return (0);
	}
	return (buff);
}

static int		ft_read_line(int fd, t_buff **buff, char **read_ln, char **br)
{
	int	val;
	int	size;

	val = 1;
	if ((*br = ft_strchr((*buff)->data, '\n')))
		if (!(*read_ln = ft_strsub((*buff)->data, 0, *br - (*buff)->data)))
			return (-1);
	if (*((*buff)->data) && !*br)
		if (!(*read_ln = ft_strdup((*buff)->data)))
			return (-1);
	while (!*br)
	{
		if (!((*buff)->data = ft_strnew(BUFF_SIZE)))
			return (-1);
		if ((val = read(fd, (*buff)->data, BUFF_SIZE)) <= 0)
			break ;
		if (!(*br = ft_strchr((*buff)->data, '\n')))
			*read_ln = ft_strjoin(*read_ln, (*buff)->data);
		else
		{
			size = *br - (*buff)->data;
			*read_ln = ft_strjoin(*read_ln, ft_strsub((*buff)->data, 0, size));
		}
	}
	return (val);
}

int				get_next_line(const int fd, char **line)
{
	static t_buff	*buff;
	char			*read_ln;
	char			*br;
	int				val;

	if (fd < 0 || !line)
		return (-1);
	if (!(buff = ft_prepare_buff(fd, buff)))
		return (-1);
	if (!*(buff->data))
	{
		if (!(buff->data = ft_strnew(BUFF_SIZE)))
			return (-1);
		if ((val = read(fd, buff->data, BUFF_SIZE)) <= 0)
			return (val);
	}
	if ((val = ft_read_line(fd, &buff, &read_ln, &br)) == -1)
		return (val);
	if (!(*line = read_ln))
		return (-1);
	if (buff->data && br)
		buff->data = br + 1;
	if (!*line && val <= 0)
		return (val);
	return (1);
}
