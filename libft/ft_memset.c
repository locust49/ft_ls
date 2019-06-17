/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzahir <medayoub.zahir@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 22:51:50 by mzahir            #+#    #+#             */
/*   Updated: 2018/10/17 23:10:15 by mzahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	uc;
	char			*str;

	i = 0;
	str = (char*)b;
	uc = (unsigned char)c;
	while (i < len)
	{
		str[i] = uc;
		i++;
	}
	return (b);
}
