/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynbuf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 12:53:55 by nmokrane          #+#    #+#             */
/*   Updated: 2014/01/03 20:09:40 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DYNBUF_H
# define DYNBUF_H

# include <string.h>

# define DEFAULT_RADIX 32

/*
** Auto expandable dynamic buffer
** - ptr: a pointer to the start of the buffer;
** - size: buffer's current full size
** - pos: The offset to the current position
** - radix: the value used to expand buffer size.
*/

typedef struct		s_dynbuf
{
	void			*ptr;
	size_t			size;
	size_t			pos;
	size_t			radix;
}					t_dynbuf;

t_dynbuf	*dynbuf_new(size_t radix);
void		dynbuf_del(t_dynbuf **buf);
int			dynbuf_write(t_dynbuf *buf, const void *data, int datasize);

#endif /* !DYNBUF_H */
