/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynbuf_write.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 12:20:13 by nmokrane          #+#    #+#             */
/*   Updated: 2014/01/03 12:53:10 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "dynbuf.h"

int			dynbuf_write(t_dynbuf *buf, const void *data, int datasize)
{
	int		idx;

	if (data == NULL)
		return (0);
	if (datasize == -1)
		datasize = ft_strlen((const char *)data);
	while ((buf->pos + datasize) > buf->size)
	{
		idx = buf->size + buf->radix;
		if ((buf->ptr = (char*)ft_realloc(buf->ptr, buf->size, idx)) == NULL)
			return (-1);
		buf->size = idx;
	}
	idx = 0;
	while (idx < datasize)
	{
		((char*)buf->ptr)[buf->pos] = ((char*)data)[idx];
		buf->pos += 1;
		idx += 1;
	}
	return (idx);
}
