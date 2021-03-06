/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 23:38:35 by xperrin           #+#    #+#             */
/*   Updated: 2019/08/29 15:07:36 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "printf_internal.h"

/*
** d = argument ; f = flag ; w = width ; p = precision
**
** Three cases:
**
** Precision only:
** p > w and p > d, basically just zeroes
** (same than left aligned)
**
** Left aligned: (default)
** ' ' | 'prepend' | '0' | itoa(d)
**
** Right aligned:
** 'prepend' | '0' | itoa(d) | ' ': w - p (-prepend?)
*/

static	size_t		l_print(int fd, char prepend, char *str, t_parg parg)
{
	int		size;
	size_t	i;
	size_t	w;

	w = ft_strlen(str);
	i = w;
	size = (parg.prec > (int)w) ? parg.prec : (int)w;
	size = (prepend) ? size + 1 : size;
	while (parg.width-- - size > 0)
	{
		buff_putchar(' ', fd);
		i++;
	}
	(prepend) ? buff_putchar(prepend, fd) : (void)42;
	size = (prepend) ? size - 1 : size;
	while (size-- - w > 0)
	{
		buff_putchar('0', fd);
		i++;
	}
	buff_write(fd, str, w);
	return ((prepend) ? i + 1 : i);
}

static	size_t		r_print(int fd, char prepend, char *str, t_parg parg)
{
	int		size;
	size_t	i;
	int		tmp;
	size_t	w;

	w = ft_strlen(str);
	i = w;
	size = (parg.prec > (int)w) ? parg.prec : (int)w;
	size = (prepend) ? size + 1 : size;
	(prepend) ? buff_putchar(prepend, fd) : (void)42;
	tmp = size;
	w += (prepend) ? 1 : 0;
	while (size-- - w > 0)
	{
		buff_putchar('0', fd);
		i++;
	}
	buff_write(fd, str, w);
	while (parg.width-- - tmp > 0)
	{
		buff_putchar(' ', fd);
		i++;
	}
	return ((prepend) ? i + 1 : i);
}

t_parg				zeroflag_handler(t_parg parg, char prepend)
{
	parg.prec = (prepend) ? parg.width - 1 : parg.width;
	parg.width = 0;
	return (parg);
}

size_t				conv_int(int fd, t_parg parg, va_list ap)
{
	intmax_t	n;
	char		prepend;
	char		str[ITOA_B_BUF];

	prepend = '\0';
	prepend = ft_strchr(parg.flags, ' ') ? ' ' : prepend;
	prepend = ft_strchr(parg.flags, '+') ? '+' : prepend;
	n = conv_t_int(parg, ap);
	if (parg.type == 'b')
		(!n && !parg.prec) ? (void)(str[0] = '\0') : ft_itoa_bs(str, n, B_BIN);
	else
		(!n && !parg.prec) ? (void)(str[0] = '\0') : ft_itoa_bs(str, n, B_DEC);
	if (n < 0)
	{
		ft_memmove(str, str + 1, sizeof(str));
		prepend = '-';
	}
	if (parg.prec == -1 && ft_strchr(parg.flags, '0')
			&& !ft_strchr(parg.flags, '-'))
		parg = zeroflag_handler(parg, prepend);
	if (!ft_strchr(parg.flags, '-'))
		return (l_print(fd, prepend, str, parg));
	else
		return (r_print(fd, prepend, str, parg));
}
