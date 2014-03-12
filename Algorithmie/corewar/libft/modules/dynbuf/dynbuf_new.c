/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynbuf_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 12:18:04 by nmokrane          #+#    #+#             */
/*   Updated: 2014/01/03 12:53:06 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "dynbuf.h"

t_dynbuf	*dynbuf_new(size_t radix)
{
	t_dynbuf	*buf;

	buf = (t_dynbuf*)ft_xmalloc(sizeof(t_dynbuf));
	if (buf == NULL)
		return (NULL);
	if (radix == 0)
		radix = DEFAULT_RADIX;
	buf->radix = radix;
	buf->ptr = NULL;
	buf->size = 0;
	buf->pos = 0;
	return (buf);
}
