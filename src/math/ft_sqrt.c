/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 13:39:07 by xperrin           #+#    #+#             */
/*   Updated: 2017/11/26 14:30:34 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_sqrt(int x)
{
	int i;
	int res;

	i = 1;
	res = 0;
	while (res < x)
	{
		res = i * i;
		if (res == x)
			return (i);
		i++;
	}
	return (0);
}
