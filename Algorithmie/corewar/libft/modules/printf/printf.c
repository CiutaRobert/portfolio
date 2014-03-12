/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 18:41:49 by nmokrane          #+#    #+#             */
/*   Updated: 2014/01/15 18:41:51 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "printf.h"

int				ft_vdprintf(int fd, const char *format, va_list ap)
{
	t_dynbuf		*buf;
	int				strpos;
	int				ret;

	buf = dynbuf_new(FTPRINTF_BUFF_SIZE);
	while ((strpos = ft_indexof(format, '%')) != -1)
	{
		format += dynbuf_write(buf, format, strpos) + 1;
		ptf_putarg(buf, &format, ap);
	}
	dynbuf_write(buf, format, strpos);
	write(fd, buf->ptr, buf->pos);
	va_end(ap);
	ret = (int)buf->pos;
	dynbuf_del(&buf);
	return (ret);
}

int				ft_dprintf(int fd, const char *format, ...)
{
	int				size;
	va_list			ap;

	va_start(ap, format);
	size = ft_vdprintf(fd, format, ap);
	va_end(ap);
	return (size);
}

int				ft_printf(const char *format, ...)
{
	int				size;
	va_list			ap;

	va_start(ap, format);
	size = ft_vdprintf(1, format, ap);
	va_end(ap);
	return (size);
}
