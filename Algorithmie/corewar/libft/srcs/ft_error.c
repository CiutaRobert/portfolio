/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 19:09:33 by nmokrane          #+#    #+#             */
/*   Updated: 2014/01/15 19:10:39 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"

void	ft_error(const char *prog_name, const char *fmt, ...)
{
	va_list		ap;

	ft_dprintf(2, "%s: ", prog_name);
	va_start(ap, fmt);
	ft_vdprintf(2, fmt, ap);
	va_end(ap);
}
