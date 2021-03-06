/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 13:42:25 by xperrin           #+#    #+#             */
/*   Updated: 2019/08/29 15:49:23 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "printf_internal.h"

static	size_t	conv_uchar(int fd, t_parg parg, va_list ap)
{
	unsigned char	u[4];
	size_t			w;
	size_t			i;

	w = conv_unicode(u, va_arg(ap, wchar_t));
	i = w;
	if (ft_strchr(parg.flags, '-'))
		buff_write(fd, u, w);
	parg.width -= w;
	while (parg.width > 0)
	{
		parg.width--;
		buff_putchar((ft_strchr(parg.flags, '0')) ? '0' : ' ', fd);
		i++;
	}
	if (!ft_strchr(parg.flags, '-'))
		buff_write(fd, u, w);
	return (i);
}

size_t			conv_char(int fd, t_parg parg, va_list ap)
{
	char	c;
	size_t	i;

	i = 1;
	if (parg.type == 'C' || parg.length == l)
		return (conv_uchar(fd, parg, ap));
	c = (parg.type == '%') ? parg.type : va_arg(ap, int);
	if (ft_strchr(parg.flags, '-'))
		buff_putchar(c, fd);
	parg.width--;
	while (parg.width > 0)
	{
		parg.width--;
		buff_putchar((ft_strchr(parg.flags, '0')) ? '0' : ' ', fd);
		i++;
	}
	if (!ft_strchr(parg.flags, '-'))
		buff_putchar(c, fd);
	return (i);
}
