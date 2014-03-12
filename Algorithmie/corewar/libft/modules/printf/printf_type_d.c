/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_type_d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 18:42:13 by nmokrane          #+#    #+#             */
/*   Updated: 2014/01/15 18:42:14 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char		*ptf_type_D(t_ptf_flags f, va_list ap)
{
	char	*res;

	res = ft_ltoa(va_arg(ap, long));
	ptf_fmt_int(&f, &res);
	return (res);
}

char		*ptf_type_d(t_ptf_flags f, va_list ap)
{
	char	*res;

	if (TAG(f, 'l'))
		return (ptf_type_D(f, ap));
	res = ft_itoa((int)va_arg(ap, int));
	ptf_fmt_int(&f, &res);
	return (res);
}

char		*ptf_type_U(t_ptf_flags f, va_list ap)
{
	char	*res;

	(void)f;
	res = ft_ultoa(va_arg(ap, unsigned long));
	ptf_fmt_int(&f, &res);
	return (res);
}

char		*ptf_type_u(t_ptf_flags f, va_list ap)
{
	char	*res;

	if (TAG(f, 'l'))
		return (ptf_type_U(f, ap));
	res = ft_uitoa(va_arg(ap, unsigned int));
	ptf_fmt_int(&f, &res);
	return (res);
}
