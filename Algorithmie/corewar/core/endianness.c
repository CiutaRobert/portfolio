/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   endianness.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzak <jagu.sayan@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 23:12:41 by jzak              #+#    #+#             */
/*   Updated: 2014/01/31 13:51:42 by jzak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

t_u16		swap_u16(t_u16 *v)
{
	unsigned char		*data;

	data = (unsigned char*)v;
	*v = ((data[1] << 0) | (data[0] << 8));
	return (*v);
}

t_u32		swap_u32(t_u32 *v)
{
	unsigned char		*data;

	data = (unsigned char*)v;
	*v = ((data[3] << 0) | (data[2] << 8) | (data[1] << 16) | (data[0] << 24));
	return (*v);
}

t_uint		to_big_endian(t_uint nb, int size)
{
	int		i;
	t_uint	new_nb;

	i = 0;
	size = (size - 1) * 8;
	new_nb = 0;
	while (i <= size)
	{
		new_nb |= ((nb >> (size - i) & 0xFF)) << i;
		i += 8;
	}
	return (new_nb);
}
