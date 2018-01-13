/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 19:45:28 by xperrin           #+#    #+#             */
/*   Updated: 2017/10/04 19:45:33 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int chr)
{
	if (32 <= chr && chr < 127)
		return (1);
	return (0);
}