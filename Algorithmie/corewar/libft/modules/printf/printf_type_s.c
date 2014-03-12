/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_type_s.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 18:42:23 by nmokrane          #+#    #+#             */
/*   Updated: 2014/01/15 18:42:24 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static char		*fill_str(char *str, t_ptf_flags *f)
{
	char		*fill;
	int			strlen;

	strlen = ft_strlen(str);
	if (f->length)
	{
		fill = ft_strnew(ft_abs(f->length));
		if (strlen < ft_abs(f->length))
			ft_memset(fill, ' ', ft_abs(f->length) - strlen);
		if (f->length < 0)
			str = ft_strjoin(str, fill);
		else
			str = ft_strjoin(fill, str);
	}
	return (str);
}

char			*ptf_type_c(t_ptf_flags f, va_list ap)
{
	char		*res;

	(void)f;
	res = ft_strnew(1);
	res[0] = (char)va_arg(ap, int);
	res = fill_str(res, &f);
	return (res);
}

char			*ptf_type_s(t_ptf_flags f, va_list ap)
{
	char		*res;

	(void)f;
	res = va_arg(ap, char *);
	if (res == NULL)
		return ("(null)");
	res = fill_str(res, &f);
	return (res);
}

char			*ptf_type_perc(t_ptf_flags f, va_list ap)
{
	(void)f;
	(void)ap;
	return ("%");
}
