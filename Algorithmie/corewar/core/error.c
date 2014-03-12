/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzak <jagu.sayan@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/05 16:50:00 by jzak              #+#    #+#             */
/*   Updated: 2014/01/18 17:15:26 by jzak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "printf.h"
#include "libft.h"

void		warning(const char *fmt, ...)
{
	va_list		va;

	ft_dprintf(2, NAME);
	va_start(va, fmt);
	ft_vdprintf(2, fmt, va);
	va_end(va);
}

void		error(void (*help) (void), const char *fmt, ...)
{
	va_list		va;

	ft_dprintf(2, NAME);
	ft_dprintf(2, "error: ");
	va_start(va, fmt);
	ft_vdprintf(2, fmt, va);
	va_end(va);
	if (help != NULL)
		help();
	exit(1);
}

void		*secure_malloc(size_t size)
{
	void	*ptr;

	ptr = (void*)malloc(sizeof(*ptr) * size);
	if (ptr == NULL)
		error(NULL, "malloc failed\n");
	return (ptr);
}

void		*secure_calloc(size_t size)
{
	void	*ptr;

	ptr = (void*)ft_calloc(sizeof(*ptr) * size);
	if (ptr == NULL)
		error(NULL, "malloc failed\n");
	return (ptr);
}
